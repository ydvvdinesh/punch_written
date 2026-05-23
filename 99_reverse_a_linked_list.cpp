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
 //brute approach stack me daalo and nikalo and temp ko uss jagah leke jaoo
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;
        //putting into stack
        while(temp != NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        //pull out all but with the help of temp
        temp = head;
    //reverse engineering krenge , temp ko har baar first element/ ya top ko refer krenge and har baar top remove krenge assign krke and temp bhi change hota rhega
        while(temp != NULL){
            // temp = st.top(); //temp is pointer and usme aap value store krea rahe ho that means its wrong , right one is given below
            temp -> val = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};

//We cannot return temp instead of head because temp is used only for traversing the linked list. During traversal, temp moves from one node to the next using temp = temp->next. After the loop finishes, temp reaches the end of the linked list and becomes NULL. Therefore, returning temp would return NULL instead of the linked list. On the other hand, head always stores the address of the first node and its value does not change during traversal. Hence, we return head because it still points to the beginning of the linked list.
