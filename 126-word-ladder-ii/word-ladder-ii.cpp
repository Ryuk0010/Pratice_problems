class Solution {
public:
void dfs(string word, map<string, int>& mp, vector<string> sequence, vector<vector<string>>& ans, string& beginWord)
{
    cout<<word<<" "<<mp[word]<<endl;
    if(word==beginWord)
    {
        reverse(sequence.begin(), sequence.end());
        ans.push_back(sequence);
        reverse(sequence.begin(), sequence.end());
        return;
    }
    int step=mp[word];
for(int i=0;i<word.length();i++)
{
    char original=word[i];
    for(char ch='a';ch<='z';ch++)
    {
        word[i]=ch;
        if(mp.find(word)!=mp.end())
        {
            if(mp[word]==(step-1))
            {
                sequence.push_back(word);
            dfs(word, mp, sequence, ans, beginWord);
            sequence.pop_back();
            }
        }
    }
    word[i]=original;
}
}
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s;
        for(auto x: wordList)
        s.insert(x);
        map<string, int> mp;
        
        queue<pair<string, int>> pendingNodes;
        pendingNodes.push({beginWord, 0});
        if(s.find(beginWord)!=s.end())
        s.erase(beginWord);
        while(!pendingNodes.empty())
        {
            string word=pendingNodes.front().first;
            int step=pendingNodes.front().second;
            pendingNodes.pop();
            mp[word]=step;
            if(word==endWord)
            break;
            for(int i=0;i<word.length();i++)
            {
                int original=word[i];
                for(char ch='a'; ch<='z';ch++)
                {
                    word[i]=ch;
                    if(s.find(word)!=s.end())
                    {
                        pendingNodes.push({word, step+1});
                        s.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        //now our map has been build which is storing number of steps to reach the corresponding word
        //now we will backtrack from our endWord to beginWord call dfs for doing the same
        vector<vector<string>> ans;
        vector<string> sequence;
        sequence.push_back(endWord);
        dfs(endWord, mp, sequence, ans, beginWord);
        return ans;
    }
};