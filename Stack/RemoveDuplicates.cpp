/**
 * Name: Ahmed Tarek
 * Date: 4 Nov 2024
 * Problem Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
 */

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(auto c:s){
            if(st.size() && c == st.top()) st.pop();
            else st.push(c);
        }
        string ans;

        while(!st.empty()) ans+=st.top() , st.pop();
        // we need to reverse ans as the stack will be reversed (LIFO)
        reverse(ans.begin() , ans.end());
        return ans;
    }
};