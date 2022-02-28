#ifndef SCENE_H
#define SCENE_H

#include <QQuickFramebufferObject>
#include "oglcanvas.h"


namespace QMLWOLF {
    class Scene : public QQuickFramebufferObject
    {
        Q_OBJECT
    protected:
        mutable QMLWOLF::FBO* pFBO{nullptr};
        QQuickWindow* pQQWindow{nullptr};

        QSize m_size {320, 200};
        mutable QColor m_backgroundColor{QColor::fromRgbF(0.33f, 0.0f, 0.18f, 1.0f)};


    public:
        Scene();
        QQuickFramebufferObject::Renderer* createRenderer() const override;

    signals:
        //Let know our Scene is Ready
        void renderingBackendInitialized() const;

    public slots:
        void setBackgroundColor(QColor color);

    };

}


#endif // SCENE_H
