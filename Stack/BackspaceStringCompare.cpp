/**
 * Name: Ahmed Tarek
 * Date: 4 Nov 2024
 * Problem Link: https://leetcode.com/problems/backspace-string-compare/
 */


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ss = "";
        string tt = "";
        // we can use strings as a stack of characters
        // push the character and when stepping onto a #
        // pop the last character then do one comparison at the end
        for(auto c:s){
            if(c == '#'){
                if(ss.size()) ss.pop_back();
            }else{
                ss += c;
            }
        } 

        for(auto c:t){
            if(c == '#'){
                if(tt.size()) tt.pop_back();
            }else{
                tt += c;
            }
        } 
        int n = ss.length() , m = tt.length();
        if(n != m) return false;
        for(int i = 0; i < n;i++){
            if(ss[i] != tt[i]) return false;
        }
        return true;
    }
};