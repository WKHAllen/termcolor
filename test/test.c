#include <stdio.h>
#include <assert.h>
#include "../src/termcolor.h"

int main(void) {
  coloredText("Hello, RED!\n", Black, Red);
  coloredText("Hello, GREEN!\n", Black, Green);
  coloredText("Hello, BLUE!\n", Black, Blue);
  resetTermColor();

  printf("Testing complete\n");
  return 0;
}
