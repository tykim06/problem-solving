#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;

        ListNode *node = head;
        int length = 1;

        while(node->next) {
            node = node->next;
            length++;
        }

        node->next = head;

        k %= length;
        k = length - k;

        for(int i=0; i<k; i++) {
            node = node->next;
        }

        head = node->next;
        node->next = NULL;

        return head;
    }
};