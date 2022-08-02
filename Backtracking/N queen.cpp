// printing one solution
#include <bits/stdc++.h>
using namespace std;

#define N 4 
  
int board[N][N];  

void printSolution(int board[N][N]) 
{ 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) 
            printf(" %d ", board[i][j]); 
        printf("\n"); 
    } 
} 
  
bool isSafe(int row, int col) 
{ 
  // checking for curr row of previous columns 
    for (int i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
  
  // upper diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return false; 
  
  // lower diagonal
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
} 
  
bool solveRec(int col) 
{ 
    if (col == N) 
        return true; 
  
  // tries to place queens by iterating each row 
    for (int i = 0; i < N; i++) { 
     
        if (isSafe(i, col)) 
        { 
            board[i][col] = 1; 
  
            if (solveRec(col + 1)) 
                return true; 
  
            board[i][col] = 0;
        } 
    } 
  
    return false; 
} 
  
bool solve() 
{
    if (solveRec(0) == false) { 
        printf("Solution does not exist"); 
        return false; 
    } 
  
    printSolution(board); 
    return true; 
}

int main() {
	
	solve(); 
    return 0; 
	
}

// printing all solutions
#include <bits/stdc++.h>
using namespace std;

#define N 4 
  
int board[N][N];  
vector<vector<int> > result;

bool isSafe(int row, int col) 
{ 
    for (int i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
  
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return false; 
  
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
} 
  
bool solveRec(int col) 
{ 
    if (col == N) 
    {
        // start
        vector<int> v;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1)
                    v.push_back(j + 1);
            }
        }
        result.push_back(v);
        // end
        return true;
    }
  
  // start
  bool res = false;
  // end
    for (int i = 0; i < N; i++) { 
     
        if (isSafe(i, col)) 
        { 
            board[i][col] = 1; 

             // start
            res = solveRec(col + 1) || res;
             // end
            board[i][col] = 0;
        } 
    } 
  
    return res; 
} 
  
// start
vector<vector<int> > solve2() 
{
    result.clear();
    
    if (solveRec(0) == false) { 
        printf("Solution does not exist"); 
        return {}; 
    } 
  
    sort(result.begin(), result.end());
    return result;
}


int main() {
	
	vector<vector<int> > v = solve2(); 
	for (auto ar : v) {
        cout << "[";
        for (auto it : ar)
            cout << it << " ";
        cout << "]";
    }
    return 0; 
	
}
// end