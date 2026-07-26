/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    // creating the function that gives path to the target node
    bool getpath(TreeNode* root, TreeNode* target, vector<TreeNode*> &path){

        if(root == NULL)
            return false;

        path.push_back(root);

        if(root == target)
            return true;

        if(getpath(root->left, target, path) ||
           getpath(root->right, target, path))
            return true;

        path.pop_back();

        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        getpath(root, p, path1);
        getpath(root, q, path2);

        int i = 0;

        while(i < path1.size() && i < path2.size() && path1[i] == path2[i]){
            i++;
        }

        return path1[i - 1];
    }
};
