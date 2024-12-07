/**
 * Name: Ahmed Tarek
 * Date: 4 Nov 2024
 * Problem Link: https://leetcode.com/problems/crawler-log-folder/description/
 */

class Solution {
public:
    int minOperations(vector<string>& logs) {
        // smart solution without stack
        int ans = 0;
        for(auto s:logs){
            if(ans && s == "../") ans--;
            else if(s != "./" && s!= "../") ans++;
        }
        return ans;
        //////////////////////////////////////
        // stack soution
        stack<string> st;
        for(auto s:logs){
            if(s == "../") {
                if(st.size()) st.pop();
            }
                
            else if(s != "./") st.push(s);
        }
        return st.size();
    }
};