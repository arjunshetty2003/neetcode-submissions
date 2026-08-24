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
        stack<int> nums;

        ListNode* curr = head;

        while (curr != nullptr) {
            nums.push(curr->val);
            curr = curr->next;
        }

        curr = head;

        while (curr != nullptr) {
            if (!nums.empty()) {
                curr->val = nums.top();
                nums.pop();
            }
            curr = curr->next;
        }

        return head;
    }
};
