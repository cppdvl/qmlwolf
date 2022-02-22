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

//*************************** THE GAME SCENE ***********************************/
void QMLWOLF::OGLFBO::render()
{
    //Ok here we draw frame after frame.... after frame.... after frame.... after frame....
    //We will draw ONLY a ONE COLOR background screen.
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(_backgroundColor.redF(), _backgroundColor.greenF(), _backgroundColor.blueF(), _backgroundColor.alphaF());
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glFlush();
    update();
}

