//optimal approach - dll and mapp se khel khatam kr denge  - pura dry ka run ka game and notes me likh diya hai 
//in dll we are crearing the dumpy head and tail 
//first we have to write a class node to use linked list ,
//declaring the linked list
class Node{
public:
    int key, value;
    Node* prev;
    Node* next;
    //creating constructor
    Node(int key, int value){
    this->value = value;
    this->key = key;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:
    int cap;
    map<int, Node*> mp;
    Node* head; //declare head and tail node
    Node* tail;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        //in cache, in starting head pointing to tail and tail pointing to head
        head->next = tail;
        tail->prev = head;
    }
    //for get we take value using key and remove from that place and move that node after the head, so we are going to write a function
     //first we write the function to remove from that place
     void deleteNode(Node* node){
        //do node bnani hai jo aage and peeche hai unke 
        Node* prevnode = node->prev;
        Node* nextnode = node->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
     }
     
     
     void addNode(Node* node){
        // yaha ek node bnani kyuki then hum head se kaam chala lenge
        Node* temp = head->next; 
        head->next = node; //jo naayi aayi usko point krega
        node->prev = head;
        node->next = temp;
        temp->prev = node;
     }


    int get(int key) {
        //jp chayiye yadi woh nahi mapp me toh 
        if(mp.find(key) == mp.end()) return -1;
            Node* node = mp[key]; // node stores everything because mapp contains somplete node with addres
            deleteNode(node);// old jagah se htaya 
            addNode(node);//nayi jagah daal diya 
        return node->value;
    }
    
    void put(int key, int value) {
        //yadi value present hai toh uski value badal denge
         if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->value = value;
            deleteNode(node);
            addNode(node);
            return;
         }
        //we will remove the last cache , last cache will always tail prev
        if(mp.size() == cap){
        Node* node = tail->prev;
        deleteNode(node);
        mp.erase(node->key);
        delete(node);
        }
        //other wise we add node afyter the head
        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
