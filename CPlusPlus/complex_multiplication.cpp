// https://leetcode.com/problems/complex-number-multiplication/description/

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;


struct c_num {
    string input;
    string output;
    int real;
    int imag;
};


class Solution {
public:
    string complexNumberMultiply(string a, string b);
    void splitComplex(c_num &n);
};


string Solution::complexNumberMultiply(string a, string b) {
	/**
    Performs complex number multiplication

    @param "a"   : First input, a+bi
           "b"   : Second input, a+bi
    @return "res.output": String, complex number multiplication result
    */
    c_num n1, n2, res;
    n1.input = a;
    n2.input = b;
    
    splitComplex(n1);
    splitComplex(n2);
    
    res.real = n1.real * n2.real - n1.imag * n2.imag; 
    res.imag = n1.real * n2.imag + n1.imag * n2.real;
    
    res.output = to_string(res.real) + "+" + to_string(res.imag) + "i";
    return res.output;
}

void Solution::splitComplex(c_num &n) {
	/**
    Splits a string of format 'a+bi' to integers a and b

    @param "n" : Struct which stores the integer real and imaginary parts
    @return None: The integers are stored in the struct input
    */
    string tmp;
    vector<string> tokens;
    stringstream ss(n.input);
    
    for(tmp; getline(ss, tmp, '+'); tokens.push_back(tmp)) {}  
    n.real = stoi(tokens[0]);
    n.imag = stoi(tokens[1].substr(0,tokens[1].length()-1));
}

int main() {
    Solution sol1;
    string input1, input2, result;

	input1 = "1+1i";
	input2 = "1+1i";
    result = sol1.complexNumberMultiply(input1, input2);
    cout << result << "\n";

    input1 = "1+-1i";
    input2 = "1+-1i";
    result = sol1.complexNumberMultiply(input1, input2);
    cout << result << "\n";

    return 0;
}