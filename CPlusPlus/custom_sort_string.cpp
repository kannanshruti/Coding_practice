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
    vector<int>order(26,100);
    for(int i = 0; i<S.size(); i++) {
        order[S[i] - 'a'] = i;
    }

    char c;
    for (int i = 0; i < T.length(); i++) {
        for (int j = 0; j < T.length() - 1; j++) {
            if (order[T[j]-'a'] > order[T[j+1]-'a']) {
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
