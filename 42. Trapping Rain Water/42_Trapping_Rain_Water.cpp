#include<bits/stdc++.h>
using namespace std;

class Solution {
    // <height, index>
    vector<pair<int, int>> left_to_right_inc_peaks;
    vector<pair<int, int>> right_to_left_inc_peaks;
public:
    vector<pair<int, int>> gen_peak_list(bool isLeft, vector<int> &height){
        vector<pair<int, int>> peak_list(height.size());

        pair<int, int> curr_peak ={INT_MIN, 0};
        if(isLeft){
            for(int i=0; i<height.size(); i++){
                if(height[i]>curr_peak.first){
                    curr_peak.first = height[i];
                    peak_list[i].second = i;
                }
                peak_list[i].first = curr_peak.first;
            }
        }else{
            for(int i=height.size()-1; i>=0; i--){
                if(height[i]>curr_peak.first){
                    curr_peak.first = height[i];
                    peak_list[i].second = i;
                }
                peak_list[i].first = curr_peak.first;
            }
        }
        return peak_list;
    }

    int trap(vector<int>& height) {

        this->left_to_right_inc_peaks = gen_peak_list(true, height);
        this->right_to_left_inc_peaks = gen_peak_list(false, height);
    }
};

int main(){

}