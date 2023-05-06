// https://leetcode.com/problems/search-in-rotated-sorted-array/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findIndex(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        // has pivot
        while (left <= right)
        {
            mid = left + floor((right - left) / 2);

            if(nums[mid]==target)
                return mid;
            //  left side increasing
            if(nums[left]<=nums[mid]){
                //  element lies inbetween it or not
                if( nums[left]<=target && target<=nums[mid])
                    right = mid-1;
                else
                    left = mid+1;
            }else{  // right side increasing
                //  element lies inbetween it or not
                if(nums[mid]<=target && target<=nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        return -1;
    }

    int myBinarySearchRetIndex(vector<int> &nums, int element, int l, int r)
    {

        while (l <= r)
        {
            int mid = l + floor((r - l) / 2);
            if (nums[mid] == element)
                return mid;
            else if (element < nums[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        return findIndex(nums, target);

        // if ((nums[0] <= target) && (target <= nums[pivot]))
        //     return myBinarySearchRetIndex(nums, target, 0, pivot);
        // else
        //     return myBinarySearchRetIndex(nums, target, pivot + 1, nums.size() - 1);
    }
};

void main()
{
    vector<int> nums = {3, 1};
    Solution obj;

    obj.search(nums, 0);
}