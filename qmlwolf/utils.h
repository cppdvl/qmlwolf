#ifndef QMLWOLF_UTILS_H
#define QMLWOLF_UTILS_H

#include <QString>
#include <QOpenGLFunctions>
namespace QMLWOLF {

class Utils
{
public:
    static QString NoPath(const QString&);
};

} // namespace QMLWOLF



namespace QMLWOLF::FBOUtils{

    int GetNumBytesPerRow(int numCols);
    bool LoadFromOpenglBuffer(QOpenGLFunctionsPrivate* pFunc, uchar* ptrImage, int numCols, int numRows);

}

#endif // QMLWOLF_UTILS_H
