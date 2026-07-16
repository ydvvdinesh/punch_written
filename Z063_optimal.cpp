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
 //optimal approach - saath saath me hi maxi nikalo, lh baar baar mat caall kro
//height ke saath unko store bhi karte gaye and last me chup chap answer puch liya
class Solution {
public:

     int maxdepth(TreeNode* root, int &maxi){
        TreeNode* node = root;
        if(node == NULL){
            return 0;
        }
        //recursive way of traversal
        int lh = maxdepth(node->left, maxi);
        int rh = maxdepth(node->right, maxi);
        maxi = max(maxi,lh+rh);
        return (1+max(lh,rh));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        maxdepth(root, diameter);
        return diameter;
    }
};
