#ifndef TEXT_STYLES_H 
#define TEXT_STYLES_H

// ANSI Reset
#define RESET "\033[0m"

// Text Formatting
#define BOLD "\033[1m%s\033[21m"
#define DIM "\033[2m%s\033[22m"
#define ITALIC "\033[3m%s\033[23m"
#define UNDERLINE "\033[4m%s\033[24m"
#define BLINK "\033[5m%s\033[25m"
#define REVERSE "\033[7m%s\033[27m"
#define STRIKETHROUGH "\033[9m%s\033[29m"

#endif
