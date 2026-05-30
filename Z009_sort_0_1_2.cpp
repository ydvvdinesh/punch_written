/*
Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/
//brute approach - find all no of zero, 1 , 2 and replace with the original linked list
class Solution {
    public:
        ListNode* sortList(ListNode* &head) {
            ListNode* temp = head;
            int cnt0 =0;
            int cnt1 =0;
            int cnt2 =0;
            while(temp != NULL){
                if (temp->data == 0) cnt0++;
                if(temp->data == 1) cnt1++;
                if(temp->data == 2) cnt2++;
                temp = temp->next;
            }
            // now replacement
            temp = head;
            while(temp != NULL){
                if(cnt0 > 0){
                temp->data = 0;
                cnt0--;
            }
            else if(cnt1 > 0){
                temp->data = 1;
                cnt1--;
            }
            else{
                temp->data = 2;
                cnt2--;
            }

            temp = temp->next;
            }
            return head;
        }
};
