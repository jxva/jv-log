#ifndef _JV_LOG_H_INCLUDE_
#define _JV_LOG_H_INCLUDE_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define JV_OK 0
#define JV_ERROR -1

#define jv_memzero(buf, n) (void *) memset(buf, 0, n)

#ifndef intptr_t
#define intptr_t long
#define uintptr_t unsigned long
#endif

typedef intptr_t jv_int_t;
typedef uintptr_t jv_uint_t;

typedef unsigned char u_char;

#define JV_LOG_EMERG 0 /* process exit(1) */
#define JV_LOG_ALERT 1
#define JV_LOG_CRIT 2
#define JV_LOG_ERR 3
#define JV_LOG_WARNING 4
#define JV_LOG_NOTICE 5
#define JV_LOG_INFO 6
#define JV_LOG_DEBUG 7

typedef struct jv_log_s jv_log_t;

struct jv_log_s {
  jv_uint_t level;
  FILE *fd;
};

jv_log_t *jv_log_create(u_char *filename, jv_uint_t level);

void jv_log_debug(jv_log_t *log, jv_uint_t level, const char *fmt, ...);

void jv_log_destroy(jv_log_t *log);

#endif /* _JV_LOG_H_INCLUDE_ */
