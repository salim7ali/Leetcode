// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/
// https://www.geeksforgeeks.org/longest-consecutive-sequence-binary-tree/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void longestConsecutiveSeq(Node *ptr, int prev_val, int curr_seq_len, &max_seq_len){
    if(ptr==NULL)
        return;
    if(ptr->data == prev_val+1)
        curr_seq_len += 1
    else
        curr_seq_len = 1;
    
    if(curr_seq_len > max_seq_len)
        max_seq_len = curr_seq_len;

    longestConsecutiveSeq(ptr->left, ptr->data, curr_seq_len, max_seq_len);
    longestConsecutiveSeq(ptr->right, ptr->data, curr_seq_len, max_seq_len);
}
int main(){
    int max_seq_len = 0;
    
    longestConsecutiveSeq(head, head->data, 0, max_seq_len);// (*head).data
}