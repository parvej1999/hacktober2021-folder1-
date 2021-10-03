#include<iostream>

using namespace std;
// #define or ||;
// #define and &&;
// int maze[4][4] = {{1, 0, 0 ,0}, {0, 1 , 1 ,0}, {0, 1, 0, 0}, {0, 1, 1, 1}};
int vis[100][100] = {0};

const int len = 4;

bool solvableMaze(int maze[][len], int sx, int sy, int dx, int dy){
    if(sx<0 || sy<0 || dx>3 || dy>3 || vis[sx][sy] == 1 || maze[sx][sy] == 0)return false;

    vis[sx][sy] = 1;
    if(sx == dx and sy == dy){
        return true;
    }

    if(solvableMaze(maze, sx, sy+1, dx, dy)){
        return true;
    }

    if(solvableMaze(maze, sx, sy-1, dx, dy)){
        return true;
    }

    if(solvableMaze(maze, sx+1, sy, dx, dy)){
        return true;
    }

    if(solvableMaze(maze, sx-1, sy, dx, dy)){
        return true;
    }

    return false;
}
