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
```

## Build

    $ make

## Run

    $ ./jv_log_main

## Out Print

```
2018-03-16 22:20:52 debug    Hello, World
2018-03-16 22:20:52 debug    fdsafdsafsafa
2018-03-16 22:20:52 debug    fdsafdsfsaf
2018-03-16 22:20:52 notice   Hello, Notice
2018-03-16 22:20:52 warn     Hello, Warning
2018-03-16 22:20:52 emerg    Hello, China
```

## License

This project is under MIT License. See the [LICENSE](LICENSE) file for the full license text.

