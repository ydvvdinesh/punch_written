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
 //brute approach - stack me daalo and comparsion krwalonikalte time
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;
        //adding the value into stack
        while(temp !=NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        //comparsion part comes , comparsion with top (because stack lifo follow karta hai) and har baar top ko htate jayenge
        temp = head; // reset our thing
        while(temp != NULL){
            if (temp-> val != st.top()) return false;
            st.pop();
            temp = temp->next;
        }
        return true;
    }
};
