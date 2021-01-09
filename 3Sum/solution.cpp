// https://leetcode.com/submissions/detail/440588427/

class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3)
            return result;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-2; i++){
            if(i==0 || (nums[i] != nums[i-1])){
                int j=i+1, k=nums.size()-1;
                
                while(j<k){
                    int currSum = nums[i]+nums[j]+nums[k];
                    if(currSum == 0){
                        result.push_back({nums[i], nums[j], nums[k]});
                        while(j<k && nums[j]==nums[j+1]) j++;
                        while(j<k && nums[k]==nums[k-1]) k--;
                        j += 1;
                        k -= 1;
                    }else if(currSum < 0)
                        j += 1;
                    else
                        k -=1;
                }
            }
        }
        
        return result;
    }
};