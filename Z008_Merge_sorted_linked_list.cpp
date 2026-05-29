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
ListNode* convert(vector<int>& arr){
        // empty array case
    if(arr.size() == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;
    for(int i =1;i<arr.size();i++){
        ListNode* temp = new ListNode(arr[i]); // this will create node everytime, temp is the pointer which is representing them
        mover ->next = temp; //connects the link
        mover = temp;
    }
    return head;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> arr;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        //in first linkedlist
        while(temp1 != NULL){
            arr.push_back(temp1->val);
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            arr.push_back(temp2->val);
            temp2 = temp2->next;
        }
        //till now we put everything into array, let`s sort it
        sort(arr.begin(),arr.end());
        //now convert array to list
        return convert(arr);
    }
};
