#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int currMax = nums[0];
        multiset<int> MS;

        MS.insert(nums[0]);
        for(int i=1; i<k; i++){
            MS.insert(nums[i]);
            currMax = max(currMax, nums[i]);
        }
        result.push_back(*(MS.rbegin()));

        for(auto ele: MS){
            cout<<ele<<" ";
        }cout<<"\n";

        for(int i=k; i<nums.size(); i++){
            int newNum = nums[i];
            int oldNum = nums[i-k];

            MS.erase(MS.find(oldNum));
            MS.insert(newNum);
            result.push_back(*(MS.rbegin()));

        }
        return result;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k=3;
    
    vector<int> res;
    res = obj.maxSlidingWindow(nums, k);
    
    for(auto ele: res){
            cout<<ele<<" ";
        }cout<<"\n";

}