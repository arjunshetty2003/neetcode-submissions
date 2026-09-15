class CacheNode {
    public:
        int key;
        int value;
        CacheNode* prev;
        CacheNode* next;

        CacheNode(int key, int value) {
            this->key = key;
            this->value = value;
            prev = nullptr;
            next = nullptr;
        }
};

class LRUCache {
private:
    unordered_map<int, CacheNode*> nodeMap;
    int capacity;
    CacheNode* head;
    CacheNode* tail;

    void insertFront(CacheNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void remove(CacheNode* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

public:
    LRUCache(int capacity) {
        head = new CacheNode(-1, -1);
        tail = new CacheNode(-1, -1);
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
        nodeMap.reserve(capacity);
    }
    
    int get(int key) {
        if (nodeMap.count(key) == false) {
            return -1;
        }
        else {
            if (head->next->key == key) {
                return head->next->value;
            }
            else {
                CacheNode* curr = nodeMap[key];
                remove(curr);
                insertFront(curr);
                return curr->value;
            }
        }
    }
    
    void put(int key, int value) {
        if (nodeMap.count(key)) {
            CacheNode* curr = nodeMap[key];
            remove(curr);
            curr->value = value;
            insertFront(curr);

            return;
        }

        if (nodeMap.size() == capacity) {
            CacheNode* leastUsed = tail->prev;
            int leastUsedKey = leastUsed->key;
            nodeMap.erase(leastUsedKey);
            remove(leastUsed);
            delete leastUsed;
        }

        CacheNode* node = new CacheNode(key, value);
        nodeMap[key] = node;
        insertFront(node);
    }
};
