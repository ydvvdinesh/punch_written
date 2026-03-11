//brute force approach - ek loop number - 1 to n mtlb (natural number) ki chalyenge and dusri vali array ke element ki ,  yadi koi number ek baar se jaada aaya toh repeating h and yadi ye 2 baar aaya toh ek bach gaya hoga nahgi kyuki usi jagah duplicae aa gaya 
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int repeating = -1;
        int missing = -1;
        for (int i = 1;i<=n;i++){
            int count =0;
            for (int j =0; j<n; j++){
                if (arr[j]==i){
                    count ++;
                }
            }
            if (count == 2){ 
                repeating = i;
            }
            if (count == 0){
                missing =i;
            }
            if (repeating != -1 && missing != -1){
                break;
            }
        }
        return {repeating, missing};
    }
};
