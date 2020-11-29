// https://leetcode.com/problems/decode-ways/

class Solution {
    // int count = 0;
public:
    int numDecodings(string s) {
        int count=0;
        countDecodings(s, 0, count);
        return count;
    }
    
    bool isValidNum(string sub){
        int num = stoi(sub);
        
        if(1<=num && num<=26)
            return true;
        else
            return false;
    }
    
    void countDecodings(string &mainStr, int i, int &count){
        if(i>=mainStr.length()){
            count += 1;
            return;
        }
        string singleChar(1, mainStr.at(i)); 
        if(isValidNum(singleChar)){
            countDecodings(mainStr, i+1, count);
        }        
        if(isValidNum(mainStr.substr(i, i+1)) && i!=mainStr.length()-1){
            countDecodings(mainStr, i+2, count);
        }
            
    }
    
    
};