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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;
        else if (list1 == nullptr && list2 != nullptr)
            return list2;
        else if (list1 != nullptr && list2 == nullptr)
            return list1;
        else {
            ListNode* head1 = list1;
            ListNode* head2 = list2;

            ListNode* dummyNode = new ListNode();
            ListNode* curr = dummyNode;

            while (head1 != nullptr && head2 != nullptr) {
                if (head1->val <= head2->val) {
                    curr->next = new ListNode(head1->val);
                    curr = curr->next;
                    head1 = head1->next;
                }
                else {
                    curr->next = new ListNode(head2->val);
                    curr = curr->next;
                    head2 = head2->next;
                }
            }

            while (head1 != nullptr) {
                curr->next = new ListNode(head1->val);
                curr = curr->next;
                head1 = head1->next;
            }

            while (head2 != nullptr) {
                curr->next = new ListNode(head2->val);
                curr = curr->next;
                head2 = head2->next;
            }

            curr = dummyNode;

            return curr->next;
        }
    }
};
