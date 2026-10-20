class Solution{   
public:    
    int minBitsFlip(int start, int goal) { 
        //for getting the answer how many bis is need to change in start to get the goal 
        //trick start xor goal = that gives a answer , in that answer we need count the set bits that is answer
        int ans = start^goal; 
        //now count using for loop
        int count = 0;
        for(int i = 0; i<32;i++){
                count += ans&1;
                ans = ans>>1; //division 2 thing
        }
        return count;
    }
};
            //In C++, you cannot access individual bits of an integer using ans[i]. Instead, use the right shift (>>) and bitwise AND (&) operators.
            /*if(ans[i] == 1){
                count++*/
                //ans&1 = 1, it means odd
                //ans&1 = 0, it means even
