#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

/******************************************
 *                                        *
 *                INCLUDES                *
 *                                        *
 ******************************************/

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstdio>
#include <climits>
#include <cctype>

/******************************************
 *                                        *
 *                DEFINES                 *
 *                                        *
 ******************************************/

#define PRINT std::cout

#define ENDL std::endl

#define STRING std::string

// print (x) 'n'
#define SPACER(x)               \
    for (int i = 0; i < x; i++) \
        PRINT << ENDL;

// reset text config + '\n'
#define RESEND \
    RESET << ENDL

// align the text (x) spaces to the Right
#define R_ALIGN(x) \
    std::setw(x) << std::right

// align the text (x) spaces to the Left
#define L_ALIGN(x) \
    std::setw(x) << std::left

// a debug message for functions
#define FT_MSG(name) \
    PRINT << MAGENTA ITALICS << name << " called" << RESEND;

// a title message for main
#define MAIN_MSG(name) \
    PRINT << GREEN UNDERLINED << name << RESEND;

// default try catch exception handle
// print error message followed by a '\n'
#define CATCH \
    catch (const std::exception &e) { std::cerr << e.what() << '\n'; }

/******************************************
 *                                        *
 *              DEFINE COLORS             *
 *                                        *
 ******************************************/

// Cursor Moving
#define CURSOR_UP(x) "\033[" << x << "A"
#define CURSOR_DOWN(x) "\033[" << x << "B"
#define CURSOR_RIGHT(x) "\033[" << x << "C"
#define CURSOR_LEFT(x) "\033[" << x << "D"
#define CURSOR_ALL_LEFT "\033[0G"

// Cursor Clear Screen
#define CLEAR_SCREEN_FORWARD_CURSOR "\033[J"
#define CLEAR_LINE_FORWARD_CURSOR "\033[K"
#define CLEAR_LINE_BACK_CURSOR "\033[1K"
#define CLEAR_ACTUAL_LINE "\033[0K"

// Text Colors (30-37)
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define ORANGE "\033[38;2;255;140;0m"

// Bright Text Colors (90-97)
#define BRIGHT_BLACK "\033[90m"
#define BRIGHT_RED "\033[91m"
#define BRIGHT_GREEN "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN "\033[96m"
#define BRIGHT_WHITE "\033[97m"

// Text Background (40-47)
#define BLACK_BACKGROUND "\033[40m"
#define RED_BACKGROUND "\033[41m"
#define GREEN_BACKGROUND "\033[42m"
#define YELLOW_BACKGROUND "\033[43m"
#define BLUE_BACKGROUND "\033[44m"
#define MAGENTA_BACKGROUND "\033[45m"
#define CYAN_BACKGROUND "\033[46m"
#define WHITE_BACKGROUND "\033[47m"

// Text Formatting (1-9)
#define BOLT "\033[1m"
#define LOW_BRIGHT "\033[2m"
#define ITALICS "\033[3m"
#define UNDERLINED "\033[4m"
#define BLINKING "\033[5m"
#define REVERSE_COLORS "\033[7m"
#define HIDE_TEXT "\033[8m"
#define CROSSED_OUT "\033[9m"

#endif