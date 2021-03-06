// https://leetcode.com/problems/next-permutation/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        // finding peak from least significant digit
        int peak_index;
        for(peak_index=nums.size()-1; peak_index>=1; peak_index--){
            if(nums[peak_index]>nums[peak_index-1])
                break;
        }
        // decreasing order input
        if(peak_index==0){
            sort(nums.begin(), nums.end());
            return;
        }

        // finding min peak
        int min_peak_val =nums[peak_index];
        int min_peak_index=peak_index, i;
        for( i=peak_index+1; i<nums.size(); i++){
            if(nums[peak_index-1]<nums[i] && nums[i]<min_peak_val)
                min_peak_index=i;
                min_peak_val=nums[i];
        }

        swap(nums[peak_index-1], nums[min_peak_index]);

        sort(nums.begin()+peak_index, nums.end());
    }
};

void disp(vector<int> nums){
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }cout<<"\n";
}
int main(){
    Solution obj;
    vector<int> nums = {5, 4, 3, 2, 1};

    obj.nextPermutation(nums);
    disp(nums);
    obj.nextPermutation(nums);
    disp(nums);
    obj.nextPermutation(nums);
    disp(nums);
    obj.nextPermutation(nums);
    disp(nums);
    
}