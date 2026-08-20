class Solution {
public:
    vector<int> succPredBST(TreeNode* root, int key) {

        TreeNode* successor = NULL;
        TreeNode* predecessor = NULL;

        while (root != NULL) {

            if (key > root->data) {
                predecessor = root;
                root = root->right;
            }

            else if (key < root->data) {
                successor = root;
                root = root->left;
            }

            else {
                // key == root->data

                // Find predecessor:
                // largest value in left subtree
                TreeNode* temp = root->left;

                while (temp != NULL) {
                    predecessor = temp;
                    temp = temp->right;
                }

                // Find successor:
                // smallest value in right subtree
                temp = root->right;

                while (temp != NULL) {
                    successor = temp;
                    temp = temp->left;
                }

                break;
            }
        }

        return {
            predecessor ? predecessor->data : -1,
            successor ? successor->data : -1
        };
    }
};
