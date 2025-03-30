class Solution {
public:
    int minimumRefill(vector<int>& plants, int ca, int cb) {
        int len = plants.size();
        int times = 0;

        int al = 0;
        int bob = len -1;

        int oca = ca;
        int ocb = cb;

        while( al <= bob){
            if(al == bob){
                if( ca < plants[al] && cb < plants[al]){
                    times++;
                }
                break;
            }

            if(plants[al] <= ca){
                ca = ca - plants[al];
                al++;    
            }
            else{
                times++;
                ca = oca;
                ca = ca - plants[al];
                al++;
            }

            if(plants[bob] <= cb){
                cb = cb - plants[bob];
                bob--;  
            }
            else{
                times++;
                cb = ocb;
                cb = cb - plants[bob];
                bob--;
            }
        }

        return times;        
    }
};