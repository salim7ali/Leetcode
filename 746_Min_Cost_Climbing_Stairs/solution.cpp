#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostFind(vector<int> &cost, vector<int> &dp, int currIndex){
        int prevIndex = currIndex-1;
        int prevPrevIndex = currIndex-2;
        
        if(dp[prevIndex] == INT_MIN ){
            dp[prevIndex] = minCostFind(cost, dp, prevIndex);
        }
        if(dp[prevPrevIndex] == INT_MIN ){
            dp[prevPrevIndex] = minCostFind(cost, dp, prevPrevIndex);
        }

        if(currIndex == cost.size())
            return min(dp[prevIndex], dp[prevPrevIndex]);    

        return min(cost[currIndex]+dp[prevIndex], cost[currIndex]+dp[prevPrevIndex]);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, INT_MIN);
        dp[0] = cost[0];
        dp[1] = cost[1];

        int minCost = minCostFind(cost, dp, cost.size());

        for(int i=0; i<dp.size(); i++){
            cout<<dp[i]<<" ";
        }cout<<"\n";

        return minCost;
        // return dp[cost.size()];

    }
};