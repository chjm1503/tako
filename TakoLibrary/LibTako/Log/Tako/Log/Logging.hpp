/**
 * @file Logging.hpp
 * @brief
 * @version 0.1
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef TAKO_LOG_LOG_HPP_
#define TAKO_LOG_LOG_HPP_

#include <cinttypes>

#include "Tako/Log/Export.h"

namespace tako {
namespace log {

enum class TakoLogEnum: uint8_t {
    Error   = 0x1,
    Warning = 0x2,
    Debug   = 0x4,
    NoLog   = 0x0,
    Warn    = Warning
};

TAKO_LOG_EXPORT void InitTakoLogging(const char* sz);

} // namespace log
} // namespace tako

#endif // TAKO_LOG_LOG_HPP_