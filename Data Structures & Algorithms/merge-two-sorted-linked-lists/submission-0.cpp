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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* h1 = list1;
        ListNode* h2 = list2;
        ListNode* tail = &dummy;
        while(h1!=nullptr && h2!=nullptr){
            if(h1->val <= h2->val){
                tail->next = h1;
                h1 = h1->next;
            }
            else{
                tail->next = h2;
                h2 = h2->next;
            }
            tail = tail->next;
        }
        while(h1!=nullptr){
            tail->next = h1;
            tail = tail->next;
            h1 = h1->next;
        }
        while(h2!=nullptr){
            tail->next = h2;
            tail = tail->next;
            h2 = h2->next;
        }
        return dummy.next;
    }
};
