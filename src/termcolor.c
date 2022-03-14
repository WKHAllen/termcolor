#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
  ANSI_TEXT_BRIGHT_WHITE,
  ""
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
  ANSI_BG_BRIGHT_WHITE,
  ""
};

typedef enum _TermColorType {
  TermColorTypeBackground,
  TermColorTypeText
} TermColorType;

typedef struct _TermColorStackNode {
  TermColor color_set[2];
  struct _TermColorStackNode *next;
} TermColorStackNode;

typedef struct _TermColorStack {
  TermColorStackNode *head;
  unsigned int size;
} TermColorStack;

static TermColorStack *termcolor_stack(void) {
  TermColorStack *stack = (TermColorStack *)malloc(sizeof(TermColorStack));
  stack->head = NULL;
  stack->size = 0;
  return stack;
}

static bool termcolor_stack_is_empty(const TermColorStack *stack) {
  return stack->size == 0;
}

static void termcolor_stack_push(TermColorStack *stack, const TermColor background_color, const TermColor text_color) {
  TermColorStackNode *new_node = (TermColorStackNode *)malloc(sizeof(TermColorStackNode));
  new_node->color_set[0] = background_color;
  new_node->color_set[1] = text_color;
  new_node->next = stack->head;
  stack->head = new_node;
  stack->size++;
}

static TermColor *termcolor_stack_pop(TermColorStack *stack) {
  if (termcolor_stack_is_empty(stack)) {
    return NULL;
  } else {
    TermColor *color_set = stack->head->color_set;
    TermColorStackNode *new_head = stack->head->next;
    free(stack->head);
    stack->head = new_head;
    stack->size--;
    return color_set;
  }
}

static TermColor *termcolor_stack_peek(TermColorStack *stack) {
  if (termcolor_stack_is_empty(stack)) {
    return NULL;
  } else {
    return stack->head->color_set;
  }
}

static void termcolor_stack_destroy(TermColorStack *stack) {
  while (!termcolor_stack_is_empty(stack)) {
    termcolor_stack_pop(stack);
  }

  free(stack);
}

static TermColorStack *color_stack = NULL;

static void init_color_stack(void) {
  if (color_stack == NULL) {
    color_stack = termcolor_stack();
  }
}

static const char *get_color(const TermColor color, const TermColorType color_type) {
  if (color_type == TermColorTypeBackground) {
    return ansi_background_colors[color];
  } else if (color_type == TermColorTypeText) {
    return ansi_text_colors[color];
  } else {
    return ANSI_RESET;
  }
}

void termcolor_push(const TermColor background_color, const TermColor text_color) {
  const char *background = get_color(background_color, TermColorTypeBackground);
  const char *text = get_color(text_color, TermColorTypeText);
  printf("%s%s", background, text);
  init_color_stack();
  termcolor_stack_push(color_stack, background_color, text_color);
}

void termcolor_push_background(const TermColor background_color) {
  const char *background = get_color(background_color, TermColorTypeBackground);
  printf("%s", background);
  init_color_stack();

  if (termcolor_stack_is_empty(color_stack)) {
    termcolor_stack_push(color_stack, background_color, TermColorNone);
  } else {
    TermColor *last_colors = termcolor_stack_peek(color_stack);
    termcolor_stack_push(color_stack, background_color, last_colors[1]);
  }
}

void termcolor_push_text(const TermColor text_color) {
  const char *text = get_color(text_color, TermColorTypeText);
  printf("%s", text);
  init_color_stack();

  if (termcolor_stack_is_empty(color_stack)) {
    termcolor_stack_push(color_stack, TermColorNone, text_color);
  } else {
    TermColor *last_colors = termcolor_stack_peek(color_stack);
    termcolor_stack_push(color_stack, last_colors[0], text_color);
  }
}

void termcolor_pop(void) {
  init_color_stack();
  termcolor_stack_pop(color_stack);

  if (termcolor_stack_is_empty(color_stack)) {
    termcolor_clear();
  } else {
    TermColor *last_colors = termcolor_stack_peek(color_stack);
    const char *background = get_color(last_colors[0], TermColorTypeBackground);
    const char *text = get_color(last_colors[1], TermColorTypeText);
    printf("%s%s", background, text);
  }
}

void termcolor_clear(void) {
  printf(ANSI_RESET);
  init_color_stack();
  termcolor_stack_destroy(color_stack);
  color_stack = NULL;
}
