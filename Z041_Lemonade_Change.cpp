//dukkan chalni hai teen currency me me 5 , 10 , 20 itni hi cureency 
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0;
        int ten = 0;
        for(int i = 0; i<n; i++){
            if(bills[i] == 5){
                five = five + 1;
            }
            else if(bills[i] == 10){
                if (five >=1){
                    // toh 10 collect krenege and bhai ko 5 return kr denge
                    ten = ten + 1;
                    five = five - 1;
                }
                else{
                    //yadi 5 nahi hai toh sab kuch false ho jayega
                    return false;
                }
            }
            else{
                // 20 hai toh do case hai yaha toh 10 ,5 ho yaa teen 5 ho return karne ke liye , rate toh 5 hi hai so 15 toh return karne pdenege
                if(five>= 1 && ten >=1){
                    five--;
                    ten--;
                }
                else if (five >= 3){
                    five -=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
