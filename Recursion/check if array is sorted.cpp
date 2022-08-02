// recursion
#include <iostream>
using namespace std;

bool sorted(int a[], int n)
{
    if(n==1)
    return true;
    
    bool restarray=sorted(a+1, n-1);
    return (a[0]<a[1] && restarray);
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    cout<<sorted(a, n)<<endl;
}

// array
#include <iostream>
#include <cmath>
using namespace std;

bool isSorted(int arr[], int n)
{
	for(int i = 1; i < n; i++)
	{
	    if(arr[i] < arr[i - 1])
	        return false;
	}

	return true;
} 

    
int main() {
	
      int arr[] = {5, 12, 30, 2, 35}, n = 5;
      
      printf("%s", isSorted(arr, n)? "true": "false");
    
}