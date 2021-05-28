#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    char val;
    int word_count;
    TrieNode *children[26];
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
    }
};

int main(){
    vector<string> strs = {"flower", "flow", "flight"};
    Solution obj;
    obj.longestCommonPrefix(strs);
    
}