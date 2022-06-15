//iterative // time: theta(no. of digits) //space: O(1)
#include <iostream>
#include <limits.h>
using namespace std;

int countDigits(int x)
{
	int res = 0;

	while(x > 0)
	{
			x = x / 10;

			res++;
	}	

	return res;
}

int main() {
    
    	int number = 789;
    	
    	cout<<countDigits(number);
    	
    	return 0;
}

//recursive
#include <bits/stdc++.h>
using namespace std;

int countDigits(int x)
{
	if(x==0)
      return 0;

	return 1 + countDigits(x/10);
}

int main() {
    
    	int number = 789;
    	
    	cout<<countDigits(number);
    	
    	return 0;
}

//logarithmic // Digit count of N = upper bound of log10(N). 
#include <bits/stdc++.h>
using namespace std;

int countDigits(int x)
{

	return floor(log10(x)+1);
}

int main() {
    
    	int number = 789;
    	
    	cout<<countDigits(number);
    	
    	return 0;
}
