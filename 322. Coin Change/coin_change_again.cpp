// solving after a long time
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1, vector<int> (amount+1, INT_MAX));

        //  amount=0 column needs 0 coins 
        for(int row=0; row<dp.size(); row++){ 
            dp[row][0] = 0;
        }

        int coinsOnTakingCurrCoin;
        int coinsOnRejectingCurrCoin;
        for(int currCoinIndex=1; currCoinIndex<dp.size(); currCoinIndex++){
            for(int currAmount=1; currAmount<dp[0].size(); currAmount++){
                // coins[currCoinIndex-1] as coins vector is indexed 0, 1, 2..
                //                                      [1, 2, 5..]
                coinsOnTakingCurrCoin = 1 + dp[currCoinIndex][currAmount - coins[currCoinIndex-1]];
                coinsOnRejectingCurrCoin = dp[currCoinIndex-1][currAmount];
                
                dp[currCoinIndex][currAmount] = min(coinsOnRejectingCurrCoin, coinsOnTakingCurrCoin);
            }
        }

        int minCoins = dp[dp.size()-1][dp[0].size()-1];
        if(minCoins == INT_MAX){
            return -1;
        }

        return minCoins;

    }
};