#ifndef MINI_VECTOR_LOG_H
#define MINI_VECTOR_LOG_H

#include <cstdio>
#include <ctime>

enum LogLevel { LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR };

void set_log_level(LogLevel level);
void log_message(LogLevel level, const char* file, int line, const char* fmt, ...);

#define LOG_INFO(fmt, ...) \
    log_message(LOG_INFO, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) \
    log_message(LOG_ERROR, __FILE__, __LINE__, fmt, ##__VA_ARGS__)

#endif
