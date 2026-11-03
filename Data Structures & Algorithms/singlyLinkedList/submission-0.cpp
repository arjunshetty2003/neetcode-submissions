
#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    int size;
    ListNode* head;

public:
    LinkedList() {
        head = new ListNode(-1); // Dummy node
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;

        ListNode* curr = head->next;

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        return curr->data;
    }

    void insertHead(int val) {
        ListNode* node = new ListNode(val);

        node->next = head->next;
        head->next = node;

        size++;
    }

    void insertTail(int val) {
        ListNode* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = new ListNode(val);
        size++;
    }

    bool remove(int index) {
        if (index < 0 || index >= size)
            return false;

        ListNode* curr = head;

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        ListNode* temp = curr->next;
        curr->next = temp->next;

        delete temp;
        size--;

        return true;
    }

    vector<int> getValues() {
        vector<int> result;

        ListNode* curr = head->next;

        while (curr != nullptr) {
            result.push_back(curr->data);
            curr = curr->next;
        }

        return result;
    }

    ~LinkedList() {
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};
