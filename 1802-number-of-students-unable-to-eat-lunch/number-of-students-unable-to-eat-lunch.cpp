class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt0 = 0, cnt1 = 0;
        for(int it: students){
            if(it) cnt1++;
            else cnt0++;
        }

        for(int it: sandwiches){
            if(it){
                if(cnt1 > 0) cnt1--;
                else return cnt0;
            }
            else{
                if(cnt0 > 0) cnt0--;
                else return cnt1;
            }
        }   
        return 0;
    }
};