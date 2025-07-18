class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        priority_queue<pair<int, char>> pq;
        vector<int> count(26, 0);
        for(char &ch : s) {
            count[ch-'a']++;

            if(count[ch-'a'] > (n+1)/2) return "";
        }
        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(count[ch-'a'] > 0) {
                pq.push({count[ch-'a'], ch});

            }
        }

        string ans = "";
       while(pq.size() > 1){
            auto ele1 = pq.top(); pq.pop();
            ans += ele1.second;
        
            auto ele2 = pq.top(); pq.pop();
            ans += ele2.second;
            
            if(--ele2.first > 0) pq.push(ele2);
            if(--ele1.first > 0) pq.push(ele1);
        }

        if(!pq.empty()) {
            ans += pq.top().second;
        }

        return ans;
    }
};