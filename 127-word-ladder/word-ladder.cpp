class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        int n = wordList.size();
        for(int i = 0; i < n; i++) st.insert(wordList[i]);

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            string word = top.first;
            int step = top.second;
            if(word == endWord) return step;
            
            for(int j = 0; j < word.size(); j++){
                char org = word[j];
                for(int i = 'a'; i <= 'z'; i++){
                    word[j] = i;
                    if(st.find(word) != st.end()){
                        q.push({word, step+1});
                        st.erase(word);
                    }
                }
                word[j] = org;
            }
            
        }
        return 0;
    }
};