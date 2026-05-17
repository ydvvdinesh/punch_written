class Solution {
  public:
    Node* removeLastNode(Node* head) {
        if (head == NULL || head-> next == NULL) return NULL;
        Node* temp = head;
        while(temp->next->next != NULL){ //yadi null nahi hai toh waha tak jaoo
            //moving temp unitl we can`t get 
            temp = temp->next;
        }
        //once we get that 
        free(temp->next);
        temp -> next = NULL;
        return head;
    }
};
