#ifndef TRIANGLESAMPLE_H
#define TRIANGLESAMPLE_H

#include "scene.h"
#include <QScreen>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>

namespace QMLWOLF
{

    struct CameraExample {

        bool bDirty {true};
        QMatrix4x4 cameraProjection {}; //Identity Matrix
        QMatrix4x4 cameraView {}; //Identity Matrix
        int mProjectionId{-1};
        int mViewId{-1};

        float mFov{60.0f};
        const float mNear{.1};
        const float mFar{100.0f};
        const float mAspectRatio{1.6f};


    };

    class TriangleFBO : public QMLWOLF::OGLFBO
    {
        QMatrix4x4 mTriangleTransform{};
        int mModelId{-1};
        QMLWOLF::CameraExample mCamera;

        int mFrame{0};

    public:
        TriangleFBO(QColor&, QQuickWindow*);
        QOpenGLShaderProgram* pProgram{nullptr};
        QOpenGLVertexArrayObject mVAO;

        void render() override;

        void SetCameraFOV(float fov)
        {
            mCamera.mFov = fov;
            mCamera.bDirty = true;
        }
    };

    class TriangleExample : public QMLWOLF::Scene
    {
        Q_OBJECT
    public:
        TriangleExample();
        QQuickFramebufferObject::Renderer* createRenderer() const override;
    public slots:
        void setCameraFOV(float fov);
    };
}

#endif // TRIANGLESAMPLE_H
