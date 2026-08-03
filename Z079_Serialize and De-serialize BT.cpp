/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //vary easy one simple conversion is there using level order traversal, yadi null hai toh # daalo 
#include <sstream>
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "";
        }
        string s = "";
        // string to store the answer 
        // we are going to use level order 
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            // jab q me se node pop hogi usse phele woh use left and right daal ke jayegi
            if(node == NULL){
                s += "#,";//, using for seperating rhem
            }
            else{
                s += to_string(node->val) + ",";// convert integer to string that why we are using to_string function , later we ae adding commas for for addition
            }
            if(node != NULL){
                q.push(node->left);
                q.push(node->right);
            }
            
        }
        return s;
    }

//in deseriliaze we habe to construct the tree through 
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == ""){
            return NULL;
        }
        stringstream ss(data);
        string str;
        getline(ss,str,',');
        //<sstream> header that lets you treat a string like an input stream (similar to how cin works).
        //ss is the stream created
        //declaration of a string 
        //now first char is stored in the string
        //stoi - String TO Integer.
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
        // left child
        //getline is going to use do sperate , and move to next
        getline(ss, str, ',');
        if (str != "#"){
            TreeNode* leftnode = new TreeNode(stoi(str));
            node->left = leftnode;
            q.push(leftnode);
        }
        //right child
         getline(ss, str, ',');
         if (str != "#"){
            TreeNode* rightnode = new TreeNode(stoi(str));
            node->right = rightnode;
            q.push(rightnode);
        }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
/*
It has 3 arguments:
getline(input_stream, destination_string, delimiter);
So here:
ss → the stream from which we are reading.
str → the string where the extracted text will be stored.
',' → stop reading when a comma is encountered.

*/
