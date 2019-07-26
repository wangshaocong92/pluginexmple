#pragma once

#include <QtCore/qglobal.h>

#if defined(LIBINTERFACE_BUILD)
#define INTERFACE_EXPORT Q_DECL_EXPORT
#else
#define INTERFACE_EXPORT Q_DECL_IMPORT
#endif
