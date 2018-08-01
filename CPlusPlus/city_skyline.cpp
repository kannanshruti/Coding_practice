// https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/

// #include "city_skyline.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int> >& grid);
    vector<int> skyline_top(vector<vector<int> >& grid, int grid_size);
    vector<int> skyline_left(vector<vector<int> >& grid, int grid_size);
};

int Solution::maxIncreaseKeepingSkyline(vector<vector<int> >& grid) {
    int count = 0;
    int grid_size = grid[0].size();
        
    vector <int> skyline_tb = skyline_top(grid, grid_size);
    vector <int> skyline_lr = skyline_left(grid, grid_size);

    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            while (grid[i][j] < skyline_tb[j] && grid[i][j] < skyline_lr[i]) {
                grid[i][j]++;
                count++;
            }
        }
    }    
    return count;
}

vector<int> Solution::skyline_top(vector<vector<int> >& grid, int grid_size) {
    vector<int> skyline_tb;
    vector<int> tmp;
    int max;
    for (int i = 0; i < grid_size; i++) {
        max = 0;
        for (int j = 0; j < grid_size; j++) {
            tmp.push_back(grid[j][i]);
        }
        max = *max_element(tmp.begin(), tmp.end());
        tmp.clear();
        skyline_tb.push_back(max);
    }
    return skyline_tb;
}

vector<int> Solution::skyline_left(vector<vector<int> >& grid, int grid_size) {
    vector<int> skyline_lr;
    vector<int> tmp;
    int max;
    for (int i = 0; i < grid_size; i++) {
        max = 0;
        max = *max_element(grid[i].begin(), grid[i].end());
        skyline_lr.push_back(max);
    }
    return skyline_lr;
}

int main() {
    Solution sol1;
    vector< vector<int> > input = {{3,0,8,4}, {2,4,5,7}, {9,2,6,3}, {0,3,1,0}};
    int count = sol1.maxIncreaseKeepingSkyline(input);
    cout << count << "\n";
    return 0;
}