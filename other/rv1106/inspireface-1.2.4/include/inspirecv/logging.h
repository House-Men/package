
#ifndef INSPIRECV_LOGGING_H_
#define INSPIRECV_LOGGING_H_

#include <sstream>

#ifndef INSPIRECV_API
#define INSPIRECV_API
#endif

// Windows headers define ERROR as a macro. Preserve it for the host while
// declaring the historical enum aliases below.
#if defined(_WIN32) && defined(ERROR)
#pragma push_macro("ERROR")
#undef ERROR
#define INSPIRECV_RESTORE_WINDOWS_ERROR_MACRO
#endif

#if defined(_WIN32)
// Expand caller aliases before selecting a macro-safe enum name. Windows
// defines ERROR as 0, including when LOG_IF forwards it to INSPIRECV_LOG.
#define INSPIRECV_LOG_SEVERITY_INFO kInfo
#define INSPIRECV_LOG_SEVERITY_WARN kWarn
#define INSPIRECV_LOG_SEVERITY_ERROR kError
#define INSPIRECV_LOG_SEVERITY_FATAL kFatal
#define INSPIRECV_LOG_SEVERITY_0 kError
#define INSPIRECV_LOG_SEVERITY_IMPL(severity) INSPIRECV_LOG_SEVERITY_##severity
#define INSPIRECV_LOG_SEVERITY(severity) INSPIRECV_LOG_SEVERITY_IMPL(severity)
#endif

/**
 * @brief Macro to create a logging stream.
 */
#if defined(_WIN32)
#define INSPIRECV_LOG(severity)                                                     \
    inspirecv::logging::ISFLogging(__FILE__, __LINE__,                              \
        inspirecv::logging::ISFLogging::LogSeverity::INSPIRECV_LOG_SEVERITY(severity)) \
      .Stream()
#else
#define INSPIRECV_LOG(severity)                                                     \
    inspirecv::logging::ISFLogging(__FILE__, __LINE__,                              \
        inspirecv::logging::ISFLogging::LogSeverity::severity)                     \
      .Stream()
#endif

/**
 * @brief Macro to check if verbose logging is enabled for a given level.
 */
#define INSPIRECV_VLOG_IS_ON(verboselevel) \
    ((verboselevel) <= inspirecv::logging::ISFLogging::VLogLevel())

/**
 * @brief Macro to set the verbose logging level.
 */
#define INSPIRECV_VLOG_SET_LEVEL(verboselevel) \
    inspirecv::logging::ISFLogging::VLogSetLevel(verboselevel)

/**
 * @brief Macro to log a message if verbose logging is enabled for a given level.
 */
#define INSPIRE_VLOG(verboselevel) LOG_IF(INFO, INSPIRECV_VLOG_IS_ON(verboselevel))

namespace inspirecv {
namespace logging {
/**
 * @brief A wrapper that logs to stderr.
 */
class INSPIRECV_API ISFLogging {
public:
    enum class LogSeverity : int {
        kInfo = 0,
        kWarn = 1,
        kError = 2,
        kFatal = 3,
        INFO = kInfo,
        WARN = kWarn,
        ERROR = kError,
        FATAL = kFatal,
    };
    ISFLogging(const char *filename, int line, LogSeverity severity)
    : severity_(severity), filename_(filename), line_(line) {}
    std::stringstream &Stream() {
        return stream_;
    }
    ~ISFLogging();

    static int VLogLevel();
    static void VLogSetLevel(int level);

private:
    std::stringstream stream_;
    LogSeverity severity_;
    const char *filename_;
    int line_;
    static int vlog_level_;
};

}  // namespace logging

}  // namespace inspirecv

#if defined(INSPIRECV_RESTORE_WINDOWS_ERROR_MACRO)
#pragma pop_macro("ERROR")
#undef INSPIRECV_RESTORE_WINDOWS_ERROR_MACRO
#endif

#endif  // INSPIRECV_LOGGING_H_
