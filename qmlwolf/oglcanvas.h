#ifndef OGLCANVAS_H
#define OGLCANVAS_H

#include <mutex>

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

        std::once_flag __getViewPortDataFlag;
        int __viewPortData[4];
        int* __pViewPortData{__viewPortData};
        int __captureDataBufferSize {0};

    protected:

        int* _pNumCols = &__viewPortData[2];
        int* _pNumRows = &__viewPortData[3];
        u_char* _pCaptureData {nullptr};
        QSharedPointer<u_char> _spCaptureData {nullptr};

        QColor& _backgroundColor;
        QQuickWindow* _pQQW{nullptr};
        QScreen* _pSCRN{nullptr};

        void _renderStart();
        void _renderEnd();

        /*!
         * \brief _enableCapture Enables the Capture of your framebuffer into a texture.
         */
        void _enableCapture();
        void _capture();
        void _disableCapture();
        bool _createACaptureTexture{false};



    public:
        OGLFBO(QColor& color, QQuickWindow* pWindow = nullptr) : FBO(),
            _backgroundColor(color),
            _pQQW(pWindow),
            _pSCRN(pWindow->screen())
        {
        }
        void render() override;
        void capture();


    };

}

#endif // OGLCANVAS_H
