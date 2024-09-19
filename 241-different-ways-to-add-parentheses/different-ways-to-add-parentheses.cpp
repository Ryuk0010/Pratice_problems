class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        int n = expression.size();
        for(int i = 0; i < n; i++){
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
                vector<int> left, right;
                left=(diffWaysToCompute(expression.substr(0, i)));
                right=(diffWaysToCompute(expression.substr(i+1)));
                for(auto it: left){
                    for(auto ti: right){
                        if(expression[i] == '+') ans.push_back(it+ti);
                        else if(expression[i] == '-') ans.push_back(it-ti);
                        else ans.push_back(it*ti);
                    }
                }
            }
        }
        if(ans.empty()) ans.push_back(stoi(expression));
        return ans;
    }
};