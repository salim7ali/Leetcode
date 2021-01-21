class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int sum =0,low=0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i-1]> prices[i]){
                if(i>=2)
                    sum += prices[i-1]-prices[low];
                low = i;
            }else if(i==prices.size()-1 && prices[i-1]<= prices[i])
                sum += prices[i]-prices[low];
        }
        return sum;
    }
};