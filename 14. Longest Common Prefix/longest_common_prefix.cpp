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

    TrieNode* findFirstNonNullChildNode(TrieNode *node){
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
            root->word_count += 1;
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
            }
        }

        // Traverse the result
        string result = "";
        if(root->word_count==0)
            return result;
        else{
            int start_word_count = root->word_count;
            ptr_node = findFirstNonNullChildNode(root);
            while(ptr_node!=NULL && start_word_count == ptr_node->word_count){
                result.push_back(ptr_node->val);
                ptr_node = findFirstNonNullChildNode(ptr_node);
            }
            // cout<<"WC="<<root->children[0]->val<<" "<<root->children[0]->word_count;
        }
        return result;        
    }
};

int main(){
    vector<string> strs1 = {"apple", "apps", "ape"};
    Solution obj1;
    cout<<obj1.longestCommonPrefix(strs1)<<"\n";
    
    vector<string> strs2 = {"flower", "flow", "floight"};
    Solution obj2;
    cout<<obj2.longestCommonPrefix(strs2)<<"\n";
    
    vector<string> strs3 = {"dog", "racecar", "car"};
    Solution obj3;
    cout<<obj3.longestCommonPrefix(strs3)<<"\n";

    vector<string> strs4 = {"a"};
    Solution obj4;
    cout<<obj4.longestCommonPrefix(strs4)<<"\n";

    vector<string> strs5 = {"", "b"};
    Solution obj5;
    cout<<obj5.longestCommonPrefix(strs5)<<"\n";
}