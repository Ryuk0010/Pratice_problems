class BrowserHistory {
private:
    stack<string> s1 , s2;
public:
    BrowserHistory(string homepage) {
        s1.push(homepage);
    }
    
    void visit(string url) {
        s1.push(url);
        while(!s2.empty()){
            s2.pop();
        }
    }
    
    string back(int steps) {
        while(s1.size() > 1 && steps > 0){
            string temp = s1.top();
            s1.pop();
            s2.push(temp);
            steps--;
        }
        return s1.top();
    }
    
    string forward(int steps) {
        while(s2.size()>0 && steps > 0){
            string temp = s2.top();
            s2.pop();
            s1.push(temp);
            steps--;
        }
        return s1.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */