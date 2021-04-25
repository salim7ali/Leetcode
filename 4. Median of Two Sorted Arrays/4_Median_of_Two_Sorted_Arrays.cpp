// https://leetcode.com/problems/median-of-two-sorted-arrays/
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
        for(r1=0; r1<nums1.size(); r1++){
            l1=r1-1;
            l2=halfArrSize-r1;
            r2=l2+1;

            if(l2<r1 && l1<r2){
                return avg(max(l1, l2), max(r1, r2));
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
    vector<int> nums2 ={9, 16, 17, 26, 57};
    Solution obj;
    cout<<obj.findMedianSortedArrays(nums1, nums2)<<"\n";
}