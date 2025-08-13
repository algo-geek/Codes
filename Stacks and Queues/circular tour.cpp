// want to find the starting petrol pump index from which a truck can complete a circular tour.


#include <bits/stdc++.h>
using namespace std;

class petrolPump {
public:
	int petrol;
	int distance;
};


int printTour(petrolPump p[], int n)
{
	int start = 0; // Starting petrol pump index
	int prev = 0; // Deficit petrol when current surplus goes negative
	int curr = 0; // Current surplus petrol
	for (int i = 0; i < n; i++) 
	{
		curr += p[i].petrol - p[i].distance;

		// If current surplus is negative, can't start from previous start
		if (curr < 0) 
        {
			start = i + 1;  // Change start to next pump
			prev += curr; // Add negative surplus to deficit
			curr = 0; // Reset current surplus
		}
	}
	 // Check if overall petrol is enough to complete the tour
	return (curr + prev >= 0) ? start : -1;
}

int main()
{
	petrolPump arr[] = { { 6, 4 }, { 3, 6 }, { 7, 3 } };

	int n = sizeof(arr) / sizeof(arr[0]);
	int start = printTour(arr, n);

	(start == -1) ? cout << "No solution" : cout << "Start = " << start;

	return 0;
}
