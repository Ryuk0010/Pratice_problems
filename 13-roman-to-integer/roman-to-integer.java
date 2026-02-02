class Solution {
    public int getNum(char c) {
    if (c == 'I') return 1;
        else if (c == 'V') return 5;
        else if (c == 'X') return 10;
        else if (c == 'L') return 50;
        else if (c == 'C') return 100;
        else if (c == 'D') return 500;
        else if (c == 'M') return 1000;
        return 0;
    }

    int ans = 0;
    public int romanToInt(String s) {
        int prev = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            int num = getNum(s.charAt(i));
            if(num < prev) ans -= num;
            else ans += num;
            System.out.println(i +" the ans is "+ ans);
            prev = num;
        }
        return ans;
    }
}