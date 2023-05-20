class Solution {
public:
    void minCostFind(vector<int> &cost, vector<int> &dp, int currIndex){
        // needs fixing
        if(currIndex ==0 || currIndex ==1){
            dp[currIndex] = cost[currIndex];
            return;
        } 
        dp[currIndex] = min(cost[currIndex]+dp[currIndex-1], cost[currIndex]+dp[currIndex-2]);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1);

        minCostFind(cost, dp, cost.size());
        return dp[cost.size()];

    }
};