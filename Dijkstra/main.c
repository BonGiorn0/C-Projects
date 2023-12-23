#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#include "dijkstra.h"

enum{
    KeyEnter = 10,
    rainbow = 77
};

int SecToNanosec(float sec)
{
    for(int i = 0; i < 8; i++)
        sec *= 10;
    return (int)(sec);
}

int SetColor(int r, int g, int b)
{
    if (r > 1000) r = 1000;
    if (g > 1000) g = 1000;
    if (b > 1000) b = 1000;

    if (r < 0) r = 0;
    if (g < 0) g = 0;
    if (b < 0) b = 0;

    int n = (r + g + b) / 12 + 8; 
    init_color(n, r, g, b);
    return n;
}

int SetPair(int fg, int bg)
{
    int n = bg + fg + 8;
    init_pair(n, fg, bg);
    return n;
}

void MovePoint(int *point, int key, int row, int col)
{
    switch(key){
    case KEY_UP:
        *point -= col;
        break;
    case KEY_DOWN:
        *point += col;
        break;
    case KEY_LEFT:
        *point -= 1;
        break;
    case KEY_RIGHT:
        *point += 1;
        break;
    }
}

void DrawPath(const struct node v[], int n, int m, int end)
{
    int i = v[end].prev;
    while(v[i].distance != 0){
        int color = SetColor(1000, 1000, 500);
        int pair = SetPair(color, COLOR_BLACK);
        mvaddch(i / m, i % m, 'o'| A_BOLD | COLOR_PAIR(pair));
        i = v[i].prev;
    }
    refresh();

}

void DrawMap(const struct node v[], int n, int m)
{
    struct timespec sleepTime = {0, SecToNanosec(0.005)};
    for(int i = 0; i < n * m; i++){
        move(i / m, i % m);
        addch('.');
        if (v[i].visited){
            int color = SetColor(v[i].distance * 17, 500, 350);
            int pair = SetPair(color, COLOR_BLACK);
            move(i / m, i % m);
            addch('|' | COLOR_PAIR(pair));
        }
        if (v[i].isWall){
            move(i / m, i % m);
            init_pair(1, COLOR_GREEN, COLOR_BLACK);
            addch('X' | A_BOLD | COLOR_PAIR(0));
        }
        if (v[i].isSrc){
            move(i / m, i % m);
            init_pair(1, COLOR_GREEN, COLOR_BLACK);
            addch('S' | A_BOLD | COLOR_PAIR(1));
        }
        if (v[i].isEnd){
            init_pair(2, COLOR_RED, COLOR_BLACK);
            move(i / m, i % m);
            addch('E'| A_BOLD | COLOR_PAIR(2));
        }
    }
    refresh();
    nanosleep(&sleepTime, NULL);
}

int main(int argc, char *argv[]){
    int src, end, current, key, row, col;
    int **g;
    struct node *vertex;
    struct timespec sleepTime = {0, SecToNanosec(0.05)};

    initscr();
    getmaxyx(stdscr, row, col);
    //row = atoi(argv[3]);
    //col = atoi(argv[4]);
    curs_set(0);
    keypad(stdscr, 1);
    timeout(0);
    start_color();

    g = malloc(row * col * sizeof(int *));
    for(int i = 0; i < row * col; i++)
        g[i] = malloc(col * row * sizeof(int));

    CreateGraph(g, row, col);

    vertex = malloc(row * col * sizeof(struct node));
    if (vertex == NULL){
        printf("No memory(((\n");
        return 1;
    }

    current = src = end = row * col / 2;
    //VertexInit(vertex, g, row * col, src, end);
    DrawMap(vertex, row, col);

    while((key = getch()) != KeyEnter){
        vertex[src].isSrc = 0;
        MovePoint(&src, key, row, col);
        vertex[src].isSrc = 1;
        DrawMap(vertex, row, col);
    }
    while((key = getch()) != KeyEnter){
    vertex[end].isEnd = 0;
        MovePoint(&end, key, row, col);
        vertex[end].isEnd = 1;
        DrawMap(vertex, row, col);
    }
    int WallMode = 0;
    while((key = getch()) != KeyEnter){
        MovePoint(&current, key, row, col);
        if(key == KEY_F(2))
            WallMode = 1;
        if(key == KEY_F(3))
            WallMode = 0;

        if(WallMode){
            DeleteGraphVertex(g, current, row, col);
            vertex[current].isWall = 1;
        }else{
            AddGraphVertex(g, current, row, col);
            vertex[current].isWall = 0;
        }
        DrawMap(vertex, row, col);
    }
    VertexInit(vertex, g, row * col, src, end);

    int i = 0, endNotFound = 1;
    while(endNotFound && i < row * col){
        endNotFound = 
            Dijkstra(vertex, g, row * col, &current);  
        DrawMap(vertex, row, col);
        DrawPath(vertex, row, col, current);
        nanosleep(&sleepTime, NULL);
        i++;
    }
    getchar();

    endwin();
    //PrintMatrix(g, row * col, col * row);
    //PrintPseudoMatrix(vertex, row, col);
    return 0;
}
