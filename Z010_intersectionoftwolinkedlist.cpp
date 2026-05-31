/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //brute approach - put one ll into map and then check with the another/remaining linked list
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        map<ListNode*,int> mpp;
        //put into mapp
        while(temp1 != NULL){
            mpp[temp1] = 1;
            temp1 = temp1 -> next;
        }
        //now check with the second list
        while(temp2 != NULL){
            if(mpp.find(temp2) != mpp.end()) return temp2;
            temp2 = temp2 -> next; //check kro next
        }
        return NULL;
    }
};
