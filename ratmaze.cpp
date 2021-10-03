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


void countAllPaths(int maze[][len], int sx, int sy, int dx, int dy, int &count){
    if(sx<0 or sy<0 or dx>3 or dy>3 or maze[sx][sy] == 0 or vis[sx][sy] == 1)return ;

    if(sx == dx and sy == dy){
        count += 1;
        
    }
    vis[sx][sy] = 1;
    countAllPaths(maze, sx, sy-1, dx, dy, count);

    countAllPaths(maze, sx, sy+1, dx, dy, count);

    countAllPaths(maze, sx+1, sy, dx, dy, count);

    countAllPaths(maze, sx-1, sy, dx, dy, count);

    vis[sx][sy] = 0;
}

int main(){
    int maze[4][4] = {  {1, 0, 0 ,0}, 
                        {1, 1, 0, 0}, 
                        {0, 1, 1, 0}, 
                        {0, 0, 1, 1}};
    int count = 0;
    cout<<solvableMaze(maze, 0, 0, 3, 3)<<endl;
    // countAllPaths(maze, 0, 0, 3, 3, count);
    // cout<<count<<endl;

    return 0;
}
