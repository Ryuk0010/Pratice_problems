class Solution {
public:
    bool isNumber(string s) {
        bool digit=false,dot=false,seene=false;
        int count=0;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(isdigit(ch)==true)digit=true;
             else if(ch=='+' || ch=='-'){
                if(count==2)return false;
                if(i>0 && (s[i-1]!='e' && s[i-1]!='E'))return false;
                if(i==s.size()-1)return false;
                count++;
                
            }
            else if(ch=='.'){
                if(dot || seene)return false;
                
                if(i==s.size()-1 && digit==false)return false;
                dot=true;
            }
            else if(ch=='e'|| ch=='E'){
                if(seene)return false;
                if(digit==false || i==s.size()-1)return false;
                seene=true;
            }else{
                return false;
            }
        }
        return true;
    }
};