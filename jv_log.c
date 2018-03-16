#include <jv_log.h>

static const char *err_levels[] = {"emerg", "alert", "crit", "err", "warning", "notice", "info", "debug"};

typedef struct tm jv_tm_t;

static inline jv_tm_t *jv_localtime(jv_tm_t *tm);

static inline void jv_log_core(jv_log_t *log, jv_uint_t level, const char *fmt, va_list args);

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

static inline void jv_log_core(jv_log_t *log, jv_uint_t level, const char *fmt, va_list args) {
  char datetime[20];

  struct tm ptm;

  /* localtime and  gmtime are similar */
  /*
    localtime_s(&timeinfo, &t);
    localtime_r(&t, &timeinfo);
  */
  strftime(datetime, sizeof(datetime), "%Y-%m-%d %X", jv_localtime(&ptm));

  fprintf(log->fd, "%s %-6s ", datetime, err_levels[level]);
  vfprintf(log->fd, fmt, args);
  /*fprintf(log->fd, "\n");*/
  fflush(log->fd);
}

jv_log_t *jv_log_create(u_char *filename, jv_uint_t level) {
  jv_log_t *log = malloc(sizeof(jv_log_t));

  if (log == NULL) {
    return (jv_log_t *) NULL;
  }

  log->fd = filename == NULL ? stdout : fopen((char *) filename, "a+");
  log->level = level;

  return log;
}

void jv_log_debug(jv_log_t *log, jv_uint_t level, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  jv_log_core(log, level, fmt, args);
  va_end(args);

  if (level == JV_LOG_EMERG) {
    fflush(log->fd);
    jv_log_destroy(log);
    exit(-1);
  }
}

void jv_log_destroy(jv_log_t *log) {
  if (log != (jv_log_t *) NULL) {
    fclose(log->fd);
    free(log);
  }
}
