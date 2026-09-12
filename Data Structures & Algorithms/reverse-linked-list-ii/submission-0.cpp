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
    ListNode* reverser(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* start = head;
        ListNode* end = head;
        ListNode* prev = dummy;
        while(--left){
            prev = start;
            start = start->next;
        }
        while(--right)
            end = end->next;

        ListNode* nextlist = end->next;
        end->next = nullptr;
        prev->next = nullptr;

        ListNode* rev = reverser(start);
        prev->next = rev;
        start->next = nextlist;

        return dummy->next;
    }
};