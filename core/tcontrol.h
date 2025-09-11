#ifndef TCONTROL_H
#define TCONTROL_H

// Cursor Consts
#define CURSOR_UP "\033[%dA"
#define CURSOR_DOWN "\033[%dB"
#define CURSOR_FORWARD "\033[%dC"
#define CURSOR_BACK "\033[%dD"
#define CURSOR_NEXT_LINE "\033[E"
#define CURSOR_PREV_LINE "\033[%dF"
#define CURSOR_HORIZONTAL_ABSOLUTE "\033[%G"
#define CURSOR_POSITION "\033[%d;%dH"
#define SAVE_CURSOR "\033[s"
#define RESTORE_CURSOR "\033[u"

#define HIDE_CURSOR "\033[?25l"
#define SHOW_CURSOR "\033[?25h"

//-------- CURSOR VISIBILITY --------
#define showCursor() printf(SHOW_CURSOR)
#define hideCursor() printf(HIDE_CURSOR)
//-----------------------------------

//-------- CURSOR MOVEMENT --------
#define moveTo(x, y) printf(CURSOR_POSITION, (y)+1,(x)+1)
#define moveUpBy(n) printf(CURSOR_UP, n )
#define moveDownBy(n) printf(CURSOR_DOWN,n)
#define moveBackBy(n) printf(CURSOR_BACK,n)
#define moveForwardBy(n) printf(CURSOR_FORWARD,n)
#define moveToNextLine() printf(CURSOR_NEXT_LINE)
#define moveToPrevLine(n) printf(CURSOR_PREV_LINE,n)
//---------------------------------
#define CLEAR_SCREEN "\033[2J"
#define CLEAR_LINE "\033[2K"
#define CLEAR_TO_END_OF_SCREEN "\033[0J"
#define CLEAR_TO_BEGINNING_OF_SCREEN "\033[1J"
#define CLEAR_TO_END_OF_LINE "\033[0K"
#define CLEAR_TO_BEGINNING_OF_LINE "\033[1K"
//-------- SCREEN --------
#define clearScreen() printf(CLEAR_SCREEN)
#define clearLine() printf(CLEAR_LINE)
#define clearToEndOfScreen() printf(CLEAR_TO_END_OF_SCREEN)
#define clearToBeginningOfScreen() printf(CLEAR_TO_BEGINNING_OF_SCREEN)
#define clearToEndOfLine() printf(CLEAR_TO_END_OF_LINE)
#define clearToBeginningOfLine() printf(CLEAR_TO_BEGINNING_OF_LINE)
//------------------------

#endif // !LIBS_H
