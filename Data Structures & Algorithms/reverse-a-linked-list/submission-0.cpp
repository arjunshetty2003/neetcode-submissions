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
    ListNode* reverseList(ListNode* head) {

        if (!head)
           return nullptr;

        stack<ListNode*> store;

        ListNode* curr = head;

        while(curr != nullptr) {
            store.push(curr);
            curr = curr->next;
        }

        head = store.top();
        store.pop();

        curr = head;

        while (!store.empty()) {
            curr->next = store.top();
            store.pop();
            curr = curr->next;
        }

        curr->next = nullptr;

        return head;
    }
};
