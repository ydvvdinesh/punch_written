// fixture of 1 and 2 bus farak ye hai , jaise hum 2 me saare possible transction kar rahe the isme sirf 2 hi kar skate hai so un do transscation mai hi aapko sabse maximum profit find out karna hai 
class Solution{
public:
//on which day , buy kiya ki nahi , cap maximum transctionkitni le skte hai which is 2
int func(int day, int buy, int cap,vector<int> arr,vector<vector<vector<int>>>& dp){
    int n = arr.size();
    //base case
    if(cap == 0){
        return 0;
    }
    if(day == n){
        return 0;
    }
    if(dp[day][buy][cap] != -1){
        return dp[day][buy][cap];
    }
    //ek din mai dono me se ek hi operation yaha hum uss din buy karenge yaha sell krenge 
    //now yadi buy kiya toh , do hi cheeze hongi take that day or don`t take that day 
    int profit = 0;
    if(buy == 1){
        //yadi phele buy kiya and why -ve aayega because it tell us ki hmari traf se kitni value isme day , kyuki jab humne buy kiya toh hmare paise toh khatam huwa na, yadi buy kar liya toh waah zero hi aayega
        //yadi buy ki toh capcity utni hi rhegi , kyuki capcity kab ghetgi jab ek puri iteration hogi buy then sell  
        int a1 = -arr[day] + func(day+1,0,cap,arr,dp);
        //ye manga hai dura lenge toh hmari traf se kuch negative huwa nahi , hmare paass toh utne paise hi honge jitne phle the , buy waali 1 rakhenge , becoz hum waah buy kar skte hai 
        int a2 = 0 + func(day+1,1,cap,arr,dp);
        profit = max(a1,a2);
    }
    //
    else{
        //yadi woh din liya sell karne ko 
        //jab sell krenge toh hmare pass toh paise badhenge
        //yadi sell hogaya toh matalb ek iteration ho gaya hai
        int b1 = arr[day] + func(day +1,1,cap-1,arr,dp);
        //if we are not taking that day for selling, that means that can`t add value or money to us 
        int b2 = 0 + func(day+1,0,cap,arr,dp);
        profit = max(b1,b2);
    }
    return dp[day][buy][cap] = profit;

}
    int stockBuySell(vector<int> arr, int n){
        //now we are using three parameter toh do dp array bhi three parameter pe jayega
        //n, yaha 0 or 1 mltb total 2, cap teen ho skte hai 0,1,2 , toh total 3 huye and -1 declare krenge 
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return func(0,1,2,arr,dp); // capcity do hai na 
    }
};
