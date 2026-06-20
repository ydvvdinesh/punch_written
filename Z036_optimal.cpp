//optimal approach - we will put two pointer top and down , top at the first and down on the last and , what we will do we pick a pair if one knows another and another know him then we will move the pointer by because woh person elimante ho jaye jiski possiblity nahi hai dry se prefect smj jaoohgr, 
//we will pick a pair like [2][3] , we will check it , then we gor the inverse [3][2] and check which can`t be 
class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        int n = M.size();
        int top = 0;
        int down = n - 1;
        while (top < down){
            if(M[top][down] == 1){ // top knows down , mtlb top toh nahi hai celeb kyuki celeb kisi ko nahi jante, move top
            top = top +1;
            }
            else if(M[down][top] == 1){//down knows top, yadi koi kisi ne jaane hai toh woh toh celebrity nahi so eliminate that and move to the next part
            down = down -1;
            }
            //yadi dono ek dusre ko nahi jante 
            else{
                top++;
                down--;
            }

            if(top>down) return -1;
            //if top and down stands on position
            if(top == down){
                for(int i =0; i<n; i++){
                    if (i == top) continue; //diagonal element
                    // column =1 , sab mujhe jante hai  row 0 , me kisi ko nahi janta 
                    if(M[i][top] == 1 && M[top][i] == 0){
                        return top;
                    }
                    else{
                        return -1;
                    }
                }
            }
        }
        return top; 
    }
};
