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
 //optimal approach - ek step slow phele rokna hai toh, yaha toh ek baar fast ko jada chlo ya ek slow ka step skip krdo fir skip mid ke ek point phele hi rukegi
 //baaki tortise and & hare hi chlega , ek 2 ek 1
 //slow hame residue dega
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
  // edge case
        if(head == NULL || head->next == NULL){
            delete(head);
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        fast = fast->next->next;
        while(fast !=NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // residue = slow;
        ListNode* middlenode = slow->next;
        slow->next = slow->next->next;
        delete(middlenode);
        return head;
    }
};
//don`t use delete function on Leetcode
