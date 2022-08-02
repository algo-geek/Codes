#include <bits/stdc++.h>
using namespace std;

class petrolPump {
public:
	int petrol;
	int distance;
};


int printTour(petrolPump p[], int n)
{
	int start = 0, prev = 0;
	int curr = 0;
	for (int i = 0; i < n; i++) 
	{
		curr += p[i].petrol - p[i].distance;
		if (curr < 0) 
        {
			start = i + 1;
			prev += curr;
			curr = 0;
		}
	}
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
