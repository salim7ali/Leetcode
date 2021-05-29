#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    char val;
    int word_count;
    TrieNode* children[26] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
    , NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    TrieNode* findNonNullNode(TrieNode *node){
        for(int i=0; i<26; i++){
            if(node->children[i] != NULL)
                return node->children[i];
        }
        return NULL;
    }

    string longestCommonPrefix(vector<string>& strs) {
            
        // create trie nodes and connections for string chars
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

                    if(ptr_node == root)
                        root->word_count += 1;
                    ptr_node = ptr_node->children[char_index];
                }else{
                    ptr_node = ptr_node->children[char_index];
                    ptr_node->word_count += 1;
                }
            }
        }

        // Traverse the result
        string result;
        if(root->word_count >1 || root->word_count==0)
            return result;
        else{
            ptr_node = findNonNullNode(root);
            ptr_node = root->children[0];
            int start_word_count = ptr_node->word_count;
            while(start_word_count == ptr_node->word_count){
            
            }
            // cout<<"WC="<<root->children[0]->val<<" "<<root->children[0]->word_count;
        }


        
    }
};

int main(){
    vector<string> strs = {"apple", "apps", "ape"};
    // vector<string> strs = {"flower", "flow", "flight"};
    Solution obj;
    obj.longestCommonPrefix(strs);
    
}