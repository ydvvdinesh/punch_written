//optimal approach - we sort both array and arrival me +1 and departure me -1 , ho gaya answer ustime kitna maximum gaya aane hai jaane ka , utne hi platform chayiye 
//aaya toh woh time ke hisab se chlega , 2 array , jo small usme phele acction
// do pointer hai hmesha small waale pe phele action liya aayega 
//keyidea - ek aadmin baitha hai eg station master woh ek raha and ab woh count kar raha kitni platform used ho rahe hai usse time period me , toh yadi usko khaali deekha koi platform toh train udhar hi mangayega
//we go with two pointer approach 
class Solution{
    public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        int n = Arrival.size();
        sort(Arrival.begin(), Arrival.end());
        sort(Departure.begin(), Departure.end());
        int i = 0; //arrival pointer 
        int j = 0; //departure pointer 
        int count =0;
        int maxcount = 0;
        while(i < n){ // kyuki arrival hi nahi hoga toh departure kaise hoga
        if(Arrival[i] < Departure[j]){ //arrival chota , mtlb train aachuki hai
            count++;
            i++;
        }
        else{ // kyuki departure chota , ab uspe action lenege 
            count--;
            j++;
        }
        maxcount = max(count, maxcount);
        }
        return maxcount;
    }
};
