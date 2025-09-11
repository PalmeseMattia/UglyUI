#ifndef UTILS_H
#define UTILS_H


// Empty set 
#define EMPTY_SET "\033[%dm"
// ANSI Reset
#define RESET "\033[0m"
// Cursor Visibility
#define HIDE_CURSOR "\033[?25l"
#define SHOW_CURSOR "\033[?25h"

// Save/Restore Cursor Position
#define SAVE_CURSOR "\033[s"
#define RESTORE_CURSOR "\033[u"

#define set(value) printf(EMPTY_SET, value)
#define reset()  printf(RESET)

#endif // !UTILS_H
