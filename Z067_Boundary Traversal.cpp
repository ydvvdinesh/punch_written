/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
 * };
 **/

// easy hai - we are going into anticlockwise directions,
// hum sabse phele left ko lenge excluded leaf node
// then leaf node ko
// then hum right boundary ko lenge but reverse order me and excluded leaf node
//
// leaf boundary lenge that means left me pehle left lenge,
// aur right me pehle right lenge, yadi right nahi hai toh left lenge.
// left waale me priority left rhegi and right waale me priority right rhegi.
//
// in last hum sab ko store krenge in a array.
//
// first we have to create a function that tells if you are leaf node
// and leaf node ko preorder se dekh lenge.

class Solution {
public:

    bool isleaf(TreeNode* root) {
        return (root->left == NULL && root->right == NULL);
    }

    // till now we created the function which tells us which is leaf node or not.

    // now we have to iterate through the left side
    void leftpart(TreeNode* root, vector<int>& ans) {

        TreeNode* curr = root->left;

        while (curr != NULL) {

            if (!isleaf(curr)) {
                ans.push_back(curr->data);
            }

            if (curr->left != NULL) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }
    }

    // now we have to iterate through the right side,
    // we use a vector jisse hum reverse order me result nikal saken

    void rightpart(TreeNode* root, vector<int>& ans) {

        TreeNode* curr = root->right;
        vector<int> maintain;

        while (curr != NULL) {

            if (!isleaf(curr)) {
                maintain.push_back(curr->data);
            }

            if (curr->right != NULL) {
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        }

        for (int i = maintain.size() - 1; i >= 0; i--) {
            ans.push_back(maintain[i]);
        }
    }

    // last for leaf nodes, we directly put them into array using preorder

    void leafpart(TreeNode* root, vector<int>& ans) {

        if (root == NULL)
            return;

        if (isleaf(root)) {
            ans.push_back(root->data);
            return;
        }

        leafpart(root->left, ans);
        leafpart(root->right, ans);
    }

    vector<int> boundary(TreeNode* root) {

        vector<int> ans;

        if (root == NULL)
            return ans;

        // Add root only if it is not a leaf
        if (!isleaf(root))
            ans.push_back(root->data);

        leftpart(root, ans);
        leafpart(root, ans);
        rightpart(root, ans);

        return ans;
    }
};
