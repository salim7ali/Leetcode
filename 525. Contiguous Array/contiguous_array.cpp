// https://leetcode.com/problems/contiguous-array/

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    int findMaxLength(vector<int>& nums) {
        vector<int> prefixSum(nums.size(), 0);
        unordered_map<int, vector<int>> hash_map;
        hash_map[0].push_back(-1);

        int currentSum=0;
        // forward pass
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0)
                currentSum -= 1;
            else  // nums[i] == 1
                currentSum += 1;
            prefixSum[i] = currentSum;

            hash_map[prefixSum[i]].push_back(i);
        }

        if(hash_map[0].size()==1)
            hash_map[0].push_back(-1);

        int max_subarray = 0;
        for(auto ele: hash_map){
            int lastIndexOfKey = ele.second.size()-1;
            if(ele.second[lastIndexOfKey] - ele.second[0] > max_subarray)
                max_subarray = ele.second[lastIndexOfKey] - ele.second[0];
        }

        return max_subarray;
    }
};