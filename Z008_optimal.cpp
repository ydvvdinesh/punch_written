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
 //optimal approach 
 //dummy node bnaoo and jo dono list me ko choti node hai usse connect kreke jaoo khud merge ho jayegi
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        //creation of dummy node 
        ListNode* dnode = new ListNode(-1);
        ListNode* temp = dnode; // temp is pointer of new linked list which is started from the dummy node 

        while(t1 != NULL && t2 != NULL){
            if(t1->val < t2->val){
            temp->next = t1; //temp will point the smallest one
            temp=t1; //here we are adding the node in linkedlist or in final one
            t1 = t1->next ; //move t1 to the next
            }
            
            else{
            temp->next = t2; //temp will point the smallest one
            temp=t2; //here we are adding the node in linkedlist or in final one
            t2 = t2->next ; //move t1 to the next
            }
        }
        // if t1 jaldi exhaust ho jaye yaha and t2 jaldi exhaust
        if(t1 != NULL){
            temp->next = t1;
        }
        if(t2 != NULL){
            temp->next = t2;
        }
        return dnode->next;
    }
};
