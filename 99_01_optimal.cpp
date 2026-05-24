/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //optimal approach - tortiose & Hare - slow and fast ek jagah aaye toh loop hai 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // ODD condition -  fast last pe rukhta hai 
        //even me null pe
        // and aayega kyuki do check karne hai same time
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next; 
            fast = fast -> next -> next; // 2 step
            if(slow == fast) return true;
        }
        return false;
    }
};
