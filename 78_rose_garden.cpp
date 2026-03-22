//brute - check every for the search space
//question - wo minimum days btaoo jab saare flower bloom/ready ho jaye to make a bouquets

//we are making this function to tell us that can we make or not the bouquests
//checking_day is the day , on which we are checking that which which is bloomed/ready or not
bool possible(vector<int>& arr, int m, int k, int checking_day){
    int count =0;
    int noofboq = 0;
    //this loop we starting to check that which which flower is ready / bloom 
    for (int i =0; i<arr.size();i++){
        if(arr[i]<=checking_day){
            count +=  1;
        }
        //jaise hi nahi hai toh hum jaha tak bloom h waha tak dekhenge ki kitni bouqeuts ban skte hai amd thennwe will assign zero kyuki hume dobaare bhi consecutive counting karni hai
        //jaise hi possible nahi h toh suddenly no of bouquets nikalne hai
        else { 
            noofboq += (count/k); //m = no of bouquest and with k adjacnet ke saath chayiye
            count = 0;
        }
        //for yadi non possible ke baad possible aaye toh we will also find no of bouquets there
    }
    noofboq += (count/k); 
    if (noofboq>=m) return true;
    else{
        return false;
    }
}

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k>n) return -1;
        int n = bloomDay.size();
        //finding minimum blooms day for flower in the garden
        int mini = INT_MAX;
        for (int i = 0; i<n;i++){
            mini = min(mini,bloomDay[i]); //we went to every element and find the minimum day will taken by a flower to be bloomed in garden , kyuki koi bhi fool hum use kr skte hai bouquets ko bane ke liye and hum bouqets tabhi bnayenge jab sab bllom ho jayenge ,  
        }
        int maxi = INT_MIN;
        //finding maximum blooms day for flower in the garden
        for (int i = 0; i<n; i++){
            maxi = max(maxi,bloomDay[i]);
        }
        if(m*k>n) return -1;
        //till here we get our search space 
        for (int i = mini; i<=maxi; i++){
            if(possible(bloomDay,m,k,i) == true){
                return i;
            }
        }
        return -1;
    }
};
