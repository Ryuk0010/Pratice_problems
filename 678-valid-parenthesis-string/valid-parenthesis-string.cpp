class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open, star;  // stores ( & * indices
        int n = s.length();

        // Traversing balances ')' brackets
        for(int i = 0; i < n; i++) {
            if(s[i] == '(')
                open.push(i);
            else if(s[i] == '*')
                star.push(i);
            else {
                if(!open.empty())
                    open.pop();
                else if(!star.empty())  // all stars in stack are automatically came before curr ')'
                    star.pop();
                else  // if ')' don't balance
                    return false;
            }
        }

        // Now process leftover '('
        while(!open.empty()) {
            if(star.empty())  // no stars available
                return false;
            else if(open.top() < star.top()) {
                open.pop();
                star.pop();
            }
            else    // open.top() > star.top()
                return false;
        } 
        
        return true;
    }
};