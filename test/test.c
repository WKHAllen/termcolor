#include <stdio.h>
#include <assert.h>
#include "../src/termcolor.h"

int main(void) {
  termcolor_push_text(TermColorRed);
  printf("Hello, RED!\n");
  termcolor_push_text(TermColorGreen);
  printf("Hello, GREEN!\n");
  termcolor_push_text(TermColorBlue);
  printf("Hello, BLUE!\n");
  termcolor_clear();

  printf("Testing complete\n");
  return 0;
}
