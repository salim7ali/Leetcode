// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/
// https://www.geeksforgeeks.org/longest-consecutive-sequence-binary-tree/
#include<bits/stdc++.h>
#include<iostream>

void longSequence(Node *ptr,int &max, int curMax, int prevVal){
    // exit case
    if(ptr->left == NULL && ptr->right == NULL)
        return;

    if(ptr->data == prevVal +1)
        curMax += 1;
    else
        curMax = 1;

    if(curMax > max)
        max = curMax;

    if(ptr->left != NULL)
        longSequence(ptr->left, max, curMax, ptr->data);
    if(ptr->right != NULL)
        longSequence(ptr->right, max, curMax, ptr->data);
}
int main(){
    int max = INT_MIN;
    
    longSequence(ptr, max, 0, (ptr->data)-1);
}