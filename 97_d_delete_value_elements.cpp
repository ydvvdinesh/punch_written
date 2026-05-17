class Solution {
  public:
    Node* deleteK(Node* head, int val) {
        //if k is 1 , that means we have to remove the head 
        if (head->val == val){
            Node* temp = head;
            head = head->next;//head will move to head next 
            delete(temp);
            return head;
        }
        //k is like 2nd element or 4th elementt then first we need to count the all node 
        Node* temp = head;
        Node* prev = NULL;
        //tranversing through a linked list 
        while(temp != NULL){
            if(temp->val == val){
                prev->next = temp->next;// prev->next->next; // jo previous ka next to next that usko previous ke next se connect kardo
                delete(temp);
                break;
            }
            prev = temp; // temp ke piche waala
            temp = temp->next; // temp variable will move to next to temp
        }
        return head;
    }
};
