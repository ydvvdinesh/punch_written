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
 //optimal approach 
 /*
 1. find the tail of the ll
 2. we have to rotate k times , that means k node aage jayengi
 3.important point hum isme 1 based indexing se jayenge
 */
class Solution {
public:

    ListNode* findnode(ListNode* temp, int d){
    int cnt = 1;

    while(temp != NULL){
        if(cnt == d) return temp;
        cnt++;
        temp = temp->next;
    }
    return NULL;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
        return head;
        //let`s find the tail
        ListNode* tail = head;
        int len = 1; // here we already count 1 after putting tail at head
        // why we intilaze the one instead of xero 
        /* both approach find the length but is store the adrress and one is loss the adress
        Approach	Length	Final tail
        len=1, while(tail->next!=NULL)	Correct	Last node
        len=0, while(tail!=NULL)	Correct	NULL , this way lost adrres
        */
        while(tail ->next != NULL){
            len++;
            tail = tail ->next;
        }
        //now we have to reach the node which is going to become the last after all rotation, by the fromula = total length of ll - k
/*
    what if k is big 
    if k is mutlitple of then length then return head as same kyuki ghoom ke wahi aayega
    is not multiple = k = k%len
*/
        if (k % len == 0) return head;
        k = k% len;
        // till now we reached to tail , now connect tail to head to make proper connection
        // make circular
            tail->next = head;
        ListNode* lastnodeafterrotation = findnode(head,len-k);
        //and its next node is our updated head
        head = lastnodeafterrotation -> next;
        lastnodeafterrotation -> next = NULL;
        return head;
    }
};
