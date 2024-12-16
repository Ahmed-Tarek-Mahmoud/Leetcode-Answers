/**
 * Name: Ahmed Tarek
 * Date: 12 Dec 2024
 * Problem Link: https://leetcode.com/problems/word-search/description/
 */
#include <bits/stdc++.h>
#include <vector>
#include <string>

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size() , m = board[0].size();
        // Try to start from each cell
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(go(i , j , 0 , n , m ,board , word)) return true;
            }
        }
        return false;
    }
    bool go(int i, int j , int k , int n , int  m, vector<vector<char>>& board, string &word){
        if (k == word.length()) { // matched the whole word
                return true;
            }
            // current character doesn't match or out of the board 
            if (i < 0 || i >= n || j < 0 || j >= m) {
                return false;
            }
            if(board[i][j] != word[k]) return false;
            
            char temp = board[i][j];
            // Mark it as taken (do)
            board[i][j] = '\0';
            // try the adjacent cells (recurse)
            if (go(i + 1, j, k + 1,n,m,board,word) 
            || go(i - 1, j, k + 1,n,m,board,word) 
            || go(i, j + 1, k + 1,n,m,board,word) 
            || go(i, j - 1, k + 1,n,m,board,word)) {
                return true;
            }
            // not taken any more (undo)
            board[i][j] = temp; 
            return false;
    }
};