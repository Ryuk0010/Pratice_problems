class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rq;
        queue<int> dq;
        int n = senate.size();
        for(int i = 0; i < n; i++){
            if(senate[i] == 'R') rq.push(i);
            else if(senate[i] == 'D') dq.push(i);
        }
        while(!rq.empty() && !dq.empty()){
            int r = rq.front();
            int d = dq.front();
            rq.pop(); dq.pop();
            (r < d)? rq.push(r + n) : dq.push(d + n);
        }

        return (rq.size() > 0)? "Radiant" : "Dire";
    }
};