#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int coins[] = {9, 6, 5, 1};
    int num_coins = 4;
    int amount = 11;
    
    int dp[12];
    int used[12];
    for (int i = 0; i <= amount; ++i) {
        dp[i] = INT_MAX;
        used[i] = -1;
    }
    dp[0] = 0;
    
    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < num_coins; ++j) {
            int coin = coins[j];
            if (i >= coin && dp[i - coin] != INT_MAX) {
                if (dp[i] > dp[i - coin] + 1) {
                    dp[i] = dp[i - coin] + 1;
                    used[i] = coin;
                }
            }
        }
    }
    
    if (dp[amount] == INT_MAX) {
        cout << "No solution" << endl;
    } else {
        cout << "Minimum coins: " << dp[amount] << endl;
        cout << "Coins used: ";
        int result[12];
        int idx = 0;
        int current = amount;
        while (current > 0) {
            int coin = used[current];
            result[idx++] = coin;
            current -= coin;
        }
        for (int k = 0; k < idx; ++k) {
            cout << result[k] << " ";
        }
        cout << endl;
    }
    
    return 0;
}