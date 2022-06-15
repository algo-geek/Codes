
// time: (R+C)
#include <bits/stdc++.h> 
using namespace std;

const int R = 4, C = 4;

void search(int mat[R][C], int x)
{
	int i  = 0, j = C - 1;
 
 // top left
 // bottom right can also be used
	while(i < R && j >= 0)
	{
		if(mat[i][j] == x)
		{
			cout << "Found at (" << i << ", " << j << ")";
			
			return;
		}
		else if(mat[i][j] > x)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
		
	cout << "Not Found";
}

int main()
{	
    int arr[][C] = {{10, 20, 30, 40},
    			   {15, 25, 35, 45},
    			   {27, 29, 35, 45},
    			   {32, 33, 39, 50}};
			   
	int x = 29;	   

	search(arr, x);

	return 0;
}