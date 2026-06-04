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
//optimal approach - now we have use to reduce the space that why we are not going with map so we go 1. create and insert copynodes betweeen element 2 .connect random pointer 3. connect the next pointer
class Solution {
public:
    Node* copyRandomList(Node* head) {

         if(head == NULL) return NULL;

        Node* temp = head;
        //1. create and insert the copynodes;
        while(temp != NULL){
            Node* nextNode = temp->next;
            Node* copyNode = new Node(temp->val);
            temp->next = copyNode;
            copyNode->next = nextNode;
            temp = nextNode;
        }
        //2.connect the random pointer
        temp = head;
        while(temp != NULL){
            Node* copynode = temp->next;
            if(temp->random != NULL){
            copynode->random = temp->random->next; //temp random ke right me hi uski copynode hogi dryrun dekh lena samaj aajayega
            }
            else{
                copynode->random = NULL;
            }
            temp = temp->next->next;
        }
        //3. connect the next pointer or extact the copynodes linked 
        temp = head;
        Node* dnode = new Node(-1);
        Node* res = dnode;
        while(temp != NULL){
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dnode->next;
    }
};
