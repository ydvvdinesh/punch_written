/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //brute appraoch - using map for storring , which we are storing <node, int> ,complete node with address and kitne times aaya
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode* , int> mpp;
        ListNode* temp = head;
        //traverse krege and check and then store , yadi check me mila that means loop hai
        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()){ //yadi jo chayiye mila toh
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};
