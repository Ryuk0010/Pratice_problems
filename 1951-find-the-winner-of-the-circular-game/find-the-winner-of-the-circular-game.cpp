class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i = 1; i <= n; i++) q.push(i);
        while(q.size() > 1){
            int popFromQ = k+1;
            while(popFromQ--){ 
                int topEle = q.front();
                q.pop();
                if(popFromQ == 1)break;
                q.push(topEle);
            }
        }
        return q.front();
    }
};