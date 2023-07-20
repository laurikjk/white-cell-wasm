#include <emscripten.h>

extern "C" {
  EMSCRIPTEN_KEEPALIVE
  const char* sayHello() {
    return "Hello, World!";
  }
}
