//naive //time:theta(sqrt(x))
#include <iostream>
using namespace std;

int sqRootFloor(int x)
{
	int i = 1;

	while(i * i <= x)
		i++;

	return i - 1;
}

int main() {
    

   cout << sqRootFloor(15);

	return 0;
}

//efficient
#include <iostream>
using namespace std;

int sqRootFloor(int x)
{
	int low = 1, high = x, ans = -1;

	while(low <= high)
	{
		int mid = (low + high) / 2;

		int mSq = mid * mid;

		if(mSq == x)
			return mid;
		else if(mSq > x)
			high = mid - 1;
		else
		{
			low = mid + 1;
			ans = mid;
		}
	}

	return ans;
}

int main() {
    

   cout << sqRootFloor(10);

	return 0;
}