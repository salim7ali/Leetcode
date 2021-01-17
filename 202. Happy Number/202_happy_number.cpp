// https://leetcode.com/submissions/detail/444106344/
class Solution {
public:
    int sumOfSquares(int num){
        int sumOSq =0;
        
        while(num){
            sumOSq += pow(num%10, 2);
            num /=10;
        }
        return sumOSq;
    }
    
    bool isHappy(int n) {
        set<int> S;
        int val = sumOfSquares(n);
        
        while(val != 1){
            // if(val == 1)
            //     return true;
            if(S.find(val) != S.end())
                return false;
            S.insert(val);
            val = sumOfSquares(val);
        }
        return true;
    }
};