//optimal approach - 3. brief - 1, yadi positve value hai asteriod ki toh right me move krega and -ve and hai toh left me move krega
//2. ulti direction hongi tabhi collid kr payega 
//3. yadi dono ka magnitude same hai dono destroy honge otherwise jiska bda hai woh woh apni present direct me aage bdega 
// we are going to use stack / list dono - lifo pe kaam karti koi bhi use krlo , tarika ek dum same hai but yadi stack kroge toh wo top then top.second me order dega toh hume fir reverse krna pdega jo hamari time complexity increase krega 
//compare hum absoulte value se compare krenge 
//note - hum stack/list me +ve store and -ve se check krenge , in one test case jaha sirf negative bache toh hi hum negative ko stack me daalenge
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int> li; // declare a list
        int n = asteroids.size();
        //now we have to traverse
        for(int i =0; i<n; i++){
            if(asteroids[i]>0){
                li.push_back(asteroids[i]);
            }
            //till now jo positive aata rhega hum usko list me daalte jayegnge bcz jab negative aayega toh hum comparison krenge
            //yadi negative hai, toh hum comparison krte jayenge and chote asteroids ko  delete krte jayenge jab taak hume koi abs value bdi nahi mil 
            else{ 
                while(!li.empty() && li.back()>0 && li.back()<abs(asteroids[i])){
                    li.pop_back();
                }
                //till now hum hum delte kr chuke hai small asteriod ko and hum ulti direction me mtlb +ve value uss abs value se bdi mil gyi hai
                if(!li.empty() && li.back() > 0 && li.back() == abs(asteroids[i])){
                    li.pop_back();
                }
                //yadi dono oppsite direction me hai and sign ulte hai toh , same value hai toh dono destroy ho jayenge 
                // yadi -ve bche or stack/lsit pura empty huwa mtlb a toh ek hi direction me jayenge
                //edge case
                else if(li.empty() || li.back()<0){
                    li.push_back(asteroids[i]);
                }
            }
        }
        return vector<int>(li.begin(), li.end());
    }
};

/*
list operation
list<int> l;
Insert
l.push_front(x);
l.push_back(x);
Delete
l.pop_front();
l.pop_back();
l.erase(it);
Access
l.front();
l.back();
Capacity
l.size();           // number of elements
l.empty();          // check if empty
Iterators
l.begin();          // first element iterator
l.end();            // one past last element
*/
