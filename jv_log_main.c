#include <jv_log.h>

int main(int argc, char *argv[]) {
  jv_log_t *log = jv_log_create(NULL, JV_LOG_DEBUG, 0);

  jv_log_debug(log, "Hello, World");

  jv_log_debug(log, "fdsafdsafsafa");

  jv_log_debug(log, "fdsa%s", "fdsfsaf");

  jv_log_notice(log, "Hello, Notice");

  jv_log_warn(log, "Hello, Warning");

  jv_log_emerg(log, "Hello, %s", "China");

  jv_log_info(log, "Hello, %s", "China");

  jv_log_destroy(log);
  
  return 0;
}
