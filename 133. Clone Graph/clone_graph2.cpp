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
    Node* graphCloner(Node* currOrigNode, map<Node*, Node*> &oldToNewMap){
        
        Node* currDupNode = new Node(currOrigNode->val);
        oldToNewMap[currOrigNode] = currDupNode;

        Node* currOrigNeighbor;
        Node* currDupNeighbor;
        for(int i=0; i<currOrigNode->neighbors.size(); i++){
            currOrigNeighbor = currOrigNode->neighbors[i];   
            
            if(oldToNewMap.find(currOrigNeighbor) == oldToNewMap.end()){ // not visited
                currDupNode->neighbors.push_back(graphCloner(currOrigNeighbor, oldToNewMap));
            }else{
                currDupNeighbor = oldToNewMap[currOrigNeighbor];
                currDupNode->neighbors.push_back(currDupNeighbor);
            }
        }
        return currDupNode;
    }

    Node* cloneGraph(Node* node) {
        map<Node*, Node*> oldToNewMap;
        
        return graphCloner(node, oldToNewMap);

    }
};