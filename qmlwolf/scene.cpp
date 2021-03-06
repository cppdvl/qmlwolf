#include "scene.h"

// !!!!!!!!! QQUICKITEM !!!!!!!!!
QMLWOLF::Scene::Scene()
{

    qInfo() << "Scene Item CTOR";
    setMirrorVertically(true);
    connect(this, &QQuickItem::windowChanged, [this](){
        this->pQQWindow = this->window();
        qInfo() << __FILE__ << ":" << __LINE__ << " QQuickWindow:" << Qt::hex << (void*)this->pQQWindow;

    });

}

QQuickFramebufferObject::Renderer* QMLWOLF::Scene::createRenderer() const
{
    pFBO = new OGLFBO(m_backgroundColor);
    qInfo() << "Scene Item FrameBuffer Object (pFBO) address:" << Qt::hex << pFBO;
    emit renderingBackendInitialized();
    return pFBO;
}


void QMLWOLF::Scene::setBackgroundColor(QColor color)
{
    m_backgroundColor = color;
}
