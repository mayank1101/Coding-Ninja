//rat in a maze problem
#include<iostream>
using namespace std;
//rat in a maze problem
#include<iostream>
using namespace std;

void printSol(int** sol, int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << sol[i][j] << " ";
		}
	}
	cout << "\n";
}

void solveMaze(int maze[][20], int n, int** sol, int r, int c)
{
	if(r ==  n-1 && c == n-1){
		sol[r][c] = 1;
		printSol(sol,n);
		return;
	}
	if(r >= n || r < 0 || c >= n || c < 0 || sol[r][c] == 1 || maze[r][c] == 0){
		return;
	}
	sol[r][c] = 1;
	solveMaze(maze,n,sol,r-1,c); // up
	solveMaze(maze,n,sol,r+1,c); // down
	solveMaze(maze,n,sol,r,c-1); // left
	solveMaze(maze,n,sol,r,c+1); // right
	sol[r][c] = 0;
}

void ratInAMaze(int maze[][20], int n)
{
	int** sol = new int*[n];
	for(int i=0;i<n;i++)
	{
		sol[i] = new int[n];
		for(int j=0;j<n;j++)
		{
			sol[i][j] = 0;
		}
	}
	solveMaze(maze,n,sol,0,0);
	return;
}


int main(){

  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  ratInAMaze(maze, n);
}



