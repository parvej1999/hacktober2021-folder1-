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

bool solve(int board[][n], int row){
    if(row>=n)
        return true;
    
    printSol(board);
    system("clear");
    for(int col = 0; col<n; col++){
        if(isSafe(board, row, col)){
            board[row][col] = 1;
            if(solve(board, row+1))
                return true;
            board[row][col] = 0;
        }
    }
    return false;
}

int main(){
    
    int board[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            board[i][j] = 0;
        }
    }
    if(solve(board,0))
        printSol(board);
    else
        cout<<"Not Sovable"<<endl;
    return 0;   
}

