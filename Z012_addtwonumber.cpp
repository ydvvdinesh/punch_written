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
//optimal - dono head ko jodo cary ke saath me and bus carry ko o and 1 me rakho and nodes ko 0 to 9 me , and jo nahi node bnaoo uske links dhyan se 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        //jaha bhi new list bnani ho waha dummy node ka istemal zarror kr
        //creation of dummynode
        ListNode* dnode = new ListNode(-1);
        ListNode* curr = dnode;
        //or lenge becauseyadi null pauche toh dusra phele hi cover ho jaye 
       
        int carry =0;
        //carry stores the next thing send to node for addition (0 or 1)
        while(t1 != NULL || t2 != NULL){
            int sum = carry;
             //sum store the sum of t1 and t2 and carry , caary toh 0 se hi hogi
            if(t1 != NULL){
                sum = sum +t1->val; // carry humne phele add krdi hai
            }
            if(t2 != NULL){
                 sum = sum +t2->val;
            }
            //after sum we have to make the node of that and make the proper link
            ListNode* newnode = new ListNode (sum %10);
            //sum%10 - that the values lies between 0 to 10;
            carry = sum /10; //so it gives 0 or 1 
            curr->next = newnode;
            curr = newnode;
            //after completion one node move to next node 
            if(t1 != NULL){
                t1 = t1->next;
            }
            if(t2 != NULL){
                t2 = t2->next;
            }
        }
        if(carry == 1){
            ListNode* newnodi = new ListNode(carry);
            curr->next = newnodi;
            newnodi->next = NULL;
        }
        return dnode->next;
    }
};
