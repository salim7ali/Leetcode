#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int first, int second){
        if(second ==0) return first;
        return gcd(second, first%second);
    }
    
    int maxPoints(vector<vector<int>> &points){
        int maxPoints = 0;


        for(int i=0; i<points.size(); i++){
            map<pair<int, int>, int> HM;
            int duplicate = 0;
            for(int j=i+1; j<points.size(); j++){
                int dy = points[i][1] - points[j][1];
                int dx = points[i][0] - points[j][0];

                if(dy==0 && dx==0)
                    duplicate += 1;
                else{
                    int GCD = __gcd(abs(dy), abs(dx));
                    dy /= GCD;
                    dx /= GCD;
                    HM[{dy, dx}] += 1;
                }

            }
            for(auto it: HM){
                maxPoints = max(maxPoints, it.second);
            }
        }
        return maxPoints;
    }
};

int main(){
    
}