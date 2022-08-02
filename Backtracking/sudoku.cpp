#include <bits/stdc++.h> 
using namespace std; 
#define N 9 

bool isSafe(int board[N][N],int row, int col, int num) 
    { 
        // curr row
        for (int d = 0; d < N; d++)  
        { 
            
            if (board[row][d] == num) { 
                return false; 
            } 
        } 

        // curr column
        for (int r = 0; r < N; r++)  
        { 
               
            if (board[r][col] == num)  
            { 
                return false; 
            } 
        } 

        // curr grid  
        int s = (int)sqrt(N); 
        int boxRowStart = row - row % s; // starting row number of grid
        int boxColStart = col - col % s; // starting column number of grid
  
        for (int r = boxRowStart; r < boxRowStart + s; r++)  
        { 
            for (int d = boxColStart; d < boxColStart + s; d++)  
            { 
                if (board[r][d] == num)  
                { 
                    return false; 
                } 
            } 
        } 
  
        return true; 
    } 

bool solve(int board[N][N],int n) 
{ 
	    int row = -1; 
        int col = -1; 
        bool isEmpty = true; 
        for (int i = 0; i < n; i++)  
        { 
            for (int j = 0; j < n; j++)  
            { 
                // if empty cell
                if (board[i][j] == 0)  
                { 
                    row = i; 
                    col = j; 
                    isEmpty = false; 
                    break; 
                } 
            } 
            if (!isEmpty) { 
                break; 
            } 
        } 

        // no empty cell
        if (isEmpty)  
        { 
            return true; 
        } 
        
        // empty cells present
        for (int num = 1; num <= n; num++)  
        { 
            if (isSafe(board, row, col, num))  
            { 
                board[row][col] = num; 
                // recursively call for remaining empty cells
                if (solve(board, n))  
                { 
                    return true; 
                } 
                else 
                { 
                    // backtrack
                    board[row][col] = 0; 
                } 
            } 
        } 
        return false; 
} 

void printGrid(int grid[N][N]) 
{ 
	for (int row = 0; row < N; row++) 
	{ 
		for (int col = 0; col < N; col++) 
			cout << grid[row][col] << " "; 
		cout << endl; 
	} 
} 
 
int main() 
{ 
	int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, 
					{ 5, 2, 0, 0, 0, 0, 0, 0, 0 }, 
					{ 0, 8, 7, 0, 0, 0, 0, 3, 1 }, 
					{ 0, 0, 3, 0, 1, 0, 0, 8, 0 }, 
					{ 9, 0, 0, 8, 6, 3, 0, 0, 5 }, 
					{ 0, 5, 0, 0, 9, 0, 6, 0, 0 }, 
					{ 1, 3, 0, 0, 0, 0, 2, 5, 0 }, 
					{ 0, 0, 0, 0, 0, 0, 0, 7, 4 }, 
					{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } }; 
	if (solve(grid,N) == true) 
		printGrid(grid); 
	else
		cout << "No solution exists"; 

	return 0; 
} 

