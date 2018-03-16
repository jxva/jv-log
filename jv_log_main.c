#include <jv_log.h>

void test(void) {
  jv_log_t *log = jv_log_create(NULL, JV_LOG_DEBUG);

  jv_log_debug(log, JV_LOG_NOTICE, "Hello, World\n");

  jv_log_debug(log, JV_LOG_EMERG, "Hello, %s\n", "China");

  jv_log_debug(log, JV_LOG_INFO, "Hello, %s\n", "China");

  jv_log_destroy(log);
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
