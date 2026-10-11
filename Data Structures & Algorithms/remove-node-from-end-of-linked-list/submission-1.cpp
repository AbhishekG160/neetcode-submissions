/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        int steps = n+1;
        while(steps--)
            fast = fast->next;
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* deleted = slow->next;
        if(deleted)
            slow->next = deleted->next;
        delete deleted;
        return dummy.next;
    }
};
