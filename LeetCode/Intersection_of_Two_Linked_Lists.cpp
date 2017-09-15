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
        if(headA == headB) return headA;
        
        set<ListNode*> trace;
        trace.insert(headA);
        trace.insert(headB);
        
        while(headA || headB) {
            if(headA) {
                headA = headA->next;
                if(headA && trace.find(headA) != trace.end()) return headA;
                trace.insert(headA);
            }
            if(headB) {
                headB = headB->next;
                if(headB && trace.find(headB) != trace.end()) return headB;
                trace.insert(headB);
            }
        }
        return NULL;
    }
};