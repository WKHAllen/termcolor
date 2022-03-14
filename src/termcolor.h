/**
 * @file termcolor.h
 * @author Will Allen
 * @brief A C library for manipulating terminal colors using ANSI escape codes.
 * @version 1.0.0
 * @date 2022-03-13
 */

#pragma once
#ifndef TERMCOLOR_H
#define TERMCOLOR_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _TermColor {
  TermColorBlack,
  TermColorRed,
  TermColorGreen,
  TermColorYellow,
  TermColorBlue,
  TermColorMagenta,
  TermColorCyan,
  TermColorLightGray,
  TermColorGray,
  TermColorLightRed,
  TermColorLightGreen,
  TermColorLightYellow,
  TermColorLightBlue,
  TermColorLightMagenta,
  TermColorLightCyan,
  TermColorWhite,
  TermColorDefault
} TermColor;

/**
 * @brief Push new background and text colors to the terminal.
 * 
 * @param background_color The new background color.
 * @param text_color The new text color.
 */
void termcolor_push(const TermColor background_color, const TermColor text_color);

/**
 * @brief Push a new background color to the terminal.
 * 
 * @param background_color The new background color.
 */
void termcolor_push_background(const TermColor background_color);

/**
 * @brief Push a new text color to the terminal.
 * 
 * @param text_color The new text color.
 */
void termcolor_push_text(const TermColor text_color);

/**
 * @brief Pop off the most recent background and text colors.
 */
void termcolor_pop(void);

/**
 * @brief Clear all color formatting from the terminal.
 */
void termcolor_clear(void);

#ifdef __cplusplus
}
#endif

#endif /* TERMCOLOR_H */
