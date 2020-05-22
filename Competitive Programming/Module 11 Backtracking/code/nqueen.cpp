#include<iostream>
using namespace std;


void printSol(int** board, int n)
{
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            cout << board[r][c] << " ";
        }
    }
    cout << "\n";
}



bool isSafe(int** board, int row, int col, int n)
{
    int i,j;
    //left to current position in the row 
    for(i=0;i<col;i++){
        if(board[row][i]){
            return false;
        }
    }

    //upper left diagonal
    for(i=row, j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]){
            return false;
        }
    }

    //bottom left diagonal
    for(i=row,j=col;i<n && j>=0;i++,j--){
        if(board[i][j]){
            return false;
        }
    }
    return true;
}

bool solveNQ(int** board, int col, int n)
{
    if(col >= n){
        printSol(board, n);
        return true;
    }
    bool ans=false;
    for(int i=0;i<n;i++){
        if(isSafe(board, i, col, n)){
            board[i][col] = 1;
            if(solveNQ(board,col+1,n)){
                ans = true;
            }
            board[i][col] = 0;
        }
    }
    return ans;
}


void placeNQueens(int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
    int** board = new int*[n];
    for(int i=0;i<n;i++)
    {
        board[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            board[i][j] = 0;
        }
    }
    if(!solveNQ(board, 0, n)){
        return;
    }
    return;
}


int main(){

  int n; 
  cin >> n ; //dimension of chess board
  placeNQueens(n);

}
