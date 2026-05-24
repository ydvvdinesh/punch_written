/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //brute force using mapp
 //mapp me daalo jo dusri baar saari nodes me phele woh hi starting point hoga
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        map <ListNode* , int> mpp;
        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()) return temp;
            mpp[temp] = 1;
            temp = temp-> next;
        }
        return NULL;
    }
};
