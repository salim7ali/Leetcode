#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    char val;
    int word_count;
    TrieNode* children[26];
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    string longestCommonPrefix(vector<string>& strs) {
            
        TrieNode* ptr_node;
        for(int string_index=0; string_index<strs.size(); string_index++){

            ptr_node = root;
            for(int j=0; j<strs[string_index].length(); j++){
                char character = strs[string_index][j];
                int char_index  = character - 'a';
                // cout<<char_ascii<<" ";

                if(ptr_node->children[char_index] == NULL){
                    TrieNode* child_node = new TrieNode();
                    child_node->val = character;
                    child_node->word_count += 1;
                    ptr_node->children[char_index] = child_node;


                    ptr_node = ptr_node->children[char_index];

                }else{
                    ptr_node = ptr_node->children[char_index];
                    ptr_node->word_count += 1;
                }


            }cout<<"\n";
        }
    }
};

int main(){
    vector<string> strs = {"apple", "apps", "ape"};
    // vector<string> strs = {"flower", "flow", "flight"};
    Solution obj;
    obj.longestCommonPrefix(strs);
    
}