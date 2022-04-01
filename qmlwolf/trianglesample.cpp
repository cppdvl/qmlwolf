#include "trianglesample.h"
#include <array>
#include <QWindow>

#include "utils.h"

std::array<float, 18> triangleData {
     0.50f,  0.00f, 0.0f, 1.0f, 0.0f, 0.0f,
     0.00f,  0.50f, 0.0f, 0.0f, 1.0f, 0.0f,
     -0.50f, 0.00f, 0.0f, 0.0f, 0.0f, 1.0f
};



QMLWOLF::TriangleFBO::TriangleFBO(QColor& color, QQuickWindow* pWindow) : OGLFBO(color, pWindow)
{
    //SHADER
    qInfo() << __FILE__ << ":" << __LINE__ << "TriangleFBO";
    pProgram = new QOpenGLShaderProgram();
    auto attach = [this](auto type, QString filename) -> bool
    {
        qInfo() << (type == QOpenGLShader::Vertex ? "Vertex Shader" : "Fragment Shader");

        return pProgram->addShaderFromSourceFile(type,filename);
    };
    auto link = [this]() -> bool
    {
        qInfo() << "Link";
        return pProgram->link();
    };
    if (!attach(QOpenGLShader::Vertex, ":/trianglefbo.vert"))  qInfo() << pProgram->log(); else qInfo() << "OK";
    if (!attach(QOpenGLShader::Fragment, ":/trianglefbo.frag"))qInfo() << pProgram->log(); else qInfo() << "OK";
    if (!link()) qInfo() << pProgram->log(); else qInfo() << "OK";

    //Attach Camera (Model & View) and Triangle (Model) to shader.
    mCamera.mProjectionId = pProgram->uniformLocation("projection");
    mCamera.mViewId = pProgram->uniformLocation("view");
    mModelId = pProgram->uniformLocation("model");


    //Calculate projectionMatrix
    mCamera.bDirty = true;

    //VERTEX BUFFER OBJECT & VAO
    QOpenGLBuffer mVBO;
    mVBO.create();
    mVBO.bind();
    mVAO.create();
    mVAO.bind();

    //Data attribution: what data, and what for.
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangleData), triangleData.data(), GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //unbind
    mVAO.release();
    mVBO.release();
    pProgram->release();

    //Enable the Capture of screenshots
    _enableCapture();

}
void QMLWOLF::TriangleFBO::render()
{


    //Ok here we draw frame after frame.... after frame.... after frame.... after frame....
    //We will draw ONLY a ONE COLOR background screen.
    _renderStart();

    //Update the Camera.
    if (mCamera.bDirty)
    {
        mCamera.cameraProjection = QMatrix4x4{};
        mCamera.cameraProjection.perspective(mCamera.mFov, mCamera.mAspectRatio, mCamera.mNear, mCamera.mFar);
        mCamera.bDirty = false;
    }

    pProgram->bind();
    {
        //Plug data into shader

        pProgram->setUniformValue(mCamera.mProjectionId, mCamera.cameraProjection);
        pProgram->setUniformValue(mCamera.mViewId, mCamera.cameraView);

        mTriangleTransform.setToIdentity();
        mTriangleTransform.translate(0.0f, 0.0f, -3.0f);
        mTriangleTransform.rotate(100.0 * mFrame / _pSCRN->refreshRate(), 0, 1, 0);
        pProgram->setUniformValue(mModelId, mTriangleTransform);

        mVAO.bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        mVAO.release();
    }
    pProgram->release();
    mFrame++;

    _renderEnd();

}


QMLWOLF::TriangleExample::TriangleExample() : Scene()
{

}

QQuickFramebufferObject::Renderer* QMLWOLF::TriangleExample::createRenderer() const
{
    pFBO = new TriangleFBO(m_backgroundColor, pQQWindow);
    qInfo() << __FILE__ << ":" << __LINE__ << " => Scene Item FrameBuffer address:" << Qt::hex << pFBO;
    emit renderingBackendInitialized();
    return pFBO;
}

void QMLWOLF::TriangleExample::setCameraFOV(float fov)
{
    auto pTriangleFBO = dynamic_cast<TriangleFBO*>(pFBO);
    if (pTriangleFBO) pTriangleFBO->SetCameraFOV(fov);
}

void QMLWOLF::TriangleExample::captureScreenShot()
{
    qInfo() << QMLWOLF::Utils::NoPath(__FILE__) << ":" << __LINE__ << " => Capturing ScreenShot!!!! ";
    auto p = dynamic_cast<QMLWOLF::OGLFBO*>(pFBO);
    if (p)
    {
        p->capture();
        qInfo() << "Will Capture!!!!";
    }
}
