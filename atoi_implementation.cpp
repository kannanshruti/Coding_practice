#include <sstream>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str);
};

int Solution::myAtoi(string str) {
    /*
    Returns the integer conversion of the input string.
    Ignores spaces in the beginning. Acceptable characters
    after the initial spaces are digits or + or -.
    @param "str": Input string
    @return "result": Output integer
    */
    string num = "";
    string sign;
    int length_s = str.length();
    int i = 0, flag = 0;

    while(i != length_s) {
        if (str[i] == ' ' && flag == 0) {
            i++;
        }
        else if (str[i] == '+' or str[i] == '-') {
            flag = 1;
            num += str[i];
            i++;
        }
        else if (str[i]-'0' <= 9) {
            num += str[i];
            flag = 1;
            i++;
        }
        else break;
    }
    if (num == "")
        return 0;
    else {
        stringstream s(num);
        int result = 0;
        s >> result;   
        return result;
    }
}

int main() {
    Solution sol1;
    string input = "    -9123 dnwekn knfwke";
    int result = sol1.myAtoi(input);
    cout << result << "\n";
    return 0;
}
