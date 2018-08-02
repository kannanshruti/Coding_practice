// https://leetcode.com/problems/battleships-in-a-board/description/
// Runs in 4 ms

#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
    vector<vector<int> > locations = {{0,1}, {1,0}};
public:
    int countBattleships(vector<vector<char> >& board);
    void check_neighbor(vector<vector<char> > &board, int i, int j);
};

int Solution::countBattleships(vector<vector<char>>& board) {
    /*
    Counts number of battleships on the board (Each must be separated by a row or column)

    @param: 'board': Inner vectors represent the rows of the board,
                     Outer vectors represent the columns of the board
    @return: 'count': Number fof battleships
    */
    int count = 0;
    int rows = board.size();
    int cols = board[0].size();
    
    for( int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 'X') {
                board[i][j] = 'o';
                check_neighbor(board, i, j);
                count++;
            }
        }
    }
    
    // Uncomment the following for display:
    // for( int i = 0; i < rows; i++) {
    //     for (int j = 0; j < cols; j++) {
    //         cout << board[i][j];
    //     }
    //     cout << "\n";
    // }

    return count;
}

void Solution::check_neighbor(vector<vector<char> > &board, int row, int col) {
    /*
    Checks whether the neighbors to the right or bottom have a portion of the ship
    Uses recursion to traverse the entire ship

    @param: 'board': Inner vectors represent the rows of the board,
                     Outer vectors represent the columns of the board
            'row'  : Current element row whose neighbors are to be checked
            'col'  : Current element column whose neighbors are to be checked
    @return: None. 'board' gets modified as and when the ship locations are found
    */

    for (int x = 0; x < locations.size(); x++) {
        int i = locations[x][0];
        int j = locations[x][1];
        if (row+i < 0 || row+i >= board.size() || col+j < 0 || col+j >= board[0].size()) continue;
        if (board[row+i][col+j] == 'X') {
            check_neighbor(board, row+i, col+j);
            board[row+i][col+j] = 'o';
        }
    }

    // Alternative solution
    // for (int i = 0; i <= 1; i++) {
    //     for (int j = 0; j <= 1; j++) {
    //         if (i == 0 && j == 0) continue; // Element which is being checked
    //         if (row+i != row && col+j != col) continue; // Diagonal elements need not be checked
    //         if (row+i < 0 || row+i >= board.size() || col+j < 0 || col+j >= board[0].size()) continue;
    //         if (board[row+i][col+j] == 'X') {
    //             check_neighbor(board, row+i, col+j);
    //             board[row+i][col+j] = 'o';
    //         }
    //     }
    // }
    return;
}

int main() {
    Solution sol1;
    vector< vector<char> > input = {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};
    int count = sol1.countBattleships(input);
    cout << count << "\n";
    return 0;
}