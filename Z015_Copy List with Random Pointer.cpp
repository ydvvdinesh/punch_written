/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//brute approach - replica bnaoo - return head copied node
//we will create a copy /replica of nodes and stored with the original and then connect krte jaoo , random hai toh woh kidr bhi connect hp skta hai so sab ka aise hi krte jaoo    
class Solution {
public:
    Node* copyRandomList(Node* head) {
      Node* temp = head;
      map<Node*, Node*> mpp; //orginal node, copied node
      while(temp != NULL){
        Node* newnode = new Node(temp->val); //creation of copied nodes
        mpp[temp] = newnode; //mpp[key] = value;
        temp = temp->next; 
      } 
      //till now we created the copied nodes , now we have to connect them 
        temp = head;
        while(temp != NULL){
            Node* copynode = mpp[temp]; //copynode is the first node of copied  ll  
            copynode->next = mpp[temp->next];//our key is temp->next and its value is next node to temp
            copynode->random = mpp[temp->random];
            temp = temp->next;
        }
        return mpp[head]; // value of head is copied head that is same as real one
    }
};
