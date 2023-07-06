/**
 * @file Export.h
 * @brief
 *
 */
#pragma once
#ifndef TAKO_LOG_EXPORT_H_
#define TAKO_LOG_EXPORT_H_

#ifdef TAKO_LOG_STATIC_DEFINE
#   define TAKO_LOG_EXPORT
#   define TAKO_LOG_NO_EXPORT
#else
#   ifndef TAKO_LOG_EXPORT
#       ifdef TAKO_LOG_DLL
#           define TAKO_LOG_EXPORT __declspec(dllexport)
#       else
#           define TAKO_LOG_EXPORT __declspec(dllimport)
#       endif // TAKO_LOG_DLL
#   endif // TAKO_LOG_EXPORT

#   ifndef TAKO_LOG_NO_EXPORT
#       define TAKO_LOG_NO_EXPORT
#   endif // TAKO_LOG_NO_EXPORT
#endif // TAKO_LOG_STATIC_DEFINE

#endif // TAKO_LOG_EXPORT_H_