#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(TEST2UI_LIB)
#  define TEST2UI_EXPORT Q_DECL_EXPORT
# else
#  define TEST2UI_EXPORT Q_DECL_IMPORT
# endif
#else
# define TEST2UI_EXPORT
#endif
