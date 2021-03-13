// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/submissions/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    bool hasPrimeSetBits(int num){
        int count=0;
        while(num){
            count += (num&1);
            num>>=1;
        }
        // since R<=10^6<=2^20
        return ((count==2)||(count==3)||(count==5)||(count==7)||(count==11)||
        (count==13)||(count==17)||(count==19));
    }
    
    int countPrimeSetBits(int L, int R) {
        int resCount = 0;
        for(int i=L; i<=R; i++)
            if(hasPrimeSetBits(i))
                resCount += 1; 
        return resCount;
    }
};

int main(){
    Solution obj;
    cout<<obj.countPrimeSetBits(842, 888);
}