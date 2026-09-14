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

    pair<ListNode*, ListNode*> reverse(ListNode* head, int k){
        ListNode* ptr1 = nullptr;
        ListNode* ptr2 = head;
        int count = 0;
        while(ptr2 != nullptr && count != k){
            ListNode* ptr3 = ptr2->next;
            ptr2->next = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr3;
            count++;
        }
        head->next = ptr2;
        return {ptr2, ptr1};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode* ptr = head;
        while(ptr != nullptr){
            n++;
            ptr = ptr->next;
        }
        int groups = n / k;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevtail = dummy;
        ListNode* curr = head;

        for(int i = 0; i < groups; i++){
            ListNode* nextGroupStart = curr;
            for(int j = 0; j < k; j++){
                nextGroupStart = nextGroupStart->next;
            }

            auto [newStart, newHead] = reverse(curr, k);

            prevtail->next = newHead;
            prevtail = curr;
            curr = nextGroupStart;
        }

        ListNode* returnNode = dummy->next;
        delete dummy;
        return returnNode;

    }
};
