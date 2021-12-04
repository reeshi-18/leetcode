class Solution {
public:
    int myAtoi(string s) {
        int i=0,r=0;
        bool isneg=false;
        while(isspace(s[i])){
            i++;
        };
        
        if(i==s.length()) return 0;
        
        if(s[i]=='-'||s[i]=='+'){
           isneg= (s[i++]=='-');
        }
        while(s[i]>='0' && s[i]<='9' && i<s.length()) {
            if (r>INT_MAX/10) return isneg?INT_MIN:INT_MAX;
            if(r==INT_MAX/10 && (s[i]-'0')>INT_MAX%10) return isneg?INT_MIN:INT_MAX;
            r=r*10+(s[i]-'0');
            i++;
        }
        return isneg?-r:r;
    }
};