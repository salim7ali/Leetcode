// https://leetcode.com/problems/search-in-rotated-sorted-array/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getPivotIndex(vector<int>& nums){
        int left = 0;
        int right = nums.size()-1;
        int mid = floor((right-left)/2); 

        // no pivot
        if(nums[left]<nums[mid] && nums[mid]<nums[right])
            return -1;
        // has pivot
        while (left<right && left!=mid)
        {
            // check right
            if(nums[left]<nums[mid] && nums[mid]>nums[right]){
                left = mid;
                mid = left + floor((right-left)/2); 
            // check left 
            }else if(nums[left]>nums[mid] && nums[mid]<nums[right]){
                right = mid;
                mid =  left + floor((right-left)/2); 
            }
        }
        return mid;
    }

    int search(vector<int>& nums, int target) {
        cout<<getPivotIndex(nums);
    }
};