class AllOne {
public:
    unordered_map<string, int> mpp;
    set<pair<int, string>> st;
    AllOne() {
        mpp.clear();
    }
    
    void inc(string key) {
        int n = mpp[key];
        mpp[key]++;
        st.erase({n, key});
        st.insert({n+1, key});
    }
    
    void dec(string key) {
        int n = mpp[key];
        if(n == 1){
            mpp.erase(key);
            st.erase({n, key});
            return;
        }
        mpp[key]--;
        st.erase({n, key});
        st.insert({n-1, key});
    }
    
    string getMaxKey() {
        if(!st.empty()) return st.rbegin()->second;
        return "";
    }
    
    string getMinKey() {
        if (!st.empty()) return st.begin()->second;
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */