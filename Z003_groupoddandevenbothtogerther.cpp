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
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
    ListNode* temp =head;
    vector<int> arr;
    //collect odd
    while(temp != NULL && temp->next !=NULL){
        arr.push_back(temp->val);
        temp = temp->next->next;
    }
    if (temp != NULL){
        arr.push_back(temp->val);
    } 
//after collecting nodes moves to starting point of even index
    temp = head->next;
    //collect even
    while(temp != NULL && temp->next !=NULL){
        arr.push_back(temp->val);
        temp = temp->next->next;
    }
    if (temp != NULL){
        arr.push_back(temp->val);
    } 
    //replace ment with data
    temp = head;
        int i =0;
    while(temp != NULL){
        temp->val = arr[i];
        temp = temp->next;
        i++;
    }
    return head;
    }
};
