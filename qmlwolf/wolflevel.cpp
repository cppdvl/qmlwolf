#include "wolflevel.h"

namespace QMLWOLF {

template <typename T>
class IShader {

};

class RenderManager
{
    //********* THIS MUST BE USED BY THE OpenGl FrameBuffer Object *********************

    //The render manager is a tree of the rendereable things.
    //This rendereable things are:
    //Shaders, VBOs, Lights, Cameras and Viewports.
    //They are lazy loaded (instanced when needed).




};

struct LEVEL
{

    //********** This MUST BE USED BY THE CONSUMER INTERFACE WolfLevel ****************
    enum struct LEVELITEM{
        BLOCK = 1,
        BUTTON = 2,
        SECRET = 3,
        DOOR = 4,
        NOTHING = 5
    };


};


QMLWOLF::WolfLevel::WolfLevel()
{

}

QQuickFramebufferObject::Renderer* WolfLevel::createRenderer() const
{
    pFBO = new WolfLevelFBO(m_backgroundColor);
    qInfo() << "WolfLevel (QMLWOLF::Scene) Frame Buffer Object Created (pFBO) @:" << Qt::hex << pFBO;
    emit renderingBackendInitialized();
    return pFBO;

}


void WolfLevel::setCameraFOV(float fov)
{

}

WolfLevelFBO::WolfLevelFBO(QColor &color) : QMLWOLF::OGLFBO(color)
{
    qInfo() << __FILE__ << ":" << __LINE__ << "WolfLevelFBO";

}

} // namespace QMLWolf
