// memoization // time: theta(mn) 
#include<bits/stdc++.h>
using namespace std;

int memo[1000][1000];

int lcs(string s1, string s2, int n, int m)
{
    if(memo[n][m]!=-1)
    return memo[n][m];

    if(m==0 || n==0)
    memo[n][m]=0;
    else
    {
        if(s1[n-1]==s2[m-1])
        memo[n][m]=1+lcs(s1, s2, n-1, m-1);
        else
        memo[n][m]=max(lcs(s1,s2,n-1,m), lcs(s1,s2,n,m-1));
    }
    

    return memo[n][m];
}

int main()
{
    string s1="AXYZ", s2="BAZ";
	
	int n = 4, m = 3;
    
	
	memset(memo,-1,sizeof(memo));
	
	cout<<lcs(s1,s2,n,m);
}

//tabular
#include <iostream>
#include <string.h>
using namespace std;


int lcs(string s1, string s2)
{
    int m = s1.length(), n = s2.length();
    
    int dp[m+1][n+1];
    
    for(int i=0;i<=m;i++)
        dp[i][0]=0;
    
    for(int j=0;j<=n;j++)
        dp[0][j]=0;
        
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    return dp[m][n];
    
}

int main() {
	
	
	string s1="AXYZ", s2="BAZ";
	
	
	cout<<lcs(s1,s2);
	

}

// printing LCS
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

void lcs(char* X, char* Y, int m, int n)
{
	int L[m + 1][n + 1];

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	int index = L[m][n];

	// character array to store the lcs string
	char lcs[index + 1];
	lcs[index] = '\0'; // Set the terminating character

	// Start from the right-most-bottom-most corner and
	// one by one store characters in lcs[]
	int i = m, j = n;
	while (i > 0 && j > 0) {
		// If current character in X[] and Y are same, then
		// current character is part of LCS
		if (X[i - 1] == Y[j - 1]) {
			lcs[index - 1] = X[i - 1]; 
			i--;
			j--;
			index--; 
		}

		// If not same, then find the larger of two and
		// go in the direction of larger value
		else if (L[i - 1][j] > L[i][j - 1])
			i--;
		else
			j--;
	}

	cout << "LCS of " << X << " and " << Y << " is " << lcs;
}

int main()
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";
	int m = strlen(X);
	int n = strlen(Y);
	lcs(X, Y, m, n);
	return 0;
}
