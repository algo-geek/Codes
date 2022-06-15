//naive //time: O(min(a, b))
#include <iostream>
#include <limits.h>
using namespace std;

int gcd(int a, int b)
{
    int m=min(a, b);
	while(m>0)
	{
		if(a%m==0 && b%m==0)
        {
            break;
        }
        m--;
	}

	return m;
}

int main() {
    
    	int a = 12, b = 15;
    	
    	cout<<gcd(a, b);
    	
    	return 0;
}




#include <iostream>
#include <limits.h>
using namespace std;

int gcd(int a, int b)
{
	while(a!=b)
	{
		if(a > b)
			a = a - b;
		else
			b = b - a; 
	}

	return a;
}

int main() {
    
    	int a = 12, b = 15;
    	
    	cout<<gcd(a, b);
    	
    	return 0;
}