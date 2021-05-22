// https://leetcode.com/problems/trapping-rain-water/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    // <height, index>
    vector<pair<int, int>> left_to_right_inc_peaks;
    vector<pair<int, int>> right_to_left_inc_peaks;
    vector<int> water_level_list;
public:
    void display(vector<pair<int, int>> vec){
        for(int i=0; i<vec.size(); i++){
            cout<<"("<<vec[i].first<<","<<vec[i].second<<") ";
        }cout<<"\n";
    }

    vector<pair<int, int>> gen_peak_list(bool isLeft, vector<int> &height){
        vector<pair<int, int>> peak_list(height.size());

        pair<int, int> curr_peak ={INT_MIN, 0};
        if(isLeft){
            for(int i=0; i<height.size(); i++){
                if(height[i]>curr_peak.first){
                    curr_peak.first = height[i];
                    curr_peak.second = i;
                }
                peak_list[i].second = curr_peak.second;
                peak_list[i].first = curr_peak.first;
            }
        }else{
            for(int i=height.size()-1; i>=0; i--){
                if(height[i]>curr_peak.first){
                    curr_peak.first = height[i];
                    curr_peak.second = i;
                }
                peak_list[i].second = curr_peak.second;
                peak_list[i].first = curr_peak.first;
            }
        }
        return peak_list;
    }

    int trap(vector<int>& height) {

        this->left_to_right_inc_peaks = gen_peak_list(true, height);
        this->right_to_left_inc_peaks = gen_peak_list(false, height);

        multiset<pair<int, int>> multi_set;
        for(int i=0; i<height.size(); i++){
            multi_set.insert({height[i], i});
        }

        while(multi_set.empty()==false){
            int curr_low_height = (*(multi_set.begin())).first;
            int curr_low_index = (*(multi_set.begin())).second;
            multi_set.erase(multi_set.begin());

            int curr_height = curr_low_height;
            // increasing height until left or right peak doesn't exist
            while(curr_height>=(left_to_right_inc_peaks[curr_low_index-1]).first  && 
            curr_height>=(right_to_left_inc_peaks[curr_low_index+1]).first){
                curr_height += 1;
            }

            water_level_list.resize(height.size());
            // left side
            for(int i=curr_low_index; i!=(left_to_right_inc_peaks[curr_low_index-1]).second; i--){
                water_level_list[i] = curr_height-curr_low_height;    
            }
            // right side
            for(int i=curr_low_index; i!=(right_to_left_inc_peaks[curr_low_index+1]).second; i--){
                water_level_list[i] = curr_height-curr_low_height;    
            }
        }


        int result_sum = 0;
        for(int i=0; i<water_level_list.size(); i++)
            result_sum += water_level_list[i];
        return result_sum;
    }
};

int main(){
    vector<int> test_vec = {7, 1, 4, 2, 0, 3, 2, 5, 0};
    
    Solution obj;
    cout<<obj.trap(test_vec)<<"\n";
}