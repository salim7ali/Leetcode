// https://leetcode.com/problems/search-in-rotated-sorted-array/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getPivotIndex(vector<int>& nums){
        int left = 0;
        int right = nums.size()-1;
        int mid = floor((right-left)/2); 

        // has pivot
        while (left<right)
        {
            if(nums[left]<nums[mid] && nums[mid]<nums[right])
                return right;
            // pivot found
            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])
                return mid;
            // check right
            if(nums[left]<nums[mid] && nums[mid]>nums[right]){
                left = mid+1;
                mid = left + floor((right-left)/2); 
            // check left 
            }else if(nums[left]>nums[mid] && nums[mid]<nums[right]){
                right = mid-1;
                mid =  left + floor((right-left)/2); 
            }
        }
        return mid;
    }

    int myBinarySearchRetIndex(vector<int> &nums, int element, int l, int r){

        while (l<r)
        {
            int mid = l+floor((r-l)/2);
            if(nums[mid]==element)
                return mid;
            else if(element<nums[mid]){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivot = getPivotIndex(nums);
        
        if(target<=nums[pivot])
            return myBinarySearchRetIndex(nums, target, 0, pivot);
        else
            return myBinarySearchRetIndex(nums, target, pivot+1, nums.size()-1);
    }
};