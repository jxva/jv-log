#include <jv_log.h>

static const char *prioritys[] = {"emerg", "alert", "crit", "error", "warning", "notice", "info", "debug"};

typedef struct tm jv_tm_t;

static inline jv_tm_t *jv_localtime(jv_tm_t *tm);

static inline void jv_log_core(jv_log_t *log, jv_uint_t priority, const char *fmt, va_list *args);

static jv_tm_t *jv_localtime(jv_tm_t *tm) {
  time_t now;
#if defined(__MINGW32__) || defined(__MINGW64__) || defined(_WIN32) || defined(_WIN64)
  jv_tm_t *t;

  now = time(NULL);
  t = localtime(&now);
  *tm = *t;
#else
  now = time(NULL);
  localtime_r(&now, tm);
#endif
  return tm;
}

static inline void jv_log_core(jv_log_t *log, jv_uint_t priority, const char *fmt, va_list *args) {
  char datetime[20];
  struct tm ptm;

  strftime(datetime, sizeof(datetime), "%Y-%m-%d %X", jv_localtime(&ptm));

  fprintf(log->fd, "%s %-8s ", datetime, prioritys[priority]);
  vfprintf(log->fd, fmt, *args);
  fprintf(log->fd, "\n");

  log->line_count++;

  if (log->line_count % log->cache_line == 0) {
    fflush(log->fd);
  }
}

jv_log_t *jv_log_create(u_char *filename, jv_uint_t priority, jv_uint_t cache_line) {
  jv_log_t *log = malloc(sizeof(jv_log_t));

  if (log == NULL) {
    return (jv_log_t *) NULL;
  }

  printf("%lu\n", sizeof(jv_log_t));

  log->fd = filename == NULL ? stdout : fopen((char *) filename, "a+");
  log->priority = priority;

  return log;
}

void jv_log(jv_log_t *log, jv_uint_t priority, const char *fmt, ...) {
  va_list args;

  if (log->priority < priority) {
    return;
  }

  va_start(args, fmt);
  jv_log_core(log, priority, fmt, &args);
  va_end(args);

  if (priority == JV_LOG_EMERG) {
    jv_log_destroy(log);
    exit(-1);
  }
}

void jv_log_destroy(jv_log_t *log) {
  if (log != (jv_log_t *) NULL) {
    fflush(log->fd);
    fclose(log->fd);
    free(log);
  }
}
