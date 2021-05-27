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
    void dfs(Node *node, Node *result, map<int, bool> &visited){
        visited[node->val] = true;

        for(int i=0; i<node->neighbors.size(); i++){
            int curr_neighbour = (*(node->neighbors[i])).val;
            if(visited[curr_neighbour] == false){
                dfs(node->neighbors[i], result, visited);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        Node *result_node_ptr;
        map<int, bool> &visited;

        dfs(node, result_node_ptr, visited);

    }
};