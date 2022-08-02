// element appearing more than n/2 times
//naive
#include <iostream>
#include <cmath>
using namespace std;


int findMajority(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		int count = 1;

		for(int j = i + 1; j < n; j++)
		{
			if(arr[i] == arr[j])
				count++;
		}

		if(count > n / 2)
			return i;
	}

	return -1;
}



int main() {
	
     int arr[] = {8, 7, 6, 8, 6, 6, 6, 6}, n = 8;

     cout<<findMajority(arr, n);
    
}

//efficient
#include <iostream>
#include <cmath>
using namespace std;


int findMajority(int arr[], int n)
{
	int res = 0, count = 1;

    	for(int i = 1; i < n; i++)
    	{
    		if(arr[res] == arr[i])
    			count++;
    		else 
    			count --;

    		if(count == 0)
    		{
    			res = i; count = 1;
    		}
    	}

    	count = 0;

    	for(int i = 0; i < n; i++)
    		if(arr[res] == arr[i])
    			count++;

    	if(count <= n /2)
    		res = -1;

    	return res; 
}



int main() {
	
     int arr[] = {8, 8, 6, 6, 6, 4, 6}, n = 7;

     cout<<findMajority(arr, n);
    
}

// element appearing more than n/3 times
// O(n) time and O(1) space
#include <bits/stdc++.h>
using namespace std;

vector < int > majorityElement(int nums[], int n) {
  int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
  for (i = 0; i < n; i++) 
  {
    if (nums[i] == num1)
    {
		count1++;
	}  
    else if (nums[i] == num2)
    {
		count2++;
	}
    else if (count1 == 0) 
	{
      num1 = nums[i];
      count1 = 1;
    }
	else if (count2 == 0) 
	{
      num2 = nums[i];
      count2 = 1;
    } 
	else 
	{
      count1--;
      count2--;
    }
  }
  vector < int > ans;

  count1 = count2 = 0;
  for (i = 0; i < n; i++) 
  {
    if (nums[i] == num1)
      count1++;
    else if (nums[i] == num2)
      count2++;
  }

  if (count1 > n / 3)
    ans.push_back(num1);
  if (count2 > n / 3)
    ans.push_back(num2);

  return ans;
}

int main() {
  int arr[] = {1,2,2,3,2};
  vector < int > majority;
  majority = majorityElement(arr, 5);
  cout << "The majority element is ";

  for (auto it: majority) 
  {
    cout << it << " ";
  }
}