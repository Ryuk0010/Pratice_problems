class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<int> st;
        for(char it: expression){
            if(it != ')' && it != ',') st.push(it);
            if(it == ')'){
                vector<char> exp;
                while(!st.empty() && st.top() != '('){
                    char c = st.top();
                    st.pop();
                    if(c == 't')exp.push_back(true);
                    else if(c == 'f')exp.push_back(false);
                }
                
                st.pop();
                char c = st.top();
                st.pop();
                bool ans = exp[0];
                if(c == '&') for(auto it: exp) ans &= it;
                else if(c == '|') for(auto it: exp) ans |= it;
                else for(auto it: exp) ans = !ans;

                if(ans)st.push('t');
                else st.push('f');
            }
        }

        return (st.top() == 't')?true: false;
    }
};