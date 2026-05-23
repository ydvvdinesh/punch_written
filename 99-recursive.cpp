/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 //recurisve - chote se bda bnta jayega , but direction ulti  rhegi 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    //base condition
    if(head ==NULL || head -> next == NULL){
        return head;
    }
//reverse from the last single
    ListNode* newhead = reverseList(head -> next); // ye jab ek node se start kre tab 
    ListNode* front = head -> next;
    front -> next = head; // sign ulte kr diye hai ab 
    //yaha humne front ka next piche waala aasign kr diya toh nisaan khu d badal jayega 
    head -> next = NULL;
    return newhead;
    }
};
