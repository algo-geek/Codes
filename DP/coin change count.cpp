// count all combinations of coins to make a given value sum.  
// infinite supply of each type of coin. 


int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<long>dp(amount+1,0);
        dp[0]=1;
        long MOD=1e10;
        for(int i=0;i<n;i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j]= (dp[j] + dp[j-coins[i]])%MOD;
            }
        }
        return dp[amount];
    }

int main() {
	
	
int coins[]={1, 2, 3}, sum=4, n=3;

cout<<getCount(coins, n, sum);
	

}
		
