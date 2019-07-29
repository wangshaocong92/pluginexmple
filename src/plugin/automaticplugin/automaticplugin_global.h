#pragma once

#include <QtCore/qglobal.h>

#if defined(LIBAUTOMATIC_BUILD)
#define AUTOMATICPLUGIN_EXPORT Q_DECL_EXPORT
#else
#define AUTOMATICPLUGIN_EXPORT Q_DECL_IMPORT
#endif

namespace plugin {
namespace automatic {
}
}
