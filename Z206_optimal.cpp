class Solution {
public:
void reversething(string& s, int start, int end){
    while(start<end){
        swap(s[start], s[end]);
        start++;
        end--;
    }
}
    string reverseWords(string s) {
        int n = s.size();
        int i =0;
        int j =0;
        reversething(s,0,n-1);
        while(j<n){
            //jab tak space hai chlte jaoo
            while(j<n && s[j] == ' '){
                j++;
            }
            if(j>= n) break; //out of index 
            int start = i;
            //jab tak space na mile itne move karte jaoo, and move to left 
            while(j<n && s[j] !=' '){
                s[i] = s[j];
                i++;
                j++;
            }
            int end = i-1;
            //now reverse the complete thing agaom
            reversething(s, start, end);
            //now last step , give space betweeb the
            if(j<n){
                s[i] = ' ';
                i++;
            }
        }
        if(i>0 && s[i-1] == ' '){
            i--;
        }
       
        return s.substr(0,i);
    }
};
