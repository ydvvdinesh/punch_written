//code simple hai bus thoda concept confusing hai
//question - For each complete path, calculate its maximum single-step difference. Then among all paths, choose the path whose maximum is the smallest.
//1.for each step , we are taking it tells how big the height change is when you make each move.

// jitna height jaada change kregi utna hi diffucult hoga hmare liye hike karna

//2. then we take the maximum of all the differnce of height change , now what it represent most difficult single move on this route, which is the greatest number we get during height change

//3. the most diffcult single move , or most height difference tells us the maximum or entire effort in this path is that maximum number which we get from the step1 , height differnce when we make the move
//entire effort of 1 paath ke me maximum kitna effort height chadne me lagya woh hi count hota hai 

//Why do we then find the minimum effort? Because we have many possible routes to reach the destination.

//neweffort variable , hum maixmum effort btayega uss root , and which is shortest woh priority queue btayegi using dijsktra

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        //differnce of heights/cell , {row of that mountain, col}(jispe hum hai) 
        priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int,int>>>
        > pq;
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        dis[0][0] = 0; //khud ki khud se height toh zero hi hogi
        pq.push({0,{0,0}});

        // techie , all four direction
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff  = it.first;
            //height differnce of between two cells , jiski queue se demand ki usse paath pe chalna hai toh uska hi differnce store krenge
            // row col or cell or mountain jaha pe khde hai
            int row = it.second.first;
            int col = it.second.second;
            if(row == n-1 && col == m-1) return diff;
            //now traverse to neghibour of four direction
            for(int i = 0; i<4; i++){
                int newrow = row + drow[i];
                int newcol = col + dcol[i];
                //check validity
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m){
                    //entire effort that particular path jis hum aarahe hai 
                    // priority queue ke hisab se path set hote hai 
                    //jab jiska number tan hum uss path ke entire effort ko count krenge 
                    //har cell or mountain ki height ka differnce har baar niklenga path me jaha jaada effort woh return kar denge
                    int entireeffort = max(abs(heights[row][col] - heights[newrow][newcol]), diff);
                    if(entireeffort < dis[newrow][newcol]){
                        dis[newrow][newcol] = entireeffort;
                        pq.push({entireeffort, {newrow, newcol}});
                    }
                    //yadi kaam effort mila toh hum usko replace kr denge 
                }
            }
        }
        return 0; //unreachable
    }
};

//now my concept jisse ek minute me samaj aajayega , hum chalna and height difference count karna , height differnce mtlb height changes , ab jitni height change hogi toh utna hi effort lgega hike karna me toh we simply say , effort we have to put to hike that height = height differnce between two mountains and jab saare height or mountain cover kar lenge toh hum dekhnege ki uss path me konsi height ko hike karne me sabse jaada effort lga hai , woh hi uss path ka entire effort count krenge , jo jada mehnat ki hai woh toh boli jaati hai , in last hume btana hai which route is eaisesst to hike toh jisme sabse kam effort lga woh hi na , toh woh priority queue har baar select kar hi raha question me uska kaam hi yehi sabse phele minium waale ko pakdo 
//We use the distance array because we need to remember the best effort we have found so far for reaching every cell/mountain.
//Keep track of the best value found so far for reaching each node/cell.yadi usse kam value me woh cell/mountain hike ho raha hai toh hum waale me kam height difference waale ko daal denge
