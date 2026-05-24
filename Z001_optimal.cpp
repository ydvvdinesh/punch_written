/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //optimal - tortiose and hare bus last me ek change hai jab collision hojaye iska mtlb hai loop and ab dusra collison hoga aur woh node starting point hoga and dusre collison me slow and fast 1-1 move krenge 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast -> next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            //collision huwa toh loop detect hogi
            if (slow == fast){
                //yadi loop detect toh ab starting point nikalana hai
                //ek point ko collision waali jagah rakhege ek ko head pe then dono ko ek ek step move kkrenge jaha woh mile that is the answer 
                slow = head;
                while(slow != fast){
                    slow = slow-> next;
                    fast = fast-> next;
                }
                return slow; // starting point
            }
        }
        return NULL;
    }
};
