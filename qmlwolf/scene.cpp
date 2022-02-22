#include "scene.h"

// !!!!!!!!! QQUICKITEM !!!!!!!!!
QMLWOLF::Scene::Scene()
{

    qInfo() << "OGLCanvas";
    setMirrorVertically(true);
    connect(this, &QQuickItem::windowChanged, [this](){

        qInfo() << "Connecting the before rendering signal to the scene loaded slot.";
        this->pQQWindow = this->window();
        if (this -> pQQWindow) connect(this->pQQWindow, &QQuickWindow::beforeRendering, this, &QMLWOLF::Scene::sceneLoaded);
    });

}

QQuickFramebufferObject::Renderer* QMLWOLF::Scene::createRenderer() const
{
    _PScene = new OGLFBO(m_rectangleColor);
    return _PScene;
}


void QMLWOLF::Scene::initializationFinished()
{
    //Prevent any call in any case the scene is not ready
    if (!_PScene) return;
    if (pQQWindow)
    {
        qInfo() << "Disconnecting";
        disconnect(this->pQQWindow, &QQuickWindow::beforeRendering, this, &QMLWOLF::Scene::sceneLoaded);
    }
}
