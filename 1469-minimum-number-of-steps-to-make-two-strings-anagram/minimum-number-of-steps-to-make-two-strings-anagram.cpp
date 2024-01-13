class Solution {
public:
    int minSteps(string s, string t){
      vector<int>vFreq(26,0);
      for(int i=0;i<s.length();i++){
        vFreq[s[i]-'a']++;
      }
      for(int j=0;j<t.length();j++){
        vFreq[t[j]-'a']--;
      }
      int ans=0; 
      for(int i=0;i<26;i++){
        if(vFreq[i]>0)
        ans+=vFreq[i];
      }
    return ans;
    }
};