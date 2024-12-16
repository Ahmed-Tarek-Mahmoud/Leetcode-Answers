/**
 * Name: Ahmed Tarek
 * Date: 12 Dec 2024
 * Problem Link: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/
 */
#include <bits/stdc++.h>
#include <vector>
#include <string>

class Solution {
public:
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> in(n , 0);
        // if the in-degree of the node is zero then it is impossimble to visit it from any other 
        // node so we include it in our set
        for(auto &ed:edges){
            in[ed[1]]++;
        }
        for(int i = 0; i < n; i++){
            if(!in[i]) ans.push_back(i);
        }
        return ans;
    }
    
};