#include<bits/stdc++.h>
using namespace std;

#define n 8

void printSol(int board[][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j]<<' ';
        }
        cout<<endl;
    }
}

bool isSafe(int board[][n], int row, int col){
    for(int i=n; i>=0; i--){
        if(board[i][col] == 1)
         return false;
    }
    for(int i=row, j=col; i>=0 and j>=0; i--, j--){
        if(board[i][j] == 1)
            return false;
    }
    for(int i=row,j=col; i>=0 and j<n; i--, j++){
        if(board[i][j] == 1)
            return false;
    }
    return true;
}
