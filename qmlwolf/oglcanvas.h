#ifndef OGLCANVAS_H
#define OGLCANVAS_H

#include <QQuickWindow>
#include <QOpenGLFunctions>
#include <QQuickFramebufferObject>
#include <QOpenGLFramebufferObject>



//Extended QML Item functionality: A QML FrameBuffer Object
namespace QMLWOLF {

    class FBO : public QQuickFramebufferObject::Renderer, public QOpenGLFunctions
    {

        //The renderer has a size.
        QSize m_size;

    public:
        FBO();
        QOpenGLFramebufferObject *createFramebufferObject(const QSize& rSize) override;

    };

    class OGLFBO : public FBO
    {
    protected:
        QColor& _backgroundColor;
        QQuickWindow* _pQQW{nullptr};
        QScreen* _pSCRN{nullptr};
    public:
        OGLFBO(QColor& color, QQuickWindow* pWindow = nullptr) : FBO(),
            _backgroundColor(color),
            _pQQW(pWindow),
            _pSCRN(pWindow->screen())
        {
        }
        void render() override;

    };

}

#endif // OGLCANVAS_H
