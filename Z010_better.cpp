/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //better approach - allignment dono ka same krna hai jaise hi same allignment me same node aaye mtlb woh hi hai intersection node/ll
class Solution {
public:

    //now we have to find which linked list is bigger because after finding bigger one hum usme(n2-n1) steps aage badhege and allginment same krke same traverse krenge 

    ListNode* allignmentsetup(ListNode* bigger,int d){
            while(d>0){
                d--;
                bigger = bigger -> next ; //bda waala se movekrega
            }
            return bigger;
        }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //first Linked List
        ListNode* temp1 = headA;
        int N1 =0;
        while(temp1 != NULL){
            N1++;
            temp1 = temp1->next;
        }
        // till now we find the leength of 1st linked list
        
        ListNode* temp2 = headB;
        int N2 =0;
        while(temp2 != NULL){
            N2++;
            temp2 = temp2->next;
        }
        //till now we d=find lenhth of both ll . and temp at null
        
    //reset temp
        temp1 = headA;
        temp2 = headB;
        
        // now we are doing allignment step using a function
        if(N1 < N2)
            temp2 = allignmentsetup(temp2, N2 - N1);

        //because second one is bigger
        else if(N2 < N1)
            temp1 = allignmentsetup(temp1, N1 - N2);

        //allignment is done, now move to checking
        while(temp1 != NULL && temp2 != NULL){
            if(temp1 == temp2) return temp1;
            temp1 = temp1 -> next;
            temp2 = temp2 ->next;
        }
        return NULL;
    }
};
