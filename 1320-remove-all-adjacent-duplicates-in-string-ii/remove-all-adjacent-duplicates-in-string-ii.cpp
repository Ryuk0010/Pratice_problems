class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(int i = 0; i < s.length(); i++){
            if(!st.empty() && st.top().first==s[i]){
                char ele = st.top().first;
                int cnt = st.top().second;
                st.pop();
                cnt++;
                st.push({ele,cnt});
            }
            else{
                st.push({s[i],1});
            }
            if(!st.empty() && st.top().second == k){
                st.pop();
            }
        }

        string ans = "";
        while(!st.empty()){
            char temp = st.top().first;
            ans.push_back(temp);
            int freq = st.top().second;
            freq--;
            st.pop();
            if(freq != 0) st.push({temp, freq});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};