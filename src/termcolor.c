#include <stdio.h>
#include "termcolor.h"

const char *ansi_text_colors[] = {
  ANSI_TEXT_BLACK,
  ANSI_TEXT_RED,
  ANSI_TEXT_GREEN,
  ANSI_TEXT_YELLOW,
  ANSI_TEXT_BLUE,
  ANSI_TEXT_MAGENTA,
  ANSI_TEXT_CYAN,
  ANSI_TEXT_WHITE,
  ANSI_TEXT_BRIGHT_BLACK,
  ANSI_TEXT_BRIGHT_RED,
  ANSI_TEXT_BRIGHT_GREEN,
  ANSI_TEXT_BRIGHT_YELLOW,
  ANSI_TEXT_BRIGHT_BLUE,
  ANSI_TEXT_BRIGHT_MAGENTA,
  ANSI_TEXT_BRIGHT_CYAN,
  ANSI_TEXT_BRIGHT_WHITE
};

const char *ansi_background_colors[] = {
  ANSI_BG_BLACK,
  ANSI_BG_RED,
  ANSI_BG_GREEN,
  ANSI_BG_YELLOW,
  ANSI_BG_BLUE,
  ANSI_BG_MAGENTA,
  ANSI_BG_CYAN,
  ANSI_BG_WHITE,
  ANSI_BG_BRIGHT_BLACK,
  ANSI_BG_BRIGHT_RED,
  ANSI_BG_BRIGHT_GREEN,
  ANSI_BG_BRIGHT_YELLOW,
  ANSI_BG_BRIGHT_BLUE,
  ANSI_BG_BRIGHT_MAGENTA,
  ANSI_BG_BRIGHT_CYAN,
  ANSI_BG_BRIGHT_WHITE
};

void coloredText(char *text, TermColor background_color, TermColor text_color) {
  printf("%s%s%s", ansi_background_colors[background_color], ansi_text_colors[text_color], text);
}

void resetTermColor(void) {
  printf(ANSI_RESET);
}
