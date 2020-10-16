// ==============================  Ë«ÏòÁ´±í + ¹þÏ£±í  ==============================
// 1
struct Node {
    int key, val;
    Node *pre, *next;
    Node() : key(0), val(0), pre(nullptr), next(nullptr) {}
    Node(int key, int val) : key(key), val(val), pre(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(imap.find(key) == imap.end()) return -1;
        imap[key]->pre->next = imap[key]->next;
        imap[key]->next->pre = imap[key]->pre;
        imap[key]->next = head->next;
        head->next->pre = imap[key];
        head->next = imap[key];
        imap[key]->pre = head;
        return imap[key]->val;
    }
    
    void put(int key, int value) {
        if(imap.find(key) != imap.end()) {
            imap[key]->val = value;
            imap[key]->pre->next = imap[key]->next;
            imap[key]->next->pre = imap[key]->pre;
            imap[key]->next = head->next;
            head->next->pre = imap[key];
            head->next = imap[key];
            imap[key]->pre = head;
        }
        else {
            Node* newnode = new Node(key, value);
            imap[key] = newnode;
            newnode->next = head->next;
            head->next->pre = newnode;
            newnode->pre = head;
            head->next = newnode;
            if(imap.size() > _capacity) {
                Node* tobedelete = tail->pre;
                imap.erase(tobedelete->key);
                tail->pre = tail->pre->pre;
                tail->pre->next = tail;
                delete tobedelete;
            }
        }
    }

private:
    int _capacity;
    Node *head, *tail;
    unordered_map<int, Node*> imap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */