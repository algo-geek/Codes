// no of bits to be flipped to convert a to b
// method 1
#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
	int count = 0;
	while (n > 0) {
		count++;
		n &= (n - 1);
	}
	return count;
}

int FlippedCount(int a, int b)
{
    // count setbits in xor
	return countSetBits(a ^ b);
}

int main()
{
	int a = 10;
	int b = 20;
	cout << FlippedCount(a, b) << endl;
	return 0;
}

// method 2
#include <bits/stdc++.h>
using namespace std;

int countFlips(int a, int b)
{

int flips = 0;

// & each bits of a && b with 1
// and store them if t1 and t2
// if t1 != t2 then we will flip that bit

while(a > 0 || b > 0){

	int t1 = (a&1);
	int t2 = (b&1);

	if(t1!=t2){
	flips++;
	}
	// right shifting a and b
	a>>=1;
	b>>=1;
}

return flips;
}

int main () {
int a = 10;
int b = 20;
cout <<countFlips(a, b);
}

