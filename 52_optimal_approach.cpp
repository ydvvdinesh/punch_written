class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0;
        int el1= INT_MIN;
        int cnt2 =0;
        int el2 = INT_MIN;
        //might be element ye hoga and niche jaake uska verfication kr lenge 
        for (int i = 0; i<n;i++){
            if(cnt1 == 0 && nums[i] != el2){ // yadi ek if , else of chla upper waala toh niche waalo ko ignore maarke jayega
                cnt1 = 1;
                el1 =nums[i];
            }
            else if(cnt2 == 0 && nums[i] != el1){ //ye edge casee is liye rakha hai ki dono element same na ho 
                cnt2 = 1;
                el2 = nums[i];
            }
            //yaha tak dono element hume maan liye , ki might be ye hi hai ab ye algo in dono ke hisab se chlenga and for loop isko last me check kregi 
            else if (el1 == nums[i]) cnt1++;
            else if (el2 == nums[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        // checking of both elements
        vector <int> ls;
        cnt1 =0;
        cnt2 = 0;
        int min = (int)(n/3) + 1;
        for (int i =0; i<n;i++){
            if(el1==nums[i]) cnt1++;
            if(el2==nums[i]) cnt2++;
        }
            if(cnt1 >= min){
                ls.push_back(el1);
        }
        if(cnt2 >= min){
                ls.push_back(el2);
        }
     return ls;
    }
};
