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
    void reorderList(ListNode* head) {

        if(head == nullptr || head->next == nullptr) return;
        
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;

        while(ptr2 != nullptr && ptr2->next != nullptr){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
        }

        ListNode* curr = ptr1->next;
        ListNode* prev = nullptr;

        ptr1->next = nullptr;

        while(curr != nullptr){

            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;

        }


        ptr1 = head;
        ptr2 = prev;

        while(ptr2 != nullptr){
            ListNode* tmp1 = ptr1->next;
            ListNode* tmp2 = ptr2->next;

            ptr1->next = ptr2;
            ptr2->next = tmp1;

            ptr1 = tmp1;
            ptr2 = tmp2;

        }

    }
};
