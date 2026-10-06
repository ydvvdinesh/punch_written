//s ko rotate karna hai yadi at any flip it will become goal then retunrrn otherwise return true
/*
s = abcde
at one flip - bcdea
at 2 flip - cdeab
at 3 flip - deabc , jitni flip bole utne eelement uthoo and same order mai last mai rakh do  
*/
//optimal
class Solution{	
	public:
		bool rotateString(string& s,string& goal){
            int n = s.size();
			//same size hona chyiye 
            if(s.size() != goal.size()){
                return false;
            }
        //used find function it will work like an algoritham we will read that 
        // here we are duplicate the string then we will find goal in it 
        string doubles  = s+s;
         // goal mila toh true, nahi mila toh false 
         return doubles.find(goal) != string::npos;;
		}
};
