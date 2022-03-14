#include <stdio.h>
#include "termcolor.h"

#define ANSI_TEXT_BLACK          "\x1b[30m"
#define ANSI_TEXT_RED            "\x1b[31m"
#define ANSI_TEXT_GREEN          "\x1b[32m"
#define ANSI_TEXT_YELLOW         "\x1b[33m"
#define ANSI_TEXT_BLUE           "\x1b[34m"
#define ANSI_TEXT_MAGENTA        "\x1b[35m"
#define ANSI_TEXT_CYAN           "\x1b[36m"
#define ANSI_TEXT_WHITE          "\x1b[37m"
#define ANSI_TEXT_BRIGHT_BLACK   "\x1b[90m"
#define ANSI_TEXT_BRIGHT_RED     "\x1b[91m"
#define ANSI_TEXT_BRIGHT_GREEN   "\x1b[92m"
#define ANSI_TEXT_BRIGHT_YELLOW  "\x1b[93m"
#define ANSI_TEXT_BRIGHT_BLUE    "\x1b[94m"
#define ANSI_TEXT_BRIGHT_MAGENTA "\x1b[95m"
#define ANSI_TEXT_BRIGHT_CYAN    "\x1b[96m"
#define ANSI_TEXT_BRIGHT_WHITE   "\x1b[97m"
#define ANSI_BG_BLACK            "\x1b[40m"
#define ANSI_BG_RED              "\x1b[41m"
#define ANSI_BG_GREEN            "\x1b[42m"
#define ANSI_BG_YELLOW           "\x1b[43m"
#define ANSI_BG_BLUE             "\x1b[44m"
#define ANSI_BG_MAGENTA          "\x1b[45m"
#define ANSI_BG_CYAN             "\x1b[46m"
#define ANSI_BG_WHITE            "\x1b[47m"
#define ANSI_BG_BRIGHT_BLACK     "\x1b[100m"
#define ANSI_BG_BRIGHT_RED       "\x1b[101m"
#define ANSI_BG_BRIGHT_GREEN     "\x1b[102m"
#define ANSI_BG_BRIGHT_YELLOW    "\x1b[103m"
#define ANSI_BG_BRIGHT_BLUE      "\x1b[104m"
#define ANSI_BG_BRIGHT_MAGENTA   "\x1b[105m"
#define ANSI_BG_BRIGHT_CYAN      "\x1b[106m"
#define ANSI_BG_BRIGHT_WHITE     "\x1b[107m"
#define ANSI_RESET               "\x1b[0m"

static const char *ansi_text_colors[] = {
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

static const char *ansi_background_colors[] = {
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

typedef enum _TermColorType {
  Background,
  Text
} TermColorType;

static const char *get_color(const TermColor color, const TermColorType color_type) {
  if (color == TermColorDefault) {
    return ANSI_RESET;
  } else {
    if (color_type == Background) {
      return ansi_background_colors[color];
    } else if (color_type == Text) {
      return ansi_text_colors[color];
    } else {
      return ANSI_RESET;
    }
  }
}

void termcolor_push(const TermColor background_color, const TermColor text_color) {
  const char *background = get_color(background_color, Background);
  const char *text = get_color(text_color, Text);
  printf("%s%s", background, text);
  /* TODO: push to global stack */
}

void termcolor_push_background(const TermColor background_color) {
  const char *background = get_color(background_color, Background);
  printf("%s", background);
  /* TODO: push to global stack */
}

void termcolor_push_text(const TermColor text_color) {
  const char *text = get_color(text_color, Text);
  printf("%s", text);
  /* TODO: push to global stack */
}

void termcolor_pop(void) {
  /* TODO: pop from global stack */
  /* if stack empty, do nothing */
}

void termcolor_clear(void) {
  printf(ANSI_RESET);
  /* TODO: empty global stack */
}
