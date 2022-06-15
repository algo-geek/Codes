//naive // time: theta(n) // cause overflow for large numbers
#include <iostream>
#include <limits.h>
using namespace std;

 int countTrailingZeros(int n)
{
	int fac=1, res=0;

	for(int i=2; i<=n; i++)
	{
		fac=fac*i;
	}

    while(fac%10==0)
    {
        res++;
        fac/=10;
    }
	return res;
}
int main() {
    
    	int number = 251;
    	
    	cout<<countTrailingZeros(number);
    	
    	return 0;
}


//optimised // taking count of 5s
// time: theta(log n) 
#include <iostream>
#include <limits.h>
using namespace std;

 int countTrailingZeros(int n)
{
	int res = 0;

	for(int i=5; i<=n; i=i*5)
	{
		res = res + (n / i);
	}

	return res;
}
int main() {
    
    	int number = 251;
    	
    	cout<<countTrailingZeros(number);
    	
    	return 0;
}