# A simple, portable, easy to use log recorder using ANSI C

A simple, portable, easy to use log recorder using ANSI C

## Features

- No dependence
- ~150 LOC
- Very easy to use

## Getting Started

### jv_log_main.c

```c
#include <jv_log.h>

int main(int argc, char *argv[]) {
  jv_log_t *log = jv_log_create(NULL, JV_LOG_DEBUG, 0);

  jv_log_stdout("Hello, Stdout");

  jv_log_stderr("Hello, Stderr");

  jv_log_debug(log, "Hello, Debug");

  jv_log_debug(log, "%s, %s", "Hello", "Debug");

  jv_log_debug(log, "%s%c %s", "Hello", ',', "Debug");

  jv_log_info(log, "Hello, %s", "Info");

  jv_log_notice(log, "Hello, %s", "World");

  jv_log_warn(log, "Hello, Warn");

  jv_log_error(log, "Hello, %s", "Error");

  jv_log_crit(log, "Hello, %s", "Crit");

  jv_log_alert(log, "Hello, %s", "Alert");

  jv_log_emerg(log, "Hello, %s", "Emerg");

  jv_log_info(log, "Hello, %s", "Info");

  jv_log_destroy(log);

  return 0;
}
```

## Build

    $ make

## Run

    $ ./jv_log_main

## Out Print

```
2018-03-18 16:55:30 stdout  Hello, Stdout
2018-03-18 16:00:18 stderr  Hello, Stderr
2018-03-18 16:00:18 debug   Hello, Debug
2018-03-18 16:00:18 debug   Hello, Debug
2018-03-18 16:00:18 debug   Hello, Debug
2018-03-18 16:00:18 info    Hello, Info
2018-03-18 16:00:18 notice  Hello, World
2018-03-18 16:00:18 warn    Hello, Warn
2018-03-18 16:00:18 error   Hello, Error
2018-03-18 16:00:18 crit    Hello, Crit
2018-03-18 16:00:18 alert   Hello, Alert
2018-03-18 16:00:18 emerg   Hello, Emerg
```

## License

This project is under MIT License. See the [LICENSE](LICENSE) file for the full license text.

