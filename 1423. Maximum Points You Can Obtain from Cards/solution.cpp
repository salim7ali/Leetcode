// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int currSum=0;
        int i;
        for(i=0; i<k; i++){
            currSum += cardPoints[i];
        }

        int maxScore = currSum;
        int j;
        while(i>0){
            --i;
            j = cardPoints.size() + i -k;
            cout<<i<<" "<<j<<"\n";

            currSum -= cardPoints[i];
            currSum += cardPoints[j];
            if(currSum>maxScore)
                maxScore = currSum;
        }
        return maxScore;
    }
};

int main(){
    vector<int> cardPoints={1,2,3,4,5,6,1};
    
    Solution obj1;
    cout<<obj1.maxScore(cardPoints, 3)<<"\n";
}