class MyCalendarTwo {
public:
    vector<pair<int, int>> singleR;
    vector<pair<int, int>> doubleR;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto it: doubleR){
            if(max(it.first, start) < min(it.second, end)) return false;
        }

        for(auto it: singleR){
            if(max(it.first, start) < min(it.second, end))
                doubleR.push_back({max(it.first, start), min(it.second, end)});
        }      
        singleR.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */