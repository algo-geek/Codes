// dp
#include <iostream>
#include <string.h>
using namespace std;


int LIS( int arr[], int n )  
{  
    int lis[n]; 
   
    lis[0] = 1;    
  
  
    for (int i = 1; i < n; i++ )  
    { 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i] > arr[j])  
                lis[i] = max(lis[i], lis[j] + 1);  
    } 
    
    int res = lis[0];
    
    for(int i=0;i<n;i++)
    {
        res = max(lis[i], res);
    }
    
    return res;
 
}  

int main() {
	
	
int arr[] ={3, 4, 2, 8, 10, 5, 1};
int n = 7;

cout<<LIS(arr, n);
	

}

// binary search
#include <iostream>
#include <string.h>
using namespace std;


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