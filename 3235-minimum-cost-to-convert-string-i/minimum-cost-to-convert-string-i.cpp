class Solution {
public:
int D[26][26];
void floid(vector<char>& original, vector<char>& changed, vector<int>& cost){
    fill(&D[0][0], &D[0][0]+26*26, INT_MAX);
    for(int i = 0; i < original.size(); i++){
        D[original[i]-'a'][changed[i]-'a'] = min(D[original[i]-'a'][changed[i]-'a'], cost[i]);
    }
    for(int i = 0 ; i < 26; i++) D[i][i] = 0;
    for(int k = 0; k < 26; k++)
        for(int i = 0; i < 26; i++)
            for(int j = 0; j < 26; j++)
                D[i][j] = min((long long)D[i][j], (long long)D[i][k]+D[k][j]);
}
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        floid(original, changed, cost);
        long long ans = 0;
        int n = source.size();
        for(int i = 0; i < n; i++){
            if(D[source[i]-'a'][target[i]-'a'] == INT_MAX) return -1;
            ans+=D[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};