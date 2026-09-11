class ListNode {
    public:
        int key;
        int value;
        ListNode* prev;
        ListNode* next;

        ListNode(int key, int value) {
            this->key = key;
            this->value = value;
            prev = nullptr;
            next = nullptr;
        }
};

class LRUCache {
private:
    ListNode* head;
    ListNode* tail;
    unordered_map<int, ListNode*> addressMap;
    int capacity;
public:
    LRUCache(int capacity) {
        addressMap.reserve(capacity);
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (addressMap.count(key) == false) {
            return -1;
        }
        else {
            ListNode* node = addressMap[key];
            int value = node->value;
            ListNode* prev = node->prev;
            ListNode* next = node->next;
            prev->next = next;
            next->prev = prev;

            head->next->prev = node;
            node->prev = head;
            node->next = head->next;
            head->next = node;
            return value;
        }
    }
    
    void put(int key, int value) {
        if (addressMap.size() < capacity) {
            if (addressMap.count(key) == true) {
                ListNode* node = addressMap[key];
                node->value = value;
                ListNode* prev = node->prev;
                ListNode* next = node->next;
                prev->next = next;
                next->prev = prev;

                head->next->prev = node;
                node->prev = head;
                node->next = head->next;
                head->next = node;
            }
            else {
                ListNode* node = new ListNode(key, value);
                head->next->prev = node;
                node->prev = head;
                node->next = head->next;
                head->next = node;

                addressMap[key] = node;
            }
        }
        else {
            if (addressMap.count(key) == true) {
                ListNode* node = addressMap[key];
                node->value = value;
                ListNode* prev = node->prev;
                ListNode* next = node->next;
                prev->next = next;
                next->prev = prev;

                head->next->prev = node;
                node->prev = head;
                node->next = head->next;
                head->next = node;
            }
            else {
                ListNode* node = new ListNode(key, value);
                ListNode* leastUsed = tail->prev;
                int leastUsedKey = leastUsed->key;
                ListNode* prev = leastUsed->prev;
                ListNode* next = leastUsed->next;
                prev->next = next;
                next->prev = prev;
                delete leastUsed;
                addressMap.erase(leastUsedKey);

                head->next->prev = node;
                node->prev = head;
                node->next = head->next;
                head->next = node;

                addressMap[key] = node;
            }
        }
    }
};
