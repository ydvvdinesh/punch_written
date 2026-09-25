//we have to find the letter of word , into given board(2d matrix), yadi mila toh true otherwise false , bus 4 direction mai hi ja skate hai, 
//how recursion is solving this - we pick a starting point , then move to another which is negihbour and check that word is going into correct way or not 
//mainly hume board mai traverse karna hai , har cell ke pass 4 option honge , all 4 directions , jidr jayenge uska letter add hojayega ,a nd jaha traverse kiya usko empty bna do , kyuki ek part me ek bar ek le skate ho 
// all direction ke letter ke hisab se jayenge, and uska cell ka letter add karte jayenneg, jaha bhi word or jis letter pe hum kaam kar rahe woh gaat huwa toh woh false, and yadi ek bhi coreect traverse kar gaya last tal toh true return lar denge , yadi ek true bhi mila that means , hum word mil gaya 
class Solution {
public:

//recursion function - ek letter ke pass 4 tarike hai saari direction me jaana hai wohi seekhta hai 
//i and j use to point the cell in tteh board 
bool f(int ind, int i, int j, vector<vector<char> >& board, string word ){
    bool ans = false;
    int n = board.size(); //rows
    int m = board[0].size();//columns
    //yadi board empty hai yaha jo letter chayiye tha mila nahi 
    if(board[i][j] == '#' || board[i][j] != word[ind]){
        return false;
    }
    // If all characters of the word are found
    if(ind == word.size()-1){
        return true; 
    }
    
    // current cell ko save kar lo 
    char temp = board[i][j];
    //yadi jo traverse huwa usko empty bnaoo
    board[i][j] = '#';
    //jab empty ho gaya now traverse to all 4 directions , yadi ek bhi true aaya toh true hi aayega 
    //top, |= or equal to sign
    if(i-1>=0){
        ans |= f(ind+1, i-1, j, board, word);
    }
    //bottom
    if(i+1<n){
        ans |= f(ind+1, i+1, j, board, word);
    }
    //left 
    if(j-1>=0){
        ans |= f(ind+1, i, j-1, board, word);
    }
    //right
    if(j+1<m){
        ans |= f(ind+1, i, j+1, board, word);
    }
    // BACKTRACKING // cell ko wapas original character bana do 
    board[i][j] = temp;
    return ans;
}

//board me doondna hai and word give hoga ek ek letter jode chalna 
    bool exist(vector<vector<char> >& board, string word) {
        int n = board.size(); //rows
        int m = board[0].size();//columns
        //use these loops we are finding the starting point
        for(int i =0; i<n;i++){
            for(int j = 0; j<m; j++){
                //iss if se jitni possible starting point hai woh mil jayenge, yadi condition nahi chlai toh sidha false return kardo kyuki jab first hi nahi mila toh saare kasie milemge 
                if(word[0] == board[i][j]){
                    if(f(0,i,j,board,word) == true){
                        return true;
                    }
                }
            }
        }
    return false;
    }
};
