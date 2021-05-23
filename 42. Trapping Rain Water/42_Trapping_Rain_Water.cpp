// https://leetcode.com/problems/trapping-rain-water/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    // <height, index>
    vector<int> left_to_right_inc_peaks;
    vector<int> right_to_left_inc_peaks;
    vector<int> water_level_list;
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

        this->left_to_right_inc_peaks = gen_peak_list(true, height);
        this->right_to_left_inc_peaks = gen_peak_list(false, height);

        display(left_to_right_inc_peaks);
        display(right_to_left_inc_peaks);
        
        int total_water_blocks = 0;
        for(int i=1; i<height.size()-1; i++){
            int curr_water_height = min(left_to_right_inc_peaks[i], right_to_left_inc_peaks[i]);

            if(curr_water_height-height[i] > 0)
                total_water_blocks += (curr_water_height-height[i]);
        }
        
        return total_water_blocks;
    }
};

int main(){
    vector<int> test_vec = {7, 1, 4, 2, 0, 3, 2, 5, 0};
    // vector<int> test_vec = {1,2,4,1,2,6};
    
    Solution obj;
    cout<<obj.trap(test_vec)<<"\n";
}