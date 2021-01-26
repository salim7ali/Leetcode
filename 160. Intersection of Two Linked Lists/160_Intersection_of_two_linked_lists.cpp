// https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int lenA=0, lenB=0;
        ListNode *travPtrA = headA;
        ListNode *travPtrB = headB;
        while(travPtrA){
            lenA += 1;
            travPtrA = travPtrA->next;
        }
        while(travPtrB){
            lenB += 1;
            travPtrB = travPtrB->next;
        }

        int skipSteps = abs(lenA - lenB);
        // cout<<"(1)"<<skipSteps;

        if(lenA>lenB){
            travPtrA = headA;
            while (skipSteps--){
                travPtrA = travPtrA->next;
            }
            travPtrB = headB;
        }else{// works even if lenA = lenB as we just skip B by 0
            travPtrB = headB;
            while (skipSteps--){
                travPtrB = travPtrB->next;
            }
            travPtrA = headA;

        }
        bool found = false;
        while (travPtrA && travPtrB){
            if(travPtrA == travPtrB){
                found = true;
                break;
            }else{
                travPtrA = travPtrA->next;
                travPtrB = travPtrB->next;
            }
        }
        
        if(travPtrA && travPtrB && found)
            return travPtrA;
        else//disjoint or not found
            return NULL;
        
    }
};