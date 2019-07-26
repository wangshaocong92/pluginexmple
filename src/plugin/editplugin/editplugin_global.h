#pragma once
#include <QtCore/qglobal.h>

#if defined(LIBEDITPLUGIN_BUILD)
#define EDITPLUGIN_EXPORT Q_DECL_EXPORT
#else
#define EDITPLUGIN_EXPORT Q_DECL_IMPORT
#endif

namespace plugin {
namespace edit {
}
}
