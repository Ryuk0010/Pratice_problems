class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(auto it: s){
            if(st.empty()){ 
                st.push(it);
                continue;
                }
            if(st.top() == '('){
                if(it == ')')
                st.pop();
                else st.push('(');
            }
            else{
                st.push(it);
            }
        }
        return st.size();
    }
};