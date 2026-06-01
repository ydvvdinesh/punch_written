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
//optimal approach by recursion but here space complexity is o(n) due to recursive stack

//We are going through back tracking phele hum har node ko traverse krte huye jaynge then jab hum base condition me pauch jayenge toh toh phit carry jodenge and phir sab me carry jodete chle jayenge but note one thing yadi carry 0 rhii in last me mtlb node nahi jodni hai one rhii toh jodni pdegi
class Solution {
public:

    int helper(ListNode* temp){
        if(temp == NULL) return 1; //as carry toh to add them 
        //phele aage jayega toh temp->next use hoga
        int carry = helper(temp->next); // this carry find us the caary which going to addd everynode in backtracking
        temp->val = temp->val + carry;
        if(temp -> val < 10){
            return 0;
        } 
            temp->val = 0;
            return 1;
    }

    ListNode *addOne(ListNode *head) {
        int carry = helper(head);
        if(carry == 1){
            ListNode* newnode = new ListNode(1);
            newnode->next = head;
            return newnode;
        }
        //yadi carry zero nahi hoti hai toh return original head;
        return head;
    }
};
