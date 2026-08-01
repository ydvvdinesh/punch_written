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
 // construct karna hai inorder ke hisab se 
class Solution {
public:

    //function used to vreate the tree using preorder and inorder traversal 
    TreeNode* createtree(vector<int>& preorder, int prestart, int preend, vector<int>& inorder,int instart, int inend, map<int, int> inMap){
        //function is taking all details of preorder and iorder and return us the root 
        // we are going in making sub part or subtree, after o
        // we are playing by making parts 
        if(prestart> preend || instart> inend) return NULL;
        //prestart is the index from where the first ele,ent of preorder array will started
        // and jab hum construct krenge toh root humesh apre order ka first hoga 
        TreeNode* root = new TreeNode(preorder[prestart]);
        //inorder me kaha hai root 
        int inroot = inMap[root->val];
        //it will give us the index
        int numleft = inroot - instart;
        // left me kitne bnde hai inorder array me 
        // create left and right part like same , bus har baar subtree ke starting and ending change karne pdenge 
        //like window me kaam hoga and window consist all dtata of nodes
        root->left = createtree(preorder, prestart+1,prestart+numleft, inorder, instart, inroot-1,inMap); 
        /*
        prestart+1 - yadi left me ja rahe hai toh jo root leli usse next lenge na , kyuki phele root aati hai
        prestart+numleft - ye end point hai kaha tak lena rooot s,je
        instart - ye toh starting se window rakhni ha
        inroot-1 - inorder me jo inroot aaye usse phele tak raakhni, inroot mtlb rpreorder root in inorder 
        */
        //we get the left value of it 
        // we have to think about left
        root->right = createtree(preorder,prestart+numleft+1, preend, inorder, inroot+1, inend, inMap);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // we are creating a map to store all inorder node into map lkater we use that in jab jum inorder me preorder ke root ka index ka pta puchna hoga jab
        map<int, int> inmap;
        for(int i =0; i<inorder.size();i++){
            inmap[inorder[i]] = i;
            //map will storing the number and at what index it is 
        }
        TreeNode* root = createtree(preorder, 0, preorder.size()-1, inorder,0, inorder.size()-1, inmap); 
        return root;
    }
};
