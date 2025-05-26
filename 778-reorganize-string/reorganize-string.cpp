class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
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
        
        while(pq.size() >= 2) {
            auto one = pq.top(); 
            pq.pop();
            
            auto two = pq.top();
            pq.pop();
            
            ans.push_back(one.second);
            ans.push_back(two.second);
            
            one.first--;
            two.first--;
            
            if(one.first > 0)
                pq.push(one);
            
            if(two.first > 0)
                pq.push(two);
        }
        
        if(!pq.empty())
            ans.push_back(pq.top().second);
        
        return ans;
    }
};