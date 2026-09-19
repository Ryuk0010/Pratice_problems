int spf[1000001];
int N=1000000;
void createspf()
{
    for(int i=1;i<=N;++i)
    {
        spf[i]=i;
    }
    for(int i=2;i*i<=N;++i)
    {
        if(spf[i]==i)
        {
            for(int j=i*i;j<=N;j+=i)
            {
                if(spf[j]==j)
                {
                    spf[j]=i;
                }
            }
        
        }
    }
}

class Solution {
public:
    int smallestValue(int n) {
        createspf();
        while(spf[n]!=n)
        {
            int sum=0;
            int x=n;
            while(x!=1)
            {
                sum+=spf[x];
                //cout<<x<<" "<<spf[x]<<endl;
                x/=spf[x];
            }
            if(sum==n)
            {
                return n;
            }
            n=sum;
        }

        return n;

    }
};