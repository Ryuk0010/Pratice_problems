class Solution {
public:
    int minOperations(vector<int>& v, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>q;
        int n=v.size();
        for(int i=0;i<n;i++) q.push(v[i]);
        int c=0;
        while(q.size()>=2) {
            if(q.top()>=k) return c;
            long long a=q.top();
            q.pop();
            long long b=q.top();
            q.pop();
            long long x=min(a,b)*2+max(a,b);
            q.push(x);
            c++;
        }
        return c;
    }
};