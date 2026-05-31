/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//wrong answer ek baar check kr lena
 //optimal approach - dono temp ko chalte rho jab null ho toh dobara start kro phir allignment me aajyega and allignment me aake jab hume woh node mil jayega jo dono list me hai 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* temp1 = headA;
       ListNode* temp2 = headB;
       while(temp1 != temp2){
        //dono pointer chlte rhenge 
            temp1 = temp1 ->next;
            temp2 = temp2 ->next;
            // dono temp ek node point kre which same or collison occurs
            if (temp1 == temp2) return temp1;
            //yadi null huw toh oppiste ke head ko point krege and phor traverse krega
            if(temp1 == NULL){
                temp1 = headB;
            }
            if(temp2 == NULL){
                temp2 = headA;
            }
       }
       return NULL; //yadi collision nahi huwa toh dry run aacha smjayega
    }
};








or 









//correct code
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1 != temp2){

            if(temp1 != NULL) temp1 = temp1->next;
            else temp1 = headB;

            if(temp2 != NULL) temp2 = temp2->next;
            else temp2 = headA;

            if(temp1 == temp2) return temp1;
        }

        return temp1;
    }
};
