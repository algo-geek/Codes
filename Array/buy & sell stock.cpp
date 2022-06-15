// sell a stock in the upcoming days with max profit // infinite transactions
//naive
#include <iostream>
#include <cmath>
using namespace std;


int maxProfit(int price[], int start, int end)
{
	if(end <= start)
		return 0;

	int profit = 0;

	for(int i = start; i < end; i++)
	{
		for(int j = i + 1; j <= end; j++)
		{
			if(price[j] > price[i])
			{
				int curr_profit = price[j] - price[i] 
                                    // left of i
								  + maxProfit(price, start, i - 1)
                                  // right of j
								  + maxProfit(price, j + 1, end);

				profit = max(profit, curr_profit);
			}
		}
	}

	return profit;
}


int main() {
	
      int arr[] = {1, 5, 3, 8, 12}, n = 5;
      // 5-1=4 & 12-3=9 
      // o/p: 3+9=13
      cout<<maxProfit(arr, 0, n - 1);
    
}

//efficient
#include <iostream>
#include <cmath>
using namespace std;


int maxProfit(int price[], int n)
{
	int profit = 0;

	for(int i = 1; i < n; i++)
	{
		if(price[i] > price[i - 1])
			profit += price[i] - price[i -1];
	}

	return profit;

}

// one transaction // efficient
#include <iostream>
using namespace std;

int maxProfit(int prices[], int n)
{
	int buy = prices[0], max_profit = 0;
	for (int i = 1; i < n; i++) {

		// Checking for lowest buy value
		if (buy > prices[i])
			buy = prices[i];

		// Checking for higher profit
		else if (prices[i] - buy > max_profit)
			max_profit = prices[i] - buy;
	}
	return max_profit;
}

int main()
{
	int prices[] = { 7, 1, 5, 6, 4 };
	int n = sizeof(prices) / sizeof(prices[0]);
	int max_profit = maxProfit(prices, n);
	cout << max_profit << endl;
	return 0;
}



int main() {
	
      int arr[] = {1, 5, 3, 8, 12}, n = 5;

      cout<<maxProfit(arr, n);
    
}