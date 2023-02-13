#ifndef MA_LOG_H
#define MA_LOG_H

#include <stdio.h>
#include <time.h>

#define LOG_TIME (1 << 0)
#define LOG_FILE (1 << 1)
#define LOG_FUNC (1 << 2)
#define LOG_LINE (1 << 3)

#define LOG_ALL (LOG_TIME | LOG_FILE | LOG_FUNC | LOG_LINE)

#define LOG_ERROR LOG_ALL

#define LOG_DEBUG LOG_TIME

#define LOG_INFO LOG_TIME

#define LOG(level, format, ...)                              \
    do                                                       \
    {                                                        \
        time_t t = time(NULL);                               \
        struct tm *tm = localtime(&t);                       \
        char buf[64];                                        \
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", tm); \
        if (level & LOG_TIME)                                \
        {                                                    \
            printf("[%s] ", buf);                            \
        }                                                    \
        if (level & LOG_FILE)                                \
        {                                                    \
            printf("%s:", __FILE__);                         \
        }                                                    \
        if (level & LOG_FUNC)                                \
        {                                                    \
            printf("%s():", __func__);                       \
        }                                                    \
        if (level & LOG_LINE)                                \
        {                                                    \
            printf("%d:", __LINE__);                         \
        }                                                    \
        printf(format "\n", ##__VA_ARGS__);                  \
    } while (0)

#endif // MA_LOG_H
