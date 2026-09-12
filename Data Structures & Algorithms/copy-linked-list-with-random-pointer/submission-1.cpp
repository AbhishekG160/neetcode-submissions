/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        // make copied A-A'-B-B' 
        // point random pointers 
        // take out the copies 
        Node* curr = head;
        while(curr){
            Node* nextone = curr->next;
            Node* newone = new Node(curr->val);
            curr->next = newone;
            newone->next = nextone;
            curr = nextone;
        }

        curr = head;
        while(curr){
            if(curr->random != nullptr)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        curr = head;
        Node* copyhead = head->next;
        Node* copycurr = copyhead; 
        while(curr){
            curr->next = curr->next->next;
            if(copycurr->next != nullptr)
                copycurr->next = copycurr->next->next;
            curr = curr->next;
            copycurr = copycurr->next;
        }
        return copyhead;
    }
};
