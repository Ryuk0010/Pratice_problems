class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int ele = tickets[k];
        int time = ele * n;
        for(int i = 0; i < n; i++){
            int timeleft = ele - tickets[i];
            if(tickets[i] <= ele){
                time -= timeleft;
            }
        }
        int bigger = 0;
        for(int i = k+1; i < n; i++){
            if(tickets[i] >= tickets[k]) bigger++;
        }
        
        return time-bigger;
    }
};