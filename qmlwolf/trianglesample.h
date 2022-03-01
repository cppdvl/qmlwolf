#ifndef TRIANGLESAMPLE_H
#define TRIANGLESAMPLE_H

#include "scene.h"
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>

namespace QMLWOLF
{

    struct CameraExample {

        QMatrix4x4 cameraProjection {}; //Identity Matrix
        QMatrix4x4 cameraView {}; //Identity Matrix
        int mProjectionId{-1};
        int mViewId{-1};


    };

    class TriangleFBO : public QMLWOLF::OGLFBO
    {
        QMatrix4x4 mTriangleTransform;
        int mModelId{-1};
        QMLWOLF::CameraExample mCamera;


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
