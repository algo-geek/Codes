// index of row with max no. of 1s // all rows are sorted in increasing order // binary array
// O(n^2)
#define R 4
#define C 4
int rowWithMax1s(bool mat[R][C]) {
	int rowIndex = -1 ;
	int maxCount = 0 ;	
	for(int i = 0 ; i < R ; i++){
		int count = 0 ;
		for(int j = 0 ; j < C ; j++ ){
			if(mat[i][j] == 1){
				count++ ;
			}
		}
		if(count > maxCount){
			maxCount = count ;
			rowIndex = i ;
		}
	}	
	return rowIndex ;
}

// O(n+m)
#define R 4
#define C 4
int rowWithMax1s(bool mat[R][C])
{
	// Initialize first row as row with max 1s
	int j,max_row_index = 0;
	j = C - 1;

	for (int i = 0; i < R; i++) 
    {   //to check whether a row has more 1's than prev
	    bool flag=false; 

		while (j >= 0 && mat[i][j] == 1) 
        {
			j = j - 1; // Update the index of leftmost 1 seen so far
		    flag=true ; //present row has more 1's than previous
			max_row_index = i; // Update max_row_index
		}
	}
	if(max_row_index==0 && mat[0][C-1]==0)
			return -1;
	return max_row_index;
}

int main()
{
	bool mat[R][C] = { {0, 0, 0, 1},
					{0, 1, 1, 1},
					{1, 1, 1, 1},
					{0, 0, 0, 0}};

	cout << "Index of row with maximum 1s is " << rowWithMax1s(mat);

	return 0;
}
