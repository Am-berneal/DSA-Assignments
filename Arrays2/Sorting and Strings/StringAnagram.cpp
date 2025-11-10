// FILE NAME: StringAnagram.cpp

#include <iostream>
#include <vector>
using namespace std;

bool areAnagrams(string s1, string s2) {
    if (s1.length() != s2.length())
        return false;

    vector<int> freq(26, 0);

    for (char c : s1) freq[c - 'a']++;
    for (char c : s2) freq[c - 'a']--;

    for (int x : freq)
        if (x != 0) return false;

    return true;
}

int main() {
    string s1 = "listen", s2 = "silent";
    cout << (areAnagrams(s1, s2) ? "Anagram" : "Not Anagram");
}
