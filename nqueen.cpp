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
