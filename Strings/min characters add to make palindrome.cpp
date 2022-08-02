// min characters to be added at front to make a palindrome
// naive // O(n^2)
#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string s)
{
	int l = s.length();
	int j;
	
	for(int i = 0, j = l - 1; i <= j; i++, j--)
	{
		if(s[i] != s[j])
			return false;
	}
	return true;
}

int main()
{
	string s = "BABABAA";
	int cnt = 0;
	int flag = 0;
	
	while(s.length()>0)
	{
		if(ispalindrome(s))
		{
			flag = 1;
			break;
		}
		else
		{
		cnt++;
		
		// erase the last element of the string
		s.erase(s.begin() + s.length() - 1);
		}
	}
	
	if(flag)
		cout << cnt;
}

// O(n) time & space
