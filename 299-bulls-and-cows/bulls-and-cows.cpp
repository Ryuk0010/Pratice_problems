class Solution {
public:
    string getHint(string secret, string guess)
    {
        int n=secret.size();
        int countb=0;
        int countc=0;
        string ans= "";
        for(int i=0;i<n;i++ )
        {
          if(secret[i]==guess[i])
            { 
                countb++;
                guess[i]=-1;
                secret[i]=-1;
            }   
        }
        
        for(int i=0;i<n;i++)
        {
            int ind = secret.find(guess[i]);
            if(ind !=-1 && guess[i]!=-1)
            {
                countc++;
                secret[ind]=-1;
            }
        }
         ans=to_string(countb)+"A"+to_string(countc)+"B";
        return ans;

    }
};