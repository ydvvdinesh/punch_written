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
 //optimal approach we are using a property of a full binary tree , that is no of nodes = 2^lh - 1
 //so for every node we are checking the height of left subtree and rigth subtree and if they  equal that means full binary tree hai toh directly formulka use kardo and if equal nahi hai toh next check last me toh milega hi , but for that particular node = 1+ leftheight + right yadi qual nahi hai toh 
class Solution {
public:

    //function to find out left subtree height 
    int leftsubtree(TreeNode* root, int &hght){
        TreeNode* node = root;
        while(node != NULL){
            hght++;
            node = node->left;
        }
        return hght;
    }

    int rightsubtree(TreeNode* root, int &hght){
        TreeNode* node = root;
        while(node != NULL){
            hght++;
            node = node->right;
        }
        return hght;
    }

    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        // lets find out the height using function
        int num = 0;
        int lh = leftsubtree(root, num); // right me jaane ki jarroorrt hai nahi uske liye toh pehele se function lgaya hai
        int rh = rightsubtree(root, num);
        // if equal toh direct use formula
        if(lh == rh ) return (1 << lh) - 1; // 2^3 -1
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
