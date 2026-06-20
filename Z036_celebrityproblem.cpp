//celebrity prob - every one know him and he doesn`t know anyone
// know =1 don`t know = 0 
//brute approach - sabko traverse krenge and dekhenge jaante hai ki nahi simple
//trick
//column me 1 - mtlb kitne hume jante hai (total sum of colums give us direction no of people)
// row me 1 kitno ko hum jante hai 
// we will make two arr acc to mtlb kitne hume jante hai and and kitno ko hum jante hai and jab hum kitno ko jante hai woh zero and hume kitne jante usme kuch number hsi that`s means wo celeb hai
//kitna admi mne jaani hi in colum and in row kin kin ne me jaanu hu celeb 
class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        int n = M.size();
        int m = M[0].size();
        //chayi m lelo ya n , square matrix hai so same size hoga
        vector<int> knowme(n,0); // this array  the number of  kitne muje jante hai  // ye column m
        vector<int> iknow(n,0); // me kitno ko janta hu // row me khlega 
        // now traverse through the matrix 
        for(int i = 0; i<n; i++){
            for(int j =0; j<n; j++){
                if(M[i][j] == 1){
                    knowme[j]++;
                    iknow[i]++;
                }
            }
        }
        for(int i = 0; i<n; i++){
            if(knowme[i] == n-1 && iknow[i] ==0) return i;
        }
        return -1;
    }
};
/*
Intuition (thoda polish karke)
Row i ka sum batata hai ki person i kitne logon ko jaanta hai.
Column j ka sum batata hai ki person j ko kitne log jaante hain.
Celebrity ki conditions:
Wo kisi ko nahi jaanta ⇒ row sum = 0
Baaki sab usko jaante hain ⇒ column sum = n-1
*/
