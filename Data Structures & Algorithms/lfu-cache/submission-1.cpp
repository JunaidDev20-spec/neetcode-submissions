
class LFUCache {
private:
    struct Node {
        int key;
        int value;
        int freq;

        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
            prev = next = nullptr;
        }
    };

    struct DoublyLinkedList {
        Node* head;
        Node* tail;
        int size;

        DoublyLinkedList() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);

            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void removeNode(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }

        void addToHead(Node* node) {
            Node* first = head->next;

            node->next = first;
            node->prev = head;

            head->next = node;
            first->prev = node;

            size++;
        }

        Node* removeLRU() {
            if (size == 0) return nullptr;

            Node* node = tail->prev;
            removeNode(node);
            return node;
        }
    };

    int capacity;
    int minFreq;

    // key -> node
    unordered_map<int, Node*> cache;

    // frequency -> doubly linked list
    unordered_map<int, DoublyLinkedList*> freqList;

    void increaseFreq(Node* node) {
        int oldFreq = node->freq;

        // Remove node from its current frequency list
        freqList[oldFreq]->removeNode(node);

        // If the minimum frequency list becomes empty,
        // advance minFreq.
        if (oldFreq == minFreq &&
            freqList[oldFreq]->size == 0) {
            minFreq++;
        }

        // Increase frequency
        node->freq++;

        // Insert into the new frequency list
        if (freqList.find(node->freq) == freqList.end()) {
            freqList[node->freq] = new DoublyLinkedList();
        }

        freqList[node->freq]->addToHead(node);
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        Node* node = cache[key];

        increaseFreq(node);

        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        // Case 1: Key already exists
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];

            node->value = value;
            increaseFreq(node);

            return;
        }

        // Case 2: Cache is full; evict LFU
        if (cache.size() == capacity) {
            DoublyLinkedList* list = freqList[minFreq];

            // Least recently used among minimum-frequency nodes
            Node* victim = list->removeLRU();

            cache.erase(victim->key);
            delete victim;
        }

        // Case 3: Insert new node
        Node* node = new Node(key, value);

        cache[key] = node;

        if (freqList.find(1) == freqList.end()) {
            freqList[1] = new DoublyLinkedList();
        }

        freqList[1]->addToHead(node);

        // New nodes always start at frequency 1
        minFreq = 1;
    }
};
