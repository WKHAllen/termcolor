#pragma once
#ifndef TERMCOLOR_H
#define TERMCOLOR_H

#ifdef __cplusplus
extern "C" {
#endif

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

extern const char *ansi_text_colors[];

extern const char *ansi_background_colors[];

typedef enum _TermColor {
  Black,
  Red,
  Green,
  Yellow,
  Blue,
  Magenta,
  Cyan,
  LightGray,
  Gray,
  LightRed,
  LightGreen,
  LightYellow,
  LightBlue,
  LightMagenta,
  LightCyan,
  White
} TermColor;

void coloredText(char *text, TermColor background_color, TermColor text_color);

void resetTermColor(void);

#ifdef __cplusplus
}
#endif

#endif /* TERMCOLOR_H */
