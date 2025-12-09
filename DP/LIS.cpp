// dp // O(n^2)
// lis[i] stores the length of the longest increasing subsequence that ends at index i
int LIS( int arr[], int n )  
{  
    vector<int>lis(n,1); 
	int res = 1;
    for (int i = 1; i < n; i++ )  
    { 
        for (int j = 0; j < i; j++ )   
		{
				if ( arr[i] > arr[j])  
                	lis[i] = max(lis[i], lis[j] + 1); 
		}
		res = max(lis[i], res);
    }     
    return res;
}  


// binary search // n long n
// The idea is to traverse the given sequence and maintain a separate list of sorted subsequence so far. 
//For every new element, find its position in the sorted subsequence using Binary Search.

// If the number is greater than the last element of the last bucket (i.e., the largest element in the current subsequence), we append the number to the end of the list. This indicates that we have found a longer subsequence.
// Otherwise, we perform a binary search on the list of buckets to find the smallest element that is greater than or equal to the current number. This step helps us maintain the property of increasing elements in the buckets.
// Once we find the position to update, we replace that element with the current number. This keeps the buckets sorted and ensures that we have the potential for a longer subsequence in the future.
        
	int ceilIdx(int tail[], int l, int r, int key) 
        { 
            while (r > l) {         
                int m = l + (r - l) / 2; 
                if (tail[m] >= key) 
                    r = m; 
                else
                    l = m+1; 
            } 
      
            return r; 
        } 
  
    int LIS(int arr[], int n) 
    { 
     
  
        int tail[n]; 
        int len =1; 
  
        tail[0] = arr[0]; 
        
        for (int i = 1; i < n; i++) {
            
            if(arr[i] > tail[len - 1])
            {
                tail[len] = arr[i];
                len++;
            }
            else{
                int c = ceilIdx(tail, 0, len - 1, arr[i]);
                
                tail[c] = arr[i];
            }
        } 
  
        return len; 
    } 


int main() {
	
	
 int arr[] ={3, 10, 20, 4, 6, 7};
  int n = 6;

cout<<LIS(arr, n);
	

}
