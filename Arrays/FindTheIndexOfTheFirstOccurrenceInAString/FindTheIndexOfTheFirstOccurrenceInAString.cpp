#include <bits/stdc++.h>
using namespace std;

// 28. Find the Index of the First Occurrence in a String

// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, 
// or -1 if needle is not part of haystack.

// Example 1:
// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0

// Example 2:
// Input: haystack = "leetcode", needle = "leeto"
// Output: -1

class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[0]) {
                int index = i, count = 0;
                for (int j = 0; j < needle.size() && index < haystack.size(); j++, index++) {
                    if (haystack[index] == needle[j]) {
                        count++;
                        if (count == needle.size()) return i;
                    } else {
                        break;
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;

    // Test cases
    string haystack = "hello";
    string needle = "ll";
    cout << "Index: " << solution.strStr(haystack, needle) << endl; // Output: 2

    haystack = "aaaaa";
    needle = "bba";
    cout << "Index: " << solution.strStr(haystack, needle) << endl; // Output: -1

    haystack = "hello";
    needle = "";
    cout << "Index: " << solution.strStr(haystack, needle) << endl; // Output: 0

    haystack = "";
    needle = "a";
    cout << "Index: " << solution.strStr(haystack, needle) << endl; // Output: -1

    return 0;
}