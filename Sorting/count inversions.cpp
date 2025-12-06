// naive // a[i]>a[j] such that i<j
#include <bits/stdc++.h>
using namespace std;

int countInversions(int arr[], int n){
    
    int res=0;
    for(int i=0;i<(n-1);i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j])
                res++;
        }
    }
    return res;
}

// efficient

// During each merging step of the merge sort algorithm, 
// we count cross inversions by comparing elements from left half with those right half. 
// If we find an element arr[i] in left half that is greater than arr[j] in the right half, 
// we can conclude that all elements after i in the left half will also be greater than arr[j]. 
// This allows us to count multiple inversions at once. 

// reduces no of comparisons needed, enhancing overall performance of the inversion counting algorithm.

int countAndMerge(int arr[], int l, int m, int r)
{
    int n1=m-l+1, n2=r-m;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++)
        left[i]=arr[i+l];
    for(int j=0;j<n2;j++)
        right[j]=arr[m+1+j];    
    int res=0,i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j])
            {arr[k++]=left[i++];}
        else{
            arr[k++]=right[j++];
            res=res+(n1-i);
        }
    }
    while(i<n1)
        arr[k++]=left[i++];
    while(j<n2)
        arr[k++]=right[j++];
    return res;
}

int countInv(int arr[], int l, int r)
{
    int res = 0;
    if (l<r) {
       
        int m = (r + l) / 2;
        
        // Inversion count will be sum of inversions in left-part, right-part and number of inversions in merging       
        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);
        res += countAndMerge(arr, l, m , r);
    }
    return res;
}
 
int main() {
	
    int arr[]={2,4,1,3,5};
	
	int n=sizeof(arr)/sizeof(arr[0]);
	
	cout<<countInv(arr,0,n-1);
}
