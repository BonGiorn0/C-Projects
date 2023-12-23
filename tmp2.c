#include <stdio.h>
#include <curses.h>

int main()
{
	initscr();
	keypad(stdscr, 1);
	while(1){
		int c;
		c = getch();
		mvprintw(0, 0, "     ");
		mvaddch(0, 0, c);
	}
}
