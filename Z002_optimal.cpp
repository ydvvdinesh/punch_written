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
 /*
 1. find the middle on and divide their part , choose m1 instead of m2 wile using tortoise & hare , hum even case me m2 lete hai slow wahi rukhta hai but yaha thoda change hai
 2.reverse the half part 
 3.comparsion with two pointer
 */
 //iterative function
ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
        ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //find middle
        ListNode* slow = head;
        ListNode* fast = head;
        //fast -> next ->next != NULL FOR getting m1
        //slow toh middle m1 pe rukhega and fast at second last
        //trick - orginal position se jagah phele rokna hai , orignial matlab real tortise and hare
        while(fast->next != NULL && fast -> next ->next != NULL){
            slow = slow ->next;
            fast = fast -> next ->next;
        }
        //reverse second part of the linkedin list 
        ListNode* newhead = reverseList(slow->next);

        //now comparsion
        ListNode* first = head;
        ListNode* second = newhead; //after reversal
        while(second != NULL){ // same number toh jab second rukhega tabho first bhi
        if (first->val != second->val){ //->val for val khaali nahi likhna
            reverseList(newhead); //jaise configuration vaise hi wapis kardena
            return false;
        }
        first = first ->next;
        second = second ->next;
        }
        reverseList(newhead);
        return true;
    }
};
