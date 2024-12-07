/**
 * Name: Ahmed Tarek
 * Date: 4 Nov 2024
 * Problem Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
 */

class Solution {
public:
    int minAddToMakeValid(string s) {
        int maftoh = 0 , ans = 0;
        for( auto c:s){
            if(c == ')'){
                if(maftoh) maftoh--;
                else ans++;
            }
            else maftoh++;
        }
        return ans+maftoh;
    }
};