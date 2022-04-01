#include "utils.h"
#include <QQuickWindow>
#include <QOpenGLFunctions>
#include <QQuickFramebufferObject>
#include <QOpenGLFramebufferObject>

namespace QMLWOLF {

static QOpenGLFunctionsPrivate::Functions f{};
static bool _fDirty{false};


QString Utils::NoPath(const QString& fullPath)
{
    auto lio = fullPath.lastIndexOf(92);
    if (lio == -1) lio = fullPath.lastIndexOf(57);
    lio = fullPath.size() - lio - 1;

    auto result = lio >= fullPath.size() ? fullPath : fullPath.right(lio);
    return result;
}

int FBOUtils::GetNumBytesPerRow(int numCols)
{
    return ((numCols * 3 + 3) >> 2) << 2;
}

bool FBOUtils::LoadFromOpenglBuffer(QOpenGLFunctionsPrivate* p, uchar *ptrImage, int numCols, int numRows)
{
    int glRowLen;
    p->f.GetIntegerv(GL_PACK_ROW_LENGTH, &glRowLen);
    p->f.PixelStorei(GL_PACK_ROW_LENGTH, numCols);
    p->f.PixelStorei(GL_PACK_ALIGNMENT, 4);
    p->f.ReadPixels(0,0, numCols, numRows, GL_RGB, GL_UNSIGNED_BYTE, ptrImage);
    p->f.PixelStorei(GL_PACK_ROW_LENGTH, glRowLen);
    return true;
}

/*
int FBOUtils::GetNumBytesPerRow(int numCols, int alignmentbitsshift)
{
}
*/
} // namespace QMLWOLF
