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
    ListNode* helper(ListNode* head, int k){
        int count = 0;
        ListNode* curr = head;
        while(curr && count<k){
            curr = curr->next;
            count++;
        }
        if(count == k){
            // enough nodes present to reverse 
            ListNode* nextpart = helper(curr, k);
            curr = head;            
            while(count){
                ListNode* next = curr->next;
                curr->next = nextpart;
                nextpart = curr;
                curr = next;
                count--;
            }

            return nextpart;
        }

        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return helper(head, k);
    }
};
