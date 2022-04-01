#ifndef QMLWOLF_CAM_H
#define QMLWOLF_CAM_H

#include <QMatrix4x4>

namespace QMLWOLF {


class Cam : public QMatrix4x4
{
    bool _isDirty{true};

public:
    Cam();

};

} // namespace QMLWOLF

#endif // QMLWOLF_CAM_H
