// https://leetcode.com/problems/clone-graph/
#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* dfs_return_clone_of_node(Node *node, unordered_map<Node*, Node*> &visited){
        if(node==NULL)
            return NULL;
        
        if(visited.find(node) == visited.end()){
            Node* copy_node = new Node(node->val);
            visited[node] = copy_node;
            
            // Node* copy_node = (Node*)malloc(sizeof(Node));
            // copy_node->val = node->val;
            // visited[node] = copy_node;


            for(auto neighbour: node->neighbors){
                visited[node]->neighbors.push_back(dfs_return_clone_of_node(neighbour, visited));
            }
        }
        return visited[node];
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> visited;

        Node *result_start_node = dfs_return_clone_of_node(node, visited);
        return result_start_node;

    }
};