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
        Node* dummy = new Node(0);
        Node* ptr1 = dummy;


        Node* ptr2 = head;

        unordered_map<Node*, Node*> new_addrs;

        while(ptr2 != nullptr){
            ptr1->next = new Node(ptr2->val);

            new_addrs[ptr2] = ptr1->next;

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        ptr2 = head;
        ptr1 = dummy->next;
        while(ptr2 != nullptr){
            ptr1->random = new_addrs[ptr2->random];
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }

        Node* returnNode = dummy->next;
        delete dummy;

        return returnNode;
    }
};
