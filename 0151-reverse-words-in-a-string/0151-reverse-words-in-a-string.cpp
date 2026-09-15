#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "";
        string ans = "";

        while (ss >> token) {
            ans = token + " " + ans;
        }

       
        if (!ans.empty()) {
            ans.pop_back();
        }

        return ans;
    }
};