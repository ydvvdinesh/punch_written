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
 //3 approaches 
 /*
 brute - go to every node look bda hai ki chota yadi chota hai toh left otherwise left me 
 better - jo bhi preorder diya hoga uska , inorder of bst me create krdenge how?, directly sorted karke ye property hoti hai bst ki
 optimal - upperbound ke hisab se jayenge , yadi pointer ki value node se choti hai toh next node ke liye upper bound uss node ki value rhegi , other wise parent node ki 
 //simple terms
 //right me jayenge toh parent node upperbound hoga 
 //left me jayenge toh khud ki value hi upperbound hogi 
 */
class Solution {
public:

    // this function return us the root of the bst 
    TreeNode* bst(vector<int>& A, int& i, int bound){
        // i is the point, a is the vector and bound is the upper bound position
        if(i == A.size() || A[i]>bound){
            return NULL;
        }
        TreeNode* root = new TreeNode(A[i++]);
        //left me jab naye pe jaynnge toh , current waala purana hoga
        root->left = bst(A,i,root->val);
        root->right = bst(A,i,bound);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i  = 0;
        return bst(preorder, i, INT_MAX);
    }
};
