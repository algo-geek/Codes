#include <iostream>
#include <string.h>
using namespace std;


int getCount(int coins[], int n, int sum)
{
    int dp[sum+1][n+1];
    
    for(int i=0;i<=n;i++)
    {
        dp[0][i]=1;
    }
    
    for(int j=0;j<=sum;j++)
    {
        dp[j][0]=0;
    }
    
    for(int i=1;i<=sum;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j] = dp[i][j-1];
            
            if(coins[j-1]<=i)
            dp[i][j]+=dp[i-coins[j-1]][j];
        }
    }
    
    return dp[sum][n];
    
}

int main() {
	
	
int coins[]={1, 2, 3}, sum=4, n=3;

cout<<getCount(coins, n, sum);
	

}

// O(n) space
int count( int S[], int m, int n )		
{		
// table[i] will be storing the number of solutions for		
// value i. We need n+1 rows as the table is constructed		
// in bottom up manner using the base case (n = 0)		
int table[n+1];		
memset(table, 0, sizeof(table));		
table[0] = 1;		
// Pick all coins one by one and update the table[] values		
// after the index greater than or equal to the value of the		
// picked coin		
for(int i=0; i<m; i++)		
for(int j=S[i]; j<=n; j++)		
table[j] += table[j-S[i]];		
return table[n];		
}		
