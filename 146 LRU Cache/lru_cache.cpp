// https://leetcode.com/problems/lru-cache/
#include<bits/stdc++.h>
using namespace std;
#define CAPACITY 5

struct node{
    int value;
    node *left = NULL;
    node *right= NULL;
};

void insertNodeAtRear(node *newNodePtr, int value, node *head, node *tail){
    tail->right = newNodePtr;
    newNodePtr->left = tail;
    tail = newNodePtr;
}

void removeNode(){
    
}

void LRU(vector<int> &ipPages, int &page_faults){
    unordered_map <int, node*> umap;
    node *head, *tail, *newNodePtr;

    for(int i=0; i<ipPages.size(); i++){
        newNodePtr = (node*)malloc(sizeof(node));
        if(i==0){//first node
            newNodePtr->value = ipPages[0];
            head = newNodePtr;
            tail = newNodePtr;
            umap[ipPages[0]] = newNodePtr; 
        }else if(i<CAPACITY){
            newNodePtr->value = ipPages[i];
            insertNodeAtRear(newNodePtr, ipPages[i], head, tail);
            umap[ipPages[i]] = newNodePtr;
        }else{
            if(umap.find(ipPages[i]) == umap.end()){

            }else{
                newNodePtr->value = ipPages[i];
                insertNodeAtRear(newNodePtr, ipPages[i], head, tail);
                umap[ipPages[i]] = newNodePtr;
                
            }
        }

        
    }
}

int main(){
    int pageFaults = 0;
    vector<int> ipPages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2};
    LRU(ipPages, pageFaults);
    return 0;        
}