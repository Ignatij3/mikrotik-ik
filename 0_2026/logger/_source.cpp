#include "_source.hpp"

namespace logger
{

void Log_::operator()(const char* func, const char* file, int32 line, logger_::log_level_ logl, const char* s)
{
    logger_::OutputFullPrefix_(func, file, line, logl);

    logger_::Outputs_(s, logl);

    if (logl == logger_::log_level_::FATAL) {
        HAL_NVIC_SystemReset();
    }
}

void Logf_::operator()(const char* func, const char* file, int32 line, logger_::log_level_ logl, const char* format, ...)
{
    logger_::OutputFullPrefix_(func, file, line, logl);

    logger_::Outputf_(format, logl);

    if (logl == logger_::log_level_::FATAL) {
        HAL_NVIC_SystemReset();
    }
}

}  // namespace logger