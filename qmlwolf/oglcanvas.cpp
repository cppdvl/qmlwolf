#include <mutex>
#include "utils.h"
#include "oglcanvas.h"
QMLWOLF::FBO::FBO()
{

    qInfo() << "OGLCanvasRenderer";

    //Inicializar el Rendering => OPENGL
    initializeOpenGLFunctions();
    //Now you can start your scene data: vertexes, normals, texture coordinates etc.
    //Tipically you would want to have you renderer to be loaded with Game, Scene data,
    //And yet this should be generic... so using a file, like .OBJ, or .DAE etc.

}


QOpenGLFramebufferObject* QMLWOLF::FBO::createFramebufferObject(const QSize &rSize)
{
    m_size = rSize;
    qInfo() << "Size of frame buffer: " << m_size;
    auto format = QOpenGLFramebufferObjectFormat{};
    format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
    format.setSamples(16);
    auto ret = new QOpenGLFramebufferObject(m_size, format);
    return ret;
}

//*************************** THE GAME SCENE *********************************************/
//*************************** THE GAME SCENE : DRAWING ***********************************/
void QMLWOLF::OGLFBO::_renderStart()
{
    //Ok here we draw frame after frame.... after frame.... after frame.... after frame....
    //We will draw ONLY a ONE COLOR background screen.
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(_backgroundColor.redF(), _backgroundColor.greenF(), _backgroundColor.blueF(), _backgroundColor.alphaF());
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void QMLWOLF::OGLFBO::render()
{

}

void QMLWOLF::OGLFBO::capture()
{
    QMLWOLF::FBOUtils::LoadFromOpenglBuffer(d_ptr, _pCaptureData, *_pNumCols, *_pNumRows);
}
void QMLWOLF::OGLFBO::_renderEnd()
{

    std::call_once(__getViewPortDataFlag,
    [this]()
    {
        glGetIntegerv(GL_VIEWPORT, __pViewPortData);
        qInfo() << "Retina Scale " << _pQQW->devicePixelRatio();
        for (auto index = 0; index < 4; ++index) qInfo() << index << ": " << __pViewPortData[index];
        if (!_createACaptureTexture) return;
        __captureDataBufferSize =  *_pNumRows * QMLWOLF::FBOUtils::GetNumBytesPerRow(*_pNumCols);
        _pCaptureData = new unsigned char[__captureDataBufferSize];
        _spCaptureData = QSharedPointer<unsigned char>{_pCaptureData, [](unsigned char* p) -> void {qInfo() << QMLWOLF::Utils::NoPath(__FILE__) << ": " << __LINE__ << " Killing OFB Capturing Texture...."; delete[] p;}};
        qInfo() << QMLWOLF::Utils::NoPath(__FILE__) << ": " << __LINE__ << " Create OFB Capturing Texture";
    }
    );
    glFlush();
    update();
}

void QMLWOLF::OGLFBO::_enableCapture()
{
    _createACaptureTexture = true;
}

