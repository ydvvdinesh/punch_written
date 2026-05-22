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
//brute approach
/*
(n/2+1) -  ye middle dega and ye toh ek number and so  temp ko uss node pe lajeyenge then we return the temp or that node thorugh temp
hmesha head diya hoga usse khelna hai 
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
    ListNode* temp = head;
    int count = 0;
    //count no of nodes
    while(temp != NULL){
        count = count +1;
        temp = temp->next; // moving temp to next code 
    }
    int midnode = (count/2) +1 ;

    //now move temp to it but before we have to reset temp isko pheli position pe leke aana pdega 
    temp = head;
    while(temp != NULL){
        midnode = midnode -1; // reduction method , jaha zero huwa untni node pe hi middle node , jisse temp se dikhado
        if(midnode == 0) break;
        temp = temp -> next;
    }
    return temp;
    }
};
