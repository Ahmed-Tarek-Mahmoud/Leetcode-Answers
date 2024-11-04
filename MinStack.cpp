/**
 * Name: Ahmed Tarek
 * Date: 4 Nov 2024
 * Problem Link: https://leetcode.com/problems/min-stack/
 */
#include <bits/stdc++.h>
#include <vector>
class MinStack {
public:
        // why to use arrays or vectors?
        // to direct access in O(1)
        vector<int> st; // represent my stack
        vector<int> mn; // store minimum positions
        
    MinStack() {
        
    }
    
    void push(int val) {
        if(mn.empty() || st[mn.back()] >= val) // if minimums are empty or the value smaller than current 
                                               //minimum then push the current index in minimums which is
                                               // current stack size
            mn.push_back(st.size());
        st.push_back(val);
    }
    
    void pop() {
        if(st.back() == st[mn.back()]) // if top element is the current minimum then pop the index
            mn.pop_back();
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return st[mn.back()];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */