// https://leetcode.com/problems/online-stock-span/

#include<bits/stdc++.h>
using namespace std;

vector<int> stockSpan(vector<int> &nums){
    stack<pair<int, int>> stackPair;
    vector<int> result(nums.size(), 1);

    for(int i=0; i<nums.size(); i++){
        if(stackPair.empty())
            stackPair.push({nums[i], i});
        else{
            if(stackPair.top().first > nums[i])
                stackPair.push({nums[i], i});
            else{// <=
                int currSpan = result[i];
                while (!stackPair.empty() && stackPair.top().first <=nums[i]){
                    currSpan += result[stackPair.top().second];
                    stackPair.pop();
                }
                result[i] = currSpan;
                stackPair.push({nums[i], i});
            }
        }
    }
    return result;
}

int main(){
    vector<int> nums = {100, 80,60, 60, 70, 60, 75, 85};
    vector<int> result = stockSpan(nums);

    for(int num: result)
        cout<<num<<" ";
    cout<<"\n";
}