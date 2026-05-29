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

// Brute Force Approach
// Step 1: Store linked list values into array
// Step 2: Sort the array
// Step 3: Replace linked list values using sorted array

class Solution {
public:
    ListNode* sortList(ListNode* head) {

        // edge case
        if(head == NULL || head->next == NULL) {
            return head;
        }

        vector<int> arr;

        // store values into array
        ListNode* temp = head;

        while(temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // sort array
        sort(arr.begin(), arr.end());

        // replace values back into linked list
        temp = head;
        int i = 0;

        while(temp != NULL) {
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }

        return head;
    }
};
