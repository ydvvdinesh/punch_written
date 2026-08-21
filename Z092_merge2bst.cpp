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
 //hasnext - kya agla element hai 
 // next - value dega next element ki 
 //approach - send all left to stack then all node then right 
class BSTIterator {
    stack<TreeNode*> mystack;
public:
//ye function sab node waalo ko stack me daal deta hai 
    void pushAll(TreeNode* node){
        while(node != NULL){
            mystack.push(node);
            node = node->left;
        }
    }

    
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    //till now we send all the left to the stack
    
    int next() {
        TreeNode* temp = mystack.top();
        mystack.pop();
        pushAll(temp->right); // right me push kiya 
        return temp->val;
    }
    
    //ki jis element pe jhum hai uske aage ko element hai ki nahi
        // Returns true if there is a next element in the iterator 
    bool hasNext() {
        return !mystack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
