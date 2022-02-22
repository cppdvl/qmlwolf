#ifndef SCENE_H
#define SCENE_H

#include <QQuickFramebufferObject>
#include "oglcanvas.h"


namespace QMLWOLF {
    class Scene : public QQuickFramebufferObject
    {
        Q_OBJECT
        mutable QMLWOLF::FBO* _PScene{nullptr};
        QQuickWindow* pQQWindow{nullptr};

        QSize m_size {320, 200};
        mutable QColor m_rectangleColor{QColor::fromRgbF(0.0f, 0.0f, 0.0f, 1.0f)};


    public:
        Scene();
        QQuickFramebufferObject::Renderer* createRenderer() const override;

    signals:
        //Let know our Scene is Ready
        void sceneLoaded();

    public slots:
        virtual void initializationFinished();


    };

}


#endif // SCENE_H
