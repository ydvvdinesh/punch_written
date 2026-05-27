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
 //optimal approach - hume isme bhi residue node pe pauchna hai but tarika alag hoga - two pointer muni and muna 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //ek baar jitna diya utne step chlke dusre node pe pauch jayenge
        ListNode* muna = head;
        for(int i =0; i<n;i++){ //only n times
            muna = muna->next;
        }
        ListNode* muni = head;
        //muni at starting and muna reachedto the residue node, now both move simaltenouly one one step when muna can`t move forward munni give answer

        //edge case 
    if(muna == NULL){
    ListNode* newHead = head->next;
    delete(head);
    return newHead;
    }

        while (muna->next != NULL){
            muna = muna->next;
            muni = muni->next; // this will be the last that gove ans
        }
        //muni is our residue
        ListNode* deletenode = muni->next;
        muni->next = muni->next->next;
        delete(deletenode);
        return head;
    }
};
