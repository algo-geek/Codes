// naive // sorted arrays // print all common elements
// time & space: O(n1+n2+n3)
#include <bits/stdc++.h>
using namespace std;

void findCommon(int a[], int b[], int c[], int n1, int n2,
				int n3)
{
	unordered_set<int> uset, uset2, uset3;
	for (int i = 0; i < n1; i++) {
		uset.insert(a[i]);
	}
	for (int i = 0; i < n2; i++) {
		uset2.insert(b[i]);
	}

	for (int i = 0; i < n3; i++) {
		if (uset.find(c[i]) != uset.end()
			&& uset2.find(c[i]) != uset.end()) {
			// using a 3rd set to prevent duplicates
			if (uset3.find(c[i]) == uset3.end())
				cout << c[i] << " ";
			uset3.insert(c[i]);
		}
	}
}

int main()
{
	int ar1[] = { 1, 5, 10, 20, 40, 80 };
	int ar2[] = { 6, 7, 20, 80, 100 };
	int ar3[] = { 3, 4, 15, 20, 30, 70, 80, 120 };
	int n1 = sizeof(ar1) / sizeof(ar1[0]);
	int n2 = sizeof(ar2) / sizeof(ar2[0]);
	int n3 = sizeof(ar3) / sizeof(ar3[0]);

	cout << "Common Elements are " << endl;
	findCommon(ar1, ar2, ar3, n1, n2, n3);
	return 0;
}

// efficient
// time: O(n1+n2+n3)
// space: O(1)

#include <bits/stdc++.h>
using namespace std;

void findCommon(int ar1[], int ar2[], int ar3[], int n1,
				int n2, int n3)
{
    // no duplicates

    // int i = 0, j = 0, k = 0;
    // while (i < n1 && j < n2 && k < n3) 
    // {
    //     if (ar1[i] == ar2[j] && ar2[j] == ar3[k]) 
    //     {
    //         cout << ar1[i] << " ";
    //         i++;
    //         j++;
    //         k++;
    //     }
    //     else if (ar1[i] < ar2[j])
    //         i++;
    //     else if (ar2[j] < ar3[k])
    //         j++;
    //     else
    //         k++;
    // }

    // duplicates involved
	int i = 0, j = 0, k = 0;
	int prev1, prev2, prev3;
	prev1 = prev2 = prev3 = INT_MIN;

	while (i < n1 && j < n2 && k < n3) 
    {
        // to skip repeated elements occuring continuously as array is sorted
		while (ar1[i] == prev1 && i < n1)
			i++;

		while (ar2[j] == prev2 && j < n2)
			j++;

		while (ar3[k] == prev3 && k < n3)
			k++;


		if (ar1[i] == ar2[j] && ar2[j] == ar3[k]) 
        {
			cout << ar1[i] << " ";
			prev1 = ar1[i];
			prev2 = ar2[j];
			prev3 = ar3[k];
			i++;
			j++;
			k++;
		}
		else if (ar1[i] < ar2[j]) 
        {
			prev1 = ar1[i];
			i++;
		}
		else if (ar2[j] < ar3[k]) 
        {
			prev2 = ar2[j];
			j++;
		}
		else 
        {
			prev3 = ar3[k];
			k++;
		}
	}
}


int main()
{
	int ar1[] = { 1, 5, 10, 20, 40, 80, 80 };
	int ar2[] = { 6, 7, 20, 80, 80, 100 };
	int ar3[] = { 3, 4, 15, 20, 30, 70, 80, 80, 120 };
	int n1 = sizeof(ar1) / sizeof(ar1[0]);
	int n2 = sizeof(ar2) / sizeof(ar2[0]);
	int n3 = sizeof(ar3) / sizeof(ar3[0]);

	cout << "Common Elements are ";
	findCommon(ar1, ar2, ar3, n1, n2, n3);
	return 0;
}
