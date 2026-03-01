//optimal one - phele saari row nikalo then usse se then unko saath me le aaya simple
//function for generating complete row
vector<int> generaterow(int row){
    vector<int> entire_row;
    long long ans = 1;
    entire_row.push_back(1); // because starting to toh one se hi hogi
    //no of row = no of element in the row
    for (int col_index = 1; col_index<row; col_index++){ // we work on zero index 
    // why we can`t start from 0 because o index pe toh humne phele hi one bhej diya hai
        ans = ans*(row-col_index);
        ans=ans/col_index;
        entire_row.push_back(ans); // har baar answer ki value dalte japp row khud create ho jayegi
    }
    return entire_row;
}
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // now we have to just geneate a colums and then all store to list
       vector<vector<int>> finalanswer;
       for (int i = 1;i<=numRows;i++){ // here indexing starts from 1 , toh eual toh use hoga smje
        finalanswer.push_back(generaterow(i));
       }
       return finalanswer;
    }
};
