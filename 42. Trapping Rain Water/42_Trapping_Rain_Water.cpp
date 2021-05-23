// https://leetcode.com/problems/trapping-rain-water/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    // <height, index>
    vector<int> left_to_right_inc_peaks;
    vector<int> right_to_left_inc_peaks;
public:
    void display(vector<int> vec){
        for(int i=0; i<vec.size(); i++){
            cout<<vec[i]<<" ";
        }cout<<"\n";
    }

    vector<int> gen_peak_list(bool isLeft, vector<int> &height){
        vector<int> peak_list(height.size());

        int curr_peak = INT_MIN;
        if(isLeft){
            for(int i=0; i<height.size(); i++){
                peak_list[i] = curr_peak;
                if(height[i]>curr_peak)
                    curr_peak = height[i];
            }
        }else{
            for(int i=height.size()-1; i>=0; i--){
                peak_list[i] = curr_peak;
                if(height[i]>curr_peak)
                    curr_peak = height[i];
            }
        }
        return peak_list;
    }

    int trap(vector<int>& height) {

        left_to_right_inc_peaks = gen_peak_list(true, height);
        right_to_left_inc_peaks = gen_peak_list(false, height);

        // display(left_to_right_inc_peaks);
        // display(right_to_left_inc_peaks);
        
        int total_water_blocks = 0;
        // (int) is required as edge case exists when height vector is empty. As height.size() is unsingned long,
        //  it returns 18446744073709551615 when height.size()-1 is used on empty vector due to underflow.
        for(int i=1; i<(int)height.size()-1; i++){
            int curr_water_height = min(left_to_right_inc_peaks[i], right_to_left_inc_peaks[i]);

            if(curr_water_height-height[i] > 0)
                total_water_blocks += (curr_water_height-height[i]);
        }
        
        return total_water_blocks;
    }
};

int main(){
    vector<int> test_vec1 = {7, 1, 4, 2, 0, 3, 2, 5, 0};
    Solution obj1;
    cout<<obj1.trap(test_vec1)<<"\n";

    vector<int> test_vec2 = {1,2,4,1,2,6};
    Solution obj2;
    cout<<obj2.trap(test_vec2)<<"\n";

    vector<int> test_vec3 = {};
    Solution obj3;
    cout<<obj3.trap(test_vec3)<<"\n";

}