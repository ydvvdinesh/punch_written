// we are making a function that can tell us can we put the given cows very well or not and for other looping we are checking by the putting 1,2,3,4....... maxi-min kaha tak poosible hai jaha nahi we return the previous jaha because we are fnding the maximum in the minimum distance between two cows
// brute approach 

bool canweplace(vector<int> &stall, int distance, int cows){
    int p = stall.size();
    int countcows =1; // kitni cows ko jagah di hai 
    int last = stall[0]; // we have to put at the first , we are putting the first cow at first stall
    for (int i =1; i<p;i++){
        if (stall[i]-last>=distance){ // hume minmum distance chayiye and we have to look for the consuective cows kyuki unse hi minimum mil skti hai 
        countcows++; //ki humne next cows ko bhi jagah de di hai
        last = stall[i]; // ab next se calculate krenge
        }
        //else likhne ki jaroort nahi hai kyuki uski koui zarrort nahi hai if will handle
    }
    if (countcows>=cows) return true; //sari cows ko jagah de di that means wohi hi hume chayiye
    else{
        return false;
    }
}


class Solution {
public:
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mini = nums[0];
        int maxi = nums[n-1];

        for (int i=1;i<=(maxi - mini);i++){ //i is the distance at which are checking / it is maintained by us 
        if(canweplace(nums,i,k) == true){
            continue;
        }
        else{
            return i-1;
        }
        }
        return (maxi - mini);//if 2 hi cows hui hh bro
    }
};
