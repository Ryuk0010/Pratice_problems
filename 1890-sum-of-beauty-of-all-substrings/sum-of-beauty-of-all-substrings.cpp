class Solution
{
public:
    int beautySum(string s)
    {
        int n = s.length();
        int total = 0;


        for (int i = 0; i < n; i++)
        {
            vector<int> v(26, 0);
            for (int j = i; j < n; j++)
            {
                v[s[j] - 'a']++;
                int maxfreq =0, minfreq = INT_MAX;
                for (int f : v)
                {
                    if (f> 0)
                    {
                        maxfreq = max(maxfreq, f);
                        minfreq = min(minfreq, f);
                    }
                }
                total +=( maxfreq - minfreq);
            }
        }
        return total;
    }
};