// recursion
// time & space: O(n)
#include <bits/stdc++.h>
using namespace std;

int friendsPairing(int n)
{
    if(n==0 || n==1 || n==2)
    return n;
    
    return friendsPairing(n-1)+friendsPairing(n-2)*(n-1);//vertical + horizontal
}

int main()
{
    cout<<friendsPairing(4)<<endl;
}

// dp
// time & space: O(n)
#include <bits/stdc++.h>
using namespace std;

int countFriendsPairings(int n)
{
	int dp[n + 1];

	for (int i = 0; i <= n; i++) {
		if (i <= 2)
			dp[i] = i;
		else
			dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
	}

	return dp[n];
}

int main()
{
	int n = 4;
	cout << countFriendsPairings(n) << endl;
	return 0;
}

// similar to fibonacci
// time: O(n) // space: O(1)
#include <bits/stdc++.h>
using namespace std;

int countFriendsPairings(int n)
{
	int a = 1, b = 2, c = 0;
	if (n <= 2) {
		return n;
	}
	for (int i = 3; i <= n; i++) 
    {
		c = b + (i - 1) * a;
		a = b;
		b = c;
	}
	return c;
}

int main()
{
	int n = 4;
	cout << countFriendsPairings(n);
	return 0;
}

