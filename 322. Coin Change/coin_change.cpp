// https://leetcode.com/problems/coin-change/
#include<bits/stdc++.h>
using namespace std;

// first example case
//coins                   amount
//      0   1   2   3   4   5   6   7   8   9   10  11
// 0
// 1
// 2
// 3

class Solution {
public:
    int coinChange(vector<int>& coins, int target_amount) {
        vector<vector<int>> dp(coins.size()+1, vector<int> (target_amount+1, INT_MAX));

        for(int row=0; row<dp.size(); row++)
            dp[row][0] = 0;

        for(int curr_coin_index=1; curr_coin_index<dp.size(); curr_coin_index++){
            for(int curr_amount=1; curr_amount<dp[0].size(); curr_amount++){

                if(coins[curr_coin_index-1] <= curr_amount){
                    //                                   min(without,with)
                    dp[curr_coin_index][curr_amount] = min(dp[curr_coin_index-1][curr_amount], 
                    1 + dp[curr_amount-coins[curr_coin_index-1]][curr_coin_index]);
                }else{
                    dp[curr_coin_index][curr_amount] = dp[curr_coin_index-1][curr_amount];
                }
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};

int main(){
    //                   0 1 2
    vector<int> coins = {1,2,5};
    Solution obj1;
    cout<<obj1.coinChange(coins, 11)<<"\n";
}