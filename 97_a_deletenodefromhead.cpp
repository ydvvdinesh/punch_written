/*
struct Node {
    int data;
    struct Node* next;
};*/
struct Node* deleteHead(struct Node* head) {
    if(head == NULL) return head;
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}
