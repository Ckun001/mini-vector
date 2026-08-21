#include "log.h"
#include <cstdarg>
#include <cstdio>
#include <ctime>

static LogLevel g_log_level = LOG_INFO;

void set_log_level(LogLevel level) { g_log_level = level; }

void log_message(LogLevel level, const char* file, int line, const char* fmt, ...) {
    if (level < g_log_level) return;
    const char* level_str = (level == LOG_INFO) ? "INFO" : "ERROR";
    time_t now = time(nullptr);
    struct tm* tm_info = localtime(&now);
    char time_buf[20];
    strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", tm_info);
    va_list args;
    va_start(args, fmt);
    char msg_buf[1024];
    vsnprintf(msg_buf, sizeof(msg_buf), fmt, args);
    va_end(args);
    fprintf(stdout, "[%s] [%s] %s:%d - %s\n", time_buf, level_str, file, line, msg_buf);
    fflush(stdout);
}
