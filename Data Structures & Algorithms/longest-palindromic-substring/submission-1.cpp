class Solution {
public:
    string longestPalindrome(string s) {
        int resLen = 0, resID = 0;

        for(int i = 0; i < s.size(); i++){
            /// odd length
            int l = i, r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(resLen < (r - l + 1)){
                    resLen = r - l + 1;
                    resID = l;
                }
                l--; r++;
            }

            ///even length
            l = i, r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(resLen < (r - l + 1)){
                    resLen = r - l + 1;
                    resID = l;
                }
                l--; r++;
            }
        }
        return s.substr(resID, resLen);
    }
};
