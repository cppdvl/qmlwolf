#ifndef QMLWOLF_WOLFLEVEL_H
#define QMLWOLF_WOLFLEVEL_H

#include "scene.h"

#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>


namespace QMLWOLF {


    class WolfLevelFBO : public QMLWOLF::OGLFBO
    {
    public:
        WolfLevelFBO(QColor &color);

    };

    class WolfLevel : public QMLWOLF::Scene
    {
        Q_OBJECT

    public:
        WolfLevel();
        QQuickFramebufferObject::Renderer* createRenderer() const override;
    public slots:
        void setCameraFOV(float fov);
    };

} // namespace QMLWolf

#endif // QMLWOLF_WOLFLEVEL_H
