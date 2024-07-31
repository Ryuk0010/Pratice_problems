class Solution {
public: 
    int Mod=1e9+7;
    int solve(int i, int j, vector<vector<int>>& phone, int curr_jumps, int jumps,vector<vector<int>>& dp){

        if(curr_jumps==jumps)return 1;
        if(dp[phone[i][j]][curr_jumps]!=-1)return dp[phone[i][j]][curr_jumps];
        
        int Drow[8]={1,1,-1,-1,2,2,-2,-2};
        int Dcol[8]={2,-2,2,-2,-1,1,-1,1};
        int sum=0;
        for(int k=0; k<8; k++){
            int nRow=i+Drow[k];
            int nCol=j+Dcol[k];
            if(nRow>=0 && nRow<4 && nCol>=0 && nCol<3 && phone[nRow][nCol]!=INT_MAX){
                int temp=solve(nRow,nCol,phone,curr_jumps+1,jumps,dp);
                sum= (sum+temp)%Mod;
            }
        }
        return dp[phone[i][j]][curr_jumps]=sum%Mod;
        
    }
    int knightDialer(int n) {
        if(n==1)return 10;
        vector<vector<int>> phone(4,vector<int>(3,0));
        phone[0][0]=1;
        phone[0][1]=2;
        phone[0][2]=3;
        phone[1][0]=4;
        phone[1][1]=5;
        phone[1][2]=6;
        phone[2][0]=7;
        phone[2][1]=8;
        phone[2][2]=9;
        phone[3][0]=INT_MAX;
        phone[3][1]=0;
        phone[3][2]=INT_MAX;
        int ans=0;
        vector<vector<int>> dp(10,vector<int>(n,-1));
        

        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                if(phone[i][j]==INT_MAX)continue;
                else {
                    ans+= solve(i,j,phone,1,n,dp);
                    ans=ans%Mod;
                }
            }
        }
        return ans;
    }
};