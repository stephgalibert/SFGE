#include "logger.h"
#include "ilogger.h"

#include "spdloglogger.h"

namespace ecge
{
    std::unique_ptr<ILogger> Logger::CreateLogger(const std::string &category)
    {
        return std::make_unique<SpdlogLogger>(category);
    }
}// namespace ecge
