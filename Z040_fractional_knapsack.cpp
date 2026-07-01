//optimal approach - greedy approach - hume maximum value nikalni hai jise hum carry/store kar sake but remeber hume give wieight ya capacity ke aandr rhena hai 
//key idea - maximise value nikalni hai iska matlab hai hume greed hai jada value ki
//toh what we will do we cannot go t the item/position which has highest value , lets suppose we want to maximum and it reches the capacity in 1 pass , then baaki toh check hi nahi huye na 
//so we will find per unit capacity , 1unit capcity me kitne value aarahi hai and jiska ratio jada aaye usse traverse krte jayenge in decreasing order 
class Solution {
public:
    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
        int n = val.size();
        // {ratio, value, weight} here we are storing the pair
        vector<pair<double, pair<long long, long long>>> arr;

        //ye hi core hai question ka 

        //declare a array to store the ratio and its value 
        for(int i = 0; i < n; i++) {
            double ratio = (double)val[i] / wt[i];
            arr.push_back({ratio, {val[i], wt[i]}});
        }
        
        sort(arr.begin(), arr.end(), greater<>());
        //using the greater int part put in the descending order, now aage move kro as ratio array
        long long totalval = 0;
        for(int i =0; i<n;i++){
            //becoz arr.first pe toh ratio hai na 
            long long value = arr[i].second.first;
            long long weight = arr[i].second.second;
            if(weight <= capacity){
                totalval += value;
                capacity -= weight;
            }
            else{
                //ratio * kitna bacha hai 
                totalval += arr[i].first * capacity ;
                break;
            }
        }
        return totalval;
    }
};
