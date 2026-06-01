/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/
//brute approach - reverse , traverse , if data less than 10 mtlb carry otherwise one , reverse

class Solution {
public:

      ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev; //most important step
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode *addOne(ListNode *head) {
        head = reverseList(head); //why we reverse because mathematics operation peeche se hi shuru hota hai obvious hai
        ListNode* temp = head ;
        int carry = 1; // carry ko one intiliaze 
        while(temp != NULL){
            temp-> val = temp->val +carry;
            if(temp->val < 10){
                temp->val = temp->val;
                carry = 0; // yadi carry zero hai toh uske aage traverse mat kro kyuki uskeaage sab same rhega
                break;
            }
            else{
                temp->val = 0;
                carry = 1;
            }
            temp =temp->next;
        }
        //no of digits (before adding one to linked list) = after addin and carry zero rhegi
        //yadi no od digits jada hogayi after adding 1 , carry 1 hai toh uske new node bnaoo and usko head bnaoo
        //edge case
        //saara khel carry ka hai, yadi carry 1 bchi hai last me after complete traversal toh usko head pe connect kar Definition
        //after traversal
        if(carry == 1){
            head = reverseList(head);
            ListNode* newnode = new ListNode(1);//becoz carry 1 me hi khelgi
            newnode -> next = head;
            return newnode;
        }
        //yadi nahi hoti hai toh real waale(jisko traverse kiya tha usko reverse kro and uska head return kardo)
        head = reverseList(head);
        return head;
    }
};
