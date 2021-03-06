#ifndef COREPLUGIN_GLOBAL_H
#define COREPLUGIN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBCORE_BUILD)
#define COREPLUGIN_EXPORT Q_DECL_EXPORT
#else
#define COREPLUGIN_EXPORT Q_DECL_IMPORT
#endif

namespace plugin {
namespace core {
}
}
#endif // COREPLUGIN_GLOBAL_H
