//iterative // time: theta(n) // space: O(1) // better solution
#include <iostream>
#include <limits.h>
using namespace std;

int fact(int n)
{
	int res = 1;

	for(int i=2; i<=n; i++)
	{
		res = res * i;
	}
	
	return res;
}
int main() {
    
    	int number = 5;
    	
    	cout<<fact(number);
    	
    	return 0;
}

//recursive  time: theta(n) // space: theta(n) 
// n+1 function calls in function call stack when we reach base case
#include <iostream>
#include <limits.h>
using namespace std;

int fact(int n)
{
	if(n==0)
	   return 1;
		
	return n * fact(n-1);
}
int main() {
    
    	int number = 5;
    	
    	cout<<fact(number);
    	
    	return 0;
}