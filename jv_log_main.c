#include <jv_log.h>

void test(void) {
  jv_log_t *log = jv_log_create(NULL, JV_LOG_DEBUG, 0);

  jv_log(log, JV_LOG_DEBUG, "Hello, World");

  jv_log(log, JV_LOG_NOTICE, "Hello, Notice");

  jv_log(log, JV_LOG_WARNING, "Hello, Warning");

  jv_log(log, JV_LOG_EMERG, "Hello, %s", "China");

  jv_log(log, JV_LOG_INFO, "Hello, %s", "China");

  jv_log_destroy(log);
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
