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
 ///same like inorder bas , thread bnane ke time hi daal do 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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
                    inorder.push_back(curr->val); // ##################################################################################ye phele aayegjayega thread bnane ke time
                    curr = curr->left; // left root right
                    //isse movement krenge and nicche waale note krege aayenge
                }
                else{ //ek toh not null and prev ka right pointing to own curr then means remove thread
                    prev->right = NULL; // now jab thread thode ge toh curr ko nahi null ko print krega andadd the value 
                    curr = curr->right; // why we are going because we already visted to left 
                }
            }
        }
        return inorder;
    }
};
