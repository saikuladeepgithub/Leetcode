class Node
{
    public :
    int key;
    int val;
    Node * prev;
    Node * next;
    Node(int k,int v)
    {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
public:
    int capacity;
    unordered_map <int,Node *> mpp;
    Node *head,*tail;
    LRUCache(int cap) {
        capacity = cap;
        mpp.clear();
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end())
            return -1;
        else
        {
            Node * node = mpp[key];
            deletenode(node);
            insertathead(node);
            return node->val;
        }

       
    }
    
    void put(int key, int value) {
        if(mpp.find(key)==mpp.end())
        {
            if(mpp.size()==capacity)
            {
                Node * node = tail->prev;
                deletenode(node);
                mpp.erase(node->key);
                delete node;
            }
            Node * node = new Node(key,value);
            mpp[key] = node;
            insertathead(node);
        }
        else
        {
            Node * node = mpp[key];
            node->val = value;
            deletenode(node);
            insertathead(node);
        }
    }

    void deletenode(Node * node)
    {
        Node * prevnode = node->prev;
        Node * nextnode = node->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }
    void insertathead(Node * node)
    {
        Node * temp = head->next;
        head->next = node;
        node->prev = head;
        temp->prev = node;
        node->next = temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */