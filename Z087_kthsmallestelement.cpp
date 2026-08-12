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
 //important property - inorder of bst always give you a sorted order 
 //optimal approach - do approach inorder likho then usko vector me store kraoo and then check kro
 //main apporach - inorder ke time hi pta lga lo , jaise hum kisi node me reach kre in oorder(left node right) toh node ko count kro and jaise k aaye woh hi node answer hogi because inorder me sabse phele left me jaata jayega then node pe aayega the root pe  
class Solution {
public:

    void inorder(TreeNode* root, int k, int& count, int& ans){
        if(root == NULL){
            return;
        }
        inorder(root->left,k,count, ans);
        //till now we reached to the most left part, now time count the all node using back track stuff
        count++;
        if(count == k){
            ans = root->val;
            return;
        }
        inorder(root->right,k, count ,ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int count =0;
        inorder(root, k ,count, ans);
        //yaha tak answer store ho gaya 
        return ans;
    }
};
