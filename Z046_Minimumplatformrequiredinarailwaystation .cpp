class Solution{
public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        int n = Arrival.size();

        int maxintersection = 0;

        for(int i = 0; i < n; i++){
            int count = 1; // Current train

            for(int j = 0; j < n; j++){
                if(i == j) continue;

                if(
                    (Arrival[j] >= Arrival[i] && Arrival[j] <= Departure[i]) ||   // j arrives during i
                    (Departure[j] >= Arrival[i] && Departure[j] <= Departure[i]) || // j departs during i
                    (Arrival[i] >= Arrival[j] && Arrival[i] <= Departure[j]) ||   // i arrives during j
                    (Departure[i] >= Arrival[j] && Departure[i] <= Departure[j])   // i departs during j
                ){
                    count++;
                }
            }

            maxintersection = max(maxintersection, count);
        }

        return maxintersection;
    }
};
