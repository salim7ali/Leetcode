// https://leetcode.com/problems/median-of-two-sorted-arrays/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int findMid(){
    //     while(left<=right){
    //         if(singleArr){
    //             mid = left+floor((right-left)/2);
    //         }

    //     }

    // }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // bool singleArr=false;
        // int left=0, right=nums2.size()-1, mid=floor((right-left)/2);

        int resultArrSize= nums1.size()+nums2.size();
        int halfArrSize=resultArrSize/2;
        int l1, l2, r1, r2;
        for(int pivot=0; pivot<nums1.size(); pivot++){
            l1=nums1[pivot-1];
            if(pivot==0)
                l1=INT_MIN;
            r1=nums1[pivot];
            l2=nums2[halfArrSize-pivot-2];
            r2=nums2[halfArrSize-pivot-1];
            if(halfArrSize-pivot-1 == nums2.size())
                r2=INT_MAX;

            if(l2<r1 && l1<r2){
                return (max(l1, l2) + max(r1, r2))/2;
            }
            // }else if(l2>=r1){
                
            // }else{// l1>=r2

            // }  
        }

        // while(1){
        //     mid = findMid(left, right, singleArr);

        // }

    }
};

int main(){
    vector<int> nums1 ={1, 5, 11, 12, 15, 20, 51, 99};
    vector<int> nums2 ={9, 16, 17, 26};
    Solution obj;
    cout<<obj.findMedianSortedArrays(nums1, nums2)<<"\n";
}