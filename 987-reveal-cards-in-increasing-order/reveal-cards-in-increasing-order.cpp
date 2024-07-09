class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        queue<int> q;
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) q.push(i);
        int i = 0;
        while(!q.empty()){
            int ind = q.front();
            q.pop();
            q.push(q.front());
            q.pop();
            ans[ind] = deck[i];
            i++;
        }
        return ans;
    }
};