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

                int without, with;
                if(coins[curr_coin_index-1] <= curr_amount){
                    without = dp[curr_coin_index-1][curr_amount];

                    // handling int overflow case
                    if(dp[ curr_coin_index ][ curr_amount-coins[curr_coin_index-1] ] == INT_MAX)
                        with = INT_MAX;
                    else
                        with = 1 + dp[ curr_coin_index ][ curr_amount-coins[curr_coin_index-1] ];

                    dp[curr_coin_index][curr_amount] = min(without, with);
                }else{
                    without = dp[curr_coin_index-1][curr_amount];
                    dp[curr_coin_index][curr_amount] = without;
                }
            }
        }
        if(dp[dp.size()-1][dp[0].size()-1] == INT_MAX)
            return -1;
        return dp[dp.size()-1][dp[0].size()-1];
    }
};

int main(){
    //                   0 1 2
    vector<int> coins = {1,2,5};
    Solution obj1;
    cout<<obj1.coinChange(coins, 11)<<"\n";

    coins = {2};
    Solution obj2;
    cout<<obj2.coinChange(coins, 3)<<"\n";

    coins = {1};
    Solution obj3;
    cout<<obj3.coinChange(coins, 0)<<"\n";

    coins = {1};
    Solution obj4;
    cout<<obj4.coinChange(coins, 1)<<"\n";

    coins = {1};
    Solution obj5;
    cout<<obj5.coinChange(coins, 2)<<"\n";
    
}