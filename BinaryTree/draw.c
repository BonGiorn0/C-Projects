#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>

#include "tree.h"

void ClearScreen(int row, int col)
{
	for(int i = 0; i < row; i++){
		move(i, 0);
		for(int j = 0; j < col; j++)
			addch(' ');
	}
}

int main(int argc, char *argv[])
{
	FILE *f;
	int val, row, col, i = 1;
	struct tree *p = NULL;
	struct timespec time = {0, 500000000};

	f = fopen("random.txt", "r");

	while(fscanf(f, "%d, ", &val)){
		//AddToTree(&p, val);
		AddToAVLTree(&p, val);

		initscr();
		getmaxyx(stdscr, row, col);
		curs_set(0);

		mvprintw(row / 8, (col - 11) / 2, "New key(%d): %d", i, val);
		DrawTree(p, col / 2 - 2, (row - getHeight(p)) / 3, -1);

		getch();
		//nanosleep(&time, NULL);
		ClearScreen(row, col);
		i++;
		endwin();
	}

	fclose(f);
	getch();

#if 0
	PrintInorder(p);
	printf("\n");
	PrintPreorder(p);
	printf("\n");
	PrintPostorder(p);
	printf("\n");
#endif

	return 0;
}
