class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k,int value)
        {
            key = k;
            val = value;
            prev = NULL;
            next = NULL;
        }
    };
    unordered_map<int,Node*>mp;
    int capacity;
    Node* head;
    Node *tail;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head =new Node(-1,-1);
        tail =new Node(-1,-1);
        head->next= tail;
        tail->prev = head;
    }

   void AddNodeAfterHead(Node* node)
    {
        Node* nodeafterHead = head->next;
        node->next = nodeafterHead;
        nodeafterHead->prev =node;
        node->prev = head;
        head->next = node;
    }

    void deleteNode(Node* node)
    {
        Node* prevNode= node->prev;
        Node* NextNode = node->next;
        NextNode->prev = prevNode;
        prevNode->next = NextNode;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* node = mp[key];
        deleteNode(node);
        AddNodeAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
           
            Node* node = mp[key];
            node->val = value;
            deleteNode(node);
            AddNodeAfterHead(node);
            return;
        }
        else{
            Node* node = new Node(key,value);
             mp[key] = node;
        AddNodeAfterHead(node);
        if(mp.size()>capacity)
        {
            Node* lru = tail->prev;
            deleteNode(lru);
            mp.erase(lru->key);
            delete lru;
        }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */