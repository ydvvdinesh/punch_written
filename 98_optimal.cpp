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

 //optimal approach - tortoise & Hare - ek ek step , dusra 2 step , simaltaneously
 //jaha fast ruka , even me null pe and odd me last pe , ho uss time slow jaha hoga wo answer hoga 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        //jab tak fast last yaha null pe nahi pocha hai tabtak move karenge
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next; //ek step
            fast = fast -> next -> next;
        }
        return slow; // kyuki jaha slow wo answer hoga 
    }
};
