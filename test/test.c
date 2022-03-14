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
  printf("No color formatting\n");
  termcolor_push(TermColorLightMagenta, TermColorCyan);
  printf("Light magenta background, cyan text\n");
  termcolor_push_text(TermColorBlack);
  printf("Light magenta background, black text\n");
  termcolor_push_background(TermColorWhite);
  printf("White background, black text\n");
  termcolor_pop();
  printf("Light magenta background, black text (again)\n");
  termcolor_pop();
  printf("Light magenta background, cyan text (again)\n");
  termcolor_pop();
  printf("No color formatting (again)\n");

  printf("Testing complete\n");
  return 0;
}
