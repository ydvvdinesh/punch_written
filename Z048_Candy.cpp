//bruteforce - 1. har ek bache ke pass atleast ek candy hogi 
//2. jis bache ki rating jada hogi usko jada candy milegi ha per apne number se jaada honi chayiye
// and candy 1 se start krnege and dete jayenge and 
//key idea , jitne se condtion puri ho utne hi deni hai baaki apne pass rakhni hai 
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> leftarray(n); //isme left array se compare karne ke baad candy store karni hai 
        vector<int> rightarray(n); // isme candy hi store hogi but right waale se compare karne ke baad 
        //and uss soefic position pe jiske pass candy jada hogi jo answer me return krenge 
        // left me candy store kar rahe hai
        int sum = 0; // saari candy ka sum rakhega 
         // Left to Right
        leftarray[0] = 1;
        for(int i = 1; i<n ; i++){
            if(ratings[i] > ratings[i-1]){
                leftarray[i] = leftarray[i-1] + 1;
                
            }
            else{
                leftarray[i] = 1;
            }
        }

         // Right to Left
        rightarray[n-1] = 1;
        //right me store krnege 
        for(int i = n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                rightarray[i] = rightarray[i+1] +1; // right waale ki value me ek increase karna hai 
            }
            else{
                rightarray[i] = 1;
            }
        }
        // finding maximum 
        for(int i = 0; i<n; i++){
            sum += max(leftarray[i], rightarray[i]);
        }
        return sum;
    }
};
