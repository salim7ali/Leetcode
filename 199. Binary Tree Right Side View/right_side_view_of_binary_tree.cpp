#include<bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
//  RL root
 
class Solution {
public:
    void gen_right_side_values(TreeNode* node, int curr_level, vector<int> &right_view_result,vector<bool> &visited_level){
        if(!node)
            return;

        if(node->right)
            gen_right_side_values(node->right, curr_level+1, right_view_result, visited_level);
        if(node->left)
            gen_right_side_values(node->left, curr_level+1, right_view_result, visited_level);
        if(visited_level[curr_level] == false){
            visited_level[curr_level] = true;
            right_view_result[curr_level] = node->val;
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return {};
        
        vector<int> right_view_result(101);
        vector<bool> visited_level(101, false);
        int curr_level = 1;

        gen_right_side_values(root, curr_level, right_view_result, visited_level);

        int no_of_levels=0;
        for(int i=1; i<visited_level.size(); i++){
            if(visited_level[i] == false)
                break;
            right_view_result[i-1] = right_view_result[i];
            no_of_levels += 1;
        }

        right_view_result.erase(right_view_result.begin()+no_of_levels, right_view_result.end());
        // right_view_result.erase(right_view_result.begin(), right_view_result.begin());

        return right_view_result;
    }
};

int main(){
    
}