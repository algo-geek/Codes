//naive
#include <iostream>
#include <cmath>
using namespace std;


int getWater(int arr[], int n)
{
	int res = 0;

	for(int i = 1; i < n - 1; i++)
	{
		int lMax = arr[i];

		for(int j = 0; j < i; j++)
			lMax = max(lMax, arr[j]);

		int rMax = arr[i];

		for(int j = i + 1; j < n; j++)
			rMax = max(rMax, arr[j]);

		res = res + (min(lMax, rMax) - arr[i]);
	}

	return res;
}


int main() {
	
     int arr[] = {3, 0, 1, 2, 5}, n = 5;

     cout<<getWater(arr, n);
    
}

//efficient //space: O(n)
#include <iostream>
#include <cmath>
using namespace std;


int getWater(int arr[], int n)
{
    int left[n];
    int right[n];
 
    int water = 0;
 
    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);
 
    // Fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);
 

    for (int i = 1; i < n-1; i++)
    {
      int var=min(left[i-1],right[i+1]);
      if(var > arr[i])
      {
        water += var - arr[i];
      }
    }
        
 
    return water;
}


int main() {
	
     int arr[] = {3, 0, 1, 2, 5}, n = 5;

     cout<<getWater(arr, n);
    
}

// O(1) space

#include <iostream>
using namespace std;

int findWater(int arr[], int n)
{
	int result = 0;
	int left_max = 0, right_max = 0;
	int lo = 0, hi = n - 1;

	while (lo <= hi) 
	{
		if (arr[lo] < arr[hi]) 
		{
			if (arr[lo] > left_max)
				left_max = arr[lo];
			else
				result += left_max - arr[lo];

			lo++;
		}
		else 
		{
			if (arr[hi] > right_max)
				right_max = arr[hi];
			else
				result += right_max - arr[hi];

			hi--;
		}
	}

	return result;
}

int main()
{
	int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum water that can be accumulated is "
		<< findWater(arr, n);
}
