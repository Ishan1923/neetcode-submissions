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

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);

        ListNode* ptr = dummy;

        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;

        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                ptr->next = l1;
                l1 = l1->next;
            }
            else{
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }

        while(l1 != nullptr){
            ptr->next = l1;
            ptr = ptr->next;
            l1 = l1->next;
        }

        while(l2 != nullptr){
            ptr->next = l2;
            ptr = ptr->next;
            l2 = l2->next;
        }

        ListNode* returnNode = dummy->next;
        delete dummy;
        return returnNode;

    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        queue<ListNode*> q;

        for(const auto& node : lists){
            if(node) q.push(node);
        }

        if(q.empty()) return nullptr;

        while(q.size() > 1){
            ListNode* l1 = q.front();
            q.pop();

            ListNode* l2 = q.front();
            q.pop();

            q.push(merge(l1, l2));
        }

        ListNode* merged = q.front();
        q.pop();

        return merged;

    }
};
