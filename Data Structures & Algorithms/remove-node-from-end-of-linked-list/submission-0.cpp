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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            size++;
            curr = curr->next;
        }
        int indexRemove = size - n;
        if (indexRemove == 0) {
            curr = head;
            head = head->next;
            delete curr;
            return head;
        }
        else {
            int index = 0;
            ListNode* prev = nullptr;
            curr = head;
            while (curr != nullptr) {
                ListNode* nextNode = curr->next;
                if (index == indexRemove) {
                    prev->next = nextNode;
                    delete curr;
                    break;
                }
                else {
                    prev = curr;
                    curr = nextNode;
                    index++;
                }
            }
        }

        return head;
    }
};
