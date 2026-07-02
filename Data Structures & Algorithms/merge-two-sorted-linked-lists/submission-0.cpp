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
        ListNode* head = nullptr;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        if (!list1)
           return list2;
        
        if (!list2)
           return list1;

        if (curr1->val <= curr2->val) {
            head = curr1;
            curr1 = curr1->next;
        }
        else {
            head = curr2;
            curr2 = curr2->next;
        }

        ListNode* curr = head;
        curr->next = nullptr;

        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1->val <= curr2->val) {
                curr->next = curr1;
                curr1 = curr1->next;
                curr = curr->next;
            }
            else {
                curr->next = curr2;
                curr2 = curr2->next;
                curr = curr->next;
            }
        }

        while (curr1 != nullptr) {
            curr->next = curr1;
            curr1 = curr1->next;
            curr = curr->next;
        }

        while (curr2 != nullptr) {
            curr->next = curr2;
            curr2 = curr2->next;
            curr = curr->next;
        }

        curr->next = nullptr;

        return head;
    }
};
