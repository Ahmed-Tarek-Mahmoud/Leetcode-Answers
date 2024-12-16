/**
 * Name: Ahmed Tarek
 * Date: 12 Dec 2024
 * Problem Link: https://leetcode.com/problems/keys-and-rooms/
 */
#include <bits/stdc++.h>
#include <vector>
#include <queue>

class Solution {
public:
    bool vis[1001];
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // perform a simple bfs and mark the visited rooms
        int n = rooms.size();
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            vis[cur] = true;
            for(auto ch : rooms[cur]){
                if(!vis[ch]) q.push(ch);
            }
        }
        // then see if you can visit all the rooms
        bool ans = true;
        for(int i = 0 ; i < n ; i++) ans&=vis[i];
        return ans;
    }
};