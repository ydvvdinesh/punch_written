/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 //morris - thread based travsrsal , last most point se root ko thread se connect kardo and ek point of situation ke baad hta de , 
 //morrris traversal and why we are using it over iterative or recursive traversal because it takes o(1) space complexity 
 // do case honge one is left is null and 2 left is not null 
 // case 1 yadi left null hai that means write root and then move to roght and write that becoz inorder order is left , root then right 
 //case 2 yadi left null nahi hai then usme hum sabse phele thread install krenege then and jo thread intilize hogiu woh rightmost node of left subrtee se current waali pe hogi , yadi sirf node node hai toh us node se hoga 
 //phele thread install then ek baar aur traversal to write the order and order ke time jo bhi thread ho sabko remove karte jaoo 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;
        while(curr != NULL){
            // case -1 , yadi left null hai toh , then directly write the order , not need to create thread
            if(curr->left == NULL){
                inorder.push_back(curr->val);
                curr = curr->right; // move to right
            }
            //case - 2 yadi null nhai hai , toh sabse phele rightmostnode me jaoo
            else{
                TreeNode* prev = curr->left; // prev variavble standing on currleft
                //prev is in left subtree, that means entering in left subtree to find the right most
                //sfter entering we have to care two things 1 null nah ho, kyuki jaise hi null waali stage pe pauchi vaise hi, wahi toh rightmost hoga jo doond raje the  
                while(prev->right != NULL && prev->right != curr){
                    prev = prev->right;
                }
                //now after finding the rightmost of left subtree we have to do threading 
                if(prev->right == NULL){
                    //next mtlb we are at the last one , now have to create thread with main root
                    prev->right = curr;
                    //after threadin, we have to go curr and start traversal from left , jaha se humme order likhenga
                    curr = curr->left; // left root right
                    //isse movement krenge and nicche waale note krege aayenge
                }
                else{ //ek toh not null and prev ka right pointing to own curr then means remove thread
                    prev->right = NULL; // now jab thread thode ge toh curr ko nahi null ko print krega andadd the value 
                    inorder.push_back(curr->val);
                    curr = curr->right; // why we are going because we already visted to left 
                }
            }
        }
        return inorder;
    }
};
