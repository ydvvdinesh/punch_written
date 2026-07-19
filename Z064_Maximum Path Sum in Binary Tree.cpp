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
 //upgraded version of diameter 
 //approach - maximum left hieght + maximum right height + node ki value , har jahag nikalo simple and 
class Solution {
public:

    //creating a function  to get to know about the total path distance at particular node 
    //maxi will store the total path value 
    int totalpath(TreeNode* root, int &maxi){
        TreeNode* node = root;
        if(node == NULL){
            return 0;
        }
        //traversal to leftside and getting the height from there and getting max to handle the negative error 
        int leftside = max(0,totalpath(node->left, maxi));
        //traversal to rightside and getting the height from there
        int rightside = max(0,totalpath(node->right, maxi));
        // storing the total value
        maxi = max(node->val + leftside + rightside, maxi);
        return node->val + max(leftside, rightside);
    }

    int maxPathSum(TreeNode* root) {
        int maximum = INT_MIN;
        totalpath(root, maximum);
        return maximum;
    }
};
