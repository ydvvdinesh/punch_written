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
 //optimal approach by two pointer
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* odd = head; // odd pointer pointing to head
        ListNode* even = head->next; //even pointer points next to head
        ListNode* evenhead = head->next; //jo odd ki chain se sabse phele connect hoga
        /*Continue loop only if:
1. even exists
2. even has a next node*/
        while(even != NULL && even->next != NULL){
            //this is two for the movement
            odd->next = odd->next->next; //odd next is now pointing to next of next of odd
            even->next = even->next->next;//odd next is now pointing to next of next of odd

            //now this is two for where the actual pointer was
            odd = odd->next;
            even= even->next;
            //both upper store the location through the movemnt snf in downward both are pointinh using upper
        }
        //now connect both ll
        odd->next = evenhead; // jo odd ka next evenhead hogi
        return head; 
    }
};
