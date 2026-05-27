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
 //brute force - jo delete karni usse phele waali pe pauch and the usko next to next poinnt kro and jo delete karni hai usko delete kardo
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;

        //length of linked list
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
    //edge case - delete the head
    if(cnt == n){
        ListNode* newhead = head->next;
        delete(head);
        return newhead;
    }

        //after counting reach to that node
        //residue or usse piche waali = length of ll - node we have to delete
        //we used a simple formula by observation
        temp = head;
        int residue = cnt - n;
        while(temp != NULL){
            residue--;
            if(residue == 0) break;
            temp = temp->next;
        }
        //we reached to our location, now delete that node and put links to correct position
        ListNode* deletenode = temp->next;
        temp->next = temp->next->next;
        delete(deletenode);
        return head;
    }
};
