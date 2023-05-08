// solving after a long time
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1, vector<int> (amount+1, INT_MAX));

        //  amount=0 column needs 0 coins 
        for(int i=0; i<dp.size(); i++){ 
            dp[i][0] = 0;
        }

        for(int i=1; i<dp.size(); i++){
            for(int j=1; j<dp[0].size(); j++){
                // coins[i-1] as coins vector is indexed 0, 1, 2..
                //                                      [1, 2, 5..]
                int coinsOnTakingCurrCoin = 1 + dp[i][j - coins[i-1]];
                int coinsOnRejectingCurrCoin = dp[i-1][j];
                
                dp[i][j] = min(coinsOnRejectingCurrCoin, coinsOnTakingCurrCoin);
            }
        }

        if(dp[dp.size()-1][dp[0].size()-1] >=0){
            return dp[dp.size()-1][dp[0].size()-1];
        }
        
        return -1;

    }
};