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
        int c = 0;

        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;

        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;

        while(ptr1 != nullptr && ptr2 != nullptr){
            int sum = ptr1->val + ptr2->val + c;

            // cout << sum << endl;

            int ones = sum % 10;
            int tens = sum / 10;

            cout << ones << " " << tens << endl;

            ptr->next = new ListNode(ones);
            c = tens;

            ptr = ptr->next;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;

        }

        while(ptr1 != nullptr){
            int sum = ptr1->val + c;
            int ones = sum % 10;
            int tens = sum / 10;
            ptr->next = new ListNode(ones);
            ptr = ptr->next;
            ptr1 = ptr1->next;
            c = tens;
        }

        while(ptr2 != nullptr){
            int sum = ptr2->val + c;
            int ones = sum % 10;
            int tens = sum / 10;
            ptr->next = new ListNode(ones);
            ptr = ptr->next;
            ptr2 = ptr2->next;
            c = tens;
        }

        if(c != 0){
            ptr->next = new ListNode(c);
        }

        ListNode* returnNode = dummy->next;
        delete dummy;
        return returnNode;

    }
};
