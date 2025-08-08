class Solution {
public:
void printRanks(const vector<vector<int>>& ranks, const string& teams) {
    for (char team : teams) {
        int idx = team - 'A';
        for (int count : ranks[idx]) {
            cout << count << " ";
        }
        cout << endl;
    }
}

    string rankTeams(vector<string>& votes) {

        string res = votes[0];
        int n = votes[0].size();

        vector<vector<int>> ranks(26, vector<int>(n));
        for(string s: votes){
            for(int i=0; i<n; i++){
                ranks[s[i] - 'A'][i]++;
            }
        }
        printRanks(ranks, res);
       
        sort(res.begin(), res.end(), [&](char x, char y){
            if(ranks[x-'A'] != ranks[y-'A'])
                return ranks[x-'A'] > ranks[y-'A'];

            return x < y;    
        });

        return res;
    }
};