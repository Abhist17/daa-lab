/*Dynamic Programming on Stock Trading
Max Profit with K Transactions (Portfolio Optimization)
Problem Statement
You are given stock prices over N days:
Prices = {10, 22, 5, 75, 65, 80}
K = 2 transactions allowed
Enter N (Number of Days), K (Number of transition) and Prices from the keyboard.
Each transaction = Buy + Sell*/



// Total no of days = 6 
// Total no of transactions = 2
// Prices = {10, 22, 5, 75, 65, 80} 


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// here the dynamic program approach to find the max profit with k transactions allowed of n days of stock prices.

int maxProfitkTransactions(int k, vector<int>& prices) {
    int n = prices.size();
    if (n == 0 || k == 0) return 0;


    vector<vector<int>> dp(k + 1, vector<int>(n, 0));
    for (int i = 1; i <= k; i++) {
        int maxProfit = -prices[0];
        for (int j = 1; j < n; j++) {
            maxProfit = max(maxProfit, dp[i - 1][j - 1] - prices[j - 1]);
            dp[i][j] = max(dp[i][j - 1], maxProfit + prices[j]); //dp[i][j] = max profit using i transa from day 0 to day j

            //base cases = dp[0][j = 0 tran = 0 profit while dp [i][0] = only 1 day for cant sell = 0 profit 
        }
    }
    return dp[k][n - 1];
}

//  creating a vector of max profit using at most i transaction up to 6 days 


int main() 
{
    int n, k;
    cout << "Enter the total no of days: ";
    cin >> n;
    cout << "enter the total no of transact allowed (K):";
    cin >> k;
    vector<int> prices (n);
    cout << "Prices you want to enter for " << n << " days: ";
    


    for (int i = 0; i < n; i++)
    {
        cout << "Day " << i + 1 << ": ";
        cin >> prices[i];

    }
    int result = maxProfitkTransactions(k, prices);
    cout << "Result: " << result;
    cout << "Max profit with " << k << " transactions: " << result << endl;

    return 0;
}


