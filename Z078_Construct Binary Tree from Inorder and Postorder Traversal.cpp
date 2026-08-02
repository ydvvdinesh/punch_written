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
class Solution {
public:

    TreeNode* createtree(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend, map<int, int>& inmap){
        
        if(poststart > postend || instart > inend){
            return NULL;
        }
        // root in preorder traversal
        TreeNode* root = new TreeNode(postorder[postend]);
        // root index in order traversal
        int inroot = inmap[root->val];
        //number in left in inorder array after finding the root
        int numleft = inroot- instart;
        //creating left part , inroot ke left me saare left part hi hoga
        root ->left = createtree(inorder, instart, inroot-1, postorder, poststart, poststart+numleft-1, inmap);
        root ->right = createtree(inorder, inroot+1, inend, postorder, poststart+numleft, postend-1, inmap);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()){
            return NULL;
        }
        // storing all inorder valuue into map , jab root ko inorder me doondna ho jaldi se mil jaye 
        map<int, int> inmap;
        for(int i = 0; i< inorder.size();i++){
            inmap[inorder[i]] = i;
        }
        TreeNode* root = createtree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inmap);
        return root;
    }
};
