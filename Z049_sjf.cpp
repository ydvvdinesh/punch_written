//optimal approach  = smallest excution time waale phele excute hongi , SJF its completely like os thing
//waiting time first wala hota hai ten usme excutuin time add hota hai then woh next keliye waiting time bnta hai
//key idea - hum smallest excution krna hai that means its a greedy approach 
class Solution {
  public:
    long long solve(vector<int>& bt) {
        int n = bt.size();
        int t = 0; //total excution time
        int wt = 0; //store the waiting time
        //sort it out 
        sort(bt.begin(),bt.end());
        for(int i =0; i<n; i++){
            wt += t;
            t += bt[i];
        }
        return (wt/n);
    }
};
