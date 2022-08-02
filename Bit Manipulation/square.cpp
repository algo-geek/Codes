// square of a no without using *, /, pow
// naive // O(n)
#include <iostream>
using namespace std;

int square(int n)
{
	if (n < 0)
		n = -n;

	int res = n;

	for (int i = 1; i < n; i++)
		res += n;

	return res;
}

int main()
{
	for (int n = 1; n <= 5; n++)
		cout << "n = " << n << ", n^2 = " << square(n)
			<< endl;
	return 0;
}

// efficient // O(log n)
#include <iostream>
using namespace std;

int square(int num)
{
	if (num < 0)
		num = -num;

	int power = 0, result = 0;
	int temp = num;

	while (temp) {
		if (temp & 1) {
			// result=result+(num*(2^power))
			result += (num << power);
		}
		power++;

		// temp=temp/2
		temp = temp >> 1;
	}

	return result;
}

int main()
{
	for (int n = 10; n <= 15; ++n)
		cout << "n = " << n << ", n^2 = " << square(n)
			<< endl;
	return 0;
}


