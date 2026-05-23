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
 // better approach - link ulte karne hai 
 // we use three pointer variable - prev , temp, front 
 // front temp se aage waala and previous peeche waala 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev; //most important step
            prev = temp;
            temp = front;
        }
        return prev;
    }
};
/* Algoritham 
1) front aage waala hoga and prev wala starting me null ko point krega 
2) hume link ki drection ghooma denge and toh aab hume gali node pe jaana hai toh temp prev ho gayi gi and front temp ho jayega 
3) and last me hum previous returm kar denge kyuki temp and front toh next ke chakkar me null touch kar denge 
*/
