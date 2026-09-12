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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* one = l1;
        ListNode* two = l2;
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(one || two || carry){
            int sum = carry;
            if(one){
                sum += one->val;
                one = one->next;
            }
            if(two){
                sum += two->val;
                two = two->next;
            }
            carry = sum/10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
        }
        return dummy->next;
    }
};
