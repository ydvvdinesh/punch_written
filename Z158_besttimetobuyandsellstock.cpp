//most important - hume maximum profit nikalna hai , toh saste mai khardne hai and mange mai bchna hai 
// we use a trick , jis day/ index pe khde hai waah se last tak jo minimum uska track rakhenge and jab un dono ko subtract krenge toh maximum result milenge 
class Solution{
public:
    int stockBuySell(vector<int> arr, int n){
        int mini = arr[0]; //hum ye maanke chlenge phee din guste hi but kar liya 
        int profit =0;
        for(int i =0; i<n; i++){
            int cost = arr[i]-mini; //selling price - buying price
            //sabka cost nikalne ke baad jiska maximum hoga woh return krenge 
             profit = max(cost,profit);
            //minimum ka count rakna hai toh toh usse pta rhe ki konse din karide toh mimum pe mil jayega and phir usko maximum pe bch de
            //ya kis din pe minimum mil raha hai
            mini = min(mini, arr[i]);
        }
        return profit;
    }
};

