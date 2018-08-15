// https://leetcode.com/problems/custom-sort-string/description/
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string customSortString(string S, string T);
};

string Solution::customSortString(string S, string T) {
    /*
    Sorts string T based on the order in S
    @param "S": String based on which sorting is to be performed
                Cannot have repetitive characters
           "T": String which is to be sorted
    @return "T": Sorted string

    */
    vector<int>order(26,100);
    for(int i = 0; i<S.size(); i++) {
        order[S[i] - 'a'] = i; // Finding the characters and their order in S
    }

    char c;
    for (int i = 0; i < T.length(); i++) {
        for (int j = 0; j < T.length() - 1; j++) {
            if (order[T[j]-'a'] > order[T[j+1]-'a']) { // Checking if order is to be changed
                c = T[j];
                T[j] = T[j+1];
                T[j+1] = c;                    
            }
        }
    }
    return T;
}

int main() {
    Solution sol1;
    string a = "cba";
    string b = "abcd";
    string result = sol1.customSortString(a, b);
    cout << result << "\n";
    return 0;
}
