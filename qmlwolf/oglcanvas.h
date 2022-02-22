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
    public:
        OGLFBO(QColor& color) : FBO(),
            _backgroundColor(color)
        {
        }
        void render() override;

    };

}

#endif // OGLCANVAS_H
