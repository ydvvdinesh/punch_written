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
 //optimal approach - 1.phele k group nikalo, then unko puri se seperate kro and first node temp and last kth hoga obvious and then reverse kardo , reverse krne ke baad unnhe connect kro and /is reverse ke baad temp last bnjayega and kthnode first for each sub group
class Solution {
public:

    //function to find the kth node 
    ListNode* findkthnode(ListNode* temp, int k){
        k--;
        while(temp != NULL && k>0){
            k--;
            temp =  temp->next;
        }
        return temp;
    }
    //function to reverse the Linked list
    ListNode* reverseList(ListNode* headab){
        ListNode* curr = headab;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* front = curr->next;
            curr->next = prev; // main step  to reverse the link
            prev = curr; // for traverse both list
            curr = front; 
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp =head; //for transverse
        // connect the nodes
        ListNode* prevnode = NULL;
        ListNode* newnode = NULL;
        while(temp != NULL){
            //1.find the kth node , because kthnode he last node hogi har sab group and temp se starting hogi
            ListNode* kthnode = findkthnode(temp,k);
            if(kthnode == NULL){
                 if(prevnode != NULL){
                    prevnode->next = temp;
                    }
                break;
                }
            //yadi null nahi hai toh hum ek k group mil gaya hai, toh hum usse list ko seperate krenge but remeber hum aage waali node ko peserve krenge becoz link connect krne me kaam aayegi
            newnode = kthnode->next;
            //now seperation, el alag hi linked list bnayenge
            kthnode->next = NULL;
            //reverse the linked list
            reverseList(temp);
            //is reverse ke baad temp last bnjayega and kthnode first for each sub group
            //check for the first sub groups
            if(temp == head){
                head = kthnode; // after reversal last first bnajyegi 
            }
            else{ //prevere bhi preserve kiya hai 
                prevnode->next = kthnode; // because kthnode first ho gayi na
            }

            //REMEBER 
            prevnode = temp; // preserve krdiya hai 
            temp= newnode; //nextnode ko isliye pserve kiya tha 
        }
    return head;
    }
};
