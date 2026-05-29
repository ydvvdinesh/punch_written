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
 //optimal approach - we are using two main algo merge sort , middle for breaking that this is going to use in merge sort


class Solution {
public:
 //tortiose and hare 
    ListNode* findmiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; // kyuki hume m1 chayiye otherwise head se start hota hai
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }


 //code for merging two linked list 

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (list1 != NULL && list2 != NULL) {

            if (list1->val < list2->val) {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        if (list1) temp->next = list1;
        else temp->next = list2;

        return dummyNode->next;
    }



    //main function
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        //acc to merge sort we have to move 
        ListNode* leftpart = head;
        ListNode* middle = findmiddle(head); //using tortiose and hare but one slight change tortoise and hare m2 location deta h even case me but hume yaha m1 chayiye toh fast ko head ke aage se move kregenge
        ListNode* rightpart = middle->next;
        //till now we get linked list divided into two parts one is left and another is right
        //now make sure left part last element will point to null
        middle->next = NULL;
        //ab dono part me recursive function lga do woh khud kr dega
        leftpart = sortList(leftpart);
        rightpart = sortList(rightpart);
        //We store recursive sorting because sortList() returns the head of the sorted linked list.

        //jab sort hojaye by recursion toh aap unne maerge krdo
        return mergeTwoLists(leftpart, rightpart);
    }
};
