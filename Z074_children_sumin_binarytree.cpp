/* Structure of a Tree Node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

//parent value = sum of both children in all nodes of the tree, convert a tree into a tree which follows the property parent value = left and right children sum 

//approach for solving this 
//assgining ke time do condition hogi , one is yadi children ka sum smaller hai toh hum parent waala children ki value ko denege
// yadi bda hai toh phir parent ki value change kro and hatam 

//when traversing downwared hum assigning krenge and return krnege toh total krenege for the parent
//assgingin if the sum of both children is smaller then parent toh left and right child me parent ki value assign karte jayenge 
// return ke time jo assign huye the unka add karke parent ki value jaan lenge 
//on moving downward assging the value to children and on moving upward assginging the value to their parent 

class Solution {
public:

    void changeTree(Node *root) {

        //base case
        if(root == NULL){
            return;
        }

        int child = 0;

        //assigning ke time check krenge
        if(root->left != NULL){
            child += root->left->data;
        }

        if(root->right != NULL){
            child += root->right->data;
        }

        //child variable contains the sum of children

        //yadi sum greater hai, parent se toh parent ki value change kro
        if(child >= root->data){
            root->data = child;
        }

        //yadi sum smaller hai , toh assginging kro children ko
        else{
            if(root->left != NULL){
                root->left->data = root->data;
            }

            if(root->right != NULL){
                root->right->data = root->data;
            }
        }

        //assging complete , now time to move left and then comeback upward , preorder
        changeTree(root->left);
        changeTree(root->right);

        //during the time of returning
        int tot = 0;

        if(root->left != NULL){
            tot += root->left->data;
        }

        if(root->right != NULL){
            tot += root->right->data;
        }

//Iska kaam hai children ki updated values ko add karke parent ki value banana.
        //leaf node ko change nahi karna
        if(root->left != NULL || root->right != NULL){
            root->data = tot;
        }
    }
};
