class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for(int i = 0; i < n; i++){
            if(asteroids[i] > 0) st.push(asteroids[i]);
            else{
                while(!st.empty() && st.top() > 0 && st.top() < -asteroids[i]){ 
                    st.pop();
                }
                if(st.empty() || st.top() < 0) st.push(asteroids[i]);
                if(!st.top() || st.top() == -asteroids[i])st.pop();
            }
        }
        vector<int> ans(st.size());
        int i = st.size()-1;
        while(!st.empty()){
            ans[i--] = st.top();
            st.pop();
        }
        return ans;
    }
};