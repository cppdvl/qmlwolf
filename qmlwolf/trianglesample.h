#ifndef TRIANGLESAMPLE_H
#define TRIANGLESAMPLE_H

#include "scene.h"
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>

namespace QMLWOLF
{
    class TriangleFBO : public QMLWOLF::OGLFBO
    {
    public:
        TriangleFBO(QColor&);
        QOpenGLShaderProgram* pProgram{nullptr};
        QOpenGLVertexArrayObject mVAO;

        void render() override;
    };

    class TriangleExample : public QMLWOLF::Scene
    {
        Q_OBJECT
    public:
        TriangleExample();
        QQuickFramebufferObject::Renderer* createRenderer() const override;
    public slots:

    };
}

#endif // TRIANGLESAMPLE_H
