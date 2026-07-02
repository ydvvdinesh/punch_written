//optimal - now we go with range based  with min and max two variable -  yadi opening mila toh dono 1 se increase , yadi closing mile toh 1 se decrease, yadi astrik mile toh teen case for both varibale , min me usse ek se ghtado and max se badho do woh hi t, becoz logically soche toh differnece one se hi chal raha hai
//concept isme bhi count ka hi hai bus humne count ko do variable me badal diya hai 
//two edge case - if starting m hi closing aaya toh hum min reset krdenge on 0 and max me aaya toj=h return false because last range negative nahi hogi
//key idea - {min, max} , yadi range 0 se start haithat means valid parenthsis hai , otherwise not
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int min = 0;
        int max = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                min++;
                max++;
            }
            else if(s[i] == ')'){
                min--;
                max--;
            }
            else{
                min--;
                max++; //by observation , besk karke dekh dekhlo , because differnece 1 ka hi rhega in additon and in subtraction , min me lower part aayrga and max higher waali range
            }
            if(min<0) min=0;
            if(max<0) return false;
        }
        //if(min == 0) return true;
        return min == 0;
    }
};
