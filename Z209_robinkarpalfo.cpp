//brute force approach - pattern ko text se krwyenge and jaaise hi compare hi match hoga toh starting index return karna hai woh kar denge
class Solution{
    public:
        vector <int> search(string pat, string txt) {
         int n = txt.size();
         int m = pat.size();
         vector<int> ans;
         //bada n hoga so n-m hume btayega last kaha pe rukna hai
         //first loop to taverse into text
         for(int i =0; i<=n-m; i++){
            bool flag = true;
            //now traverse into the pattern and checking time 
            for(int j =0; j<m; j++){
                // i+j , i+j me i cover karelnge and j ka compare hoga and i +j jaha hoga waha compare suru 
                if(pat[j] != txt[i+j]){
                    flag = false;
                    break;
                }
            }
                if(flag == true){
                    ans.push_back(i);
                }
         }
         return ans;
        }
};
