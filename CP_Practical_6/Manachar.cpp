#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Compute the longest palindromic substring using Manacher's algorithm.
// This returns the palindrome itself.
string manacherLongestPalindrome(const string &s) {
    int n = s.size();
    if (n == 0) return "";

    // d1[i] stores the radius of the longest odd-length palindrome centered at i.
    vector<int> d1(n);
    int l = 0, r = -1;
    for (int i = 0; i < n; ++i) {
        int k = 1;
        if (i <= r) {
            // Use the mirror of i around the current palindrome [l, r].
            k = min(d1[l + r - i], r - i + 1);
        }
        // Expand the odd-length palindrome centered at i.
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k;
        k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }

    // d2[i] stores the radius of the longest even-length palindrome centered
    // between i-1 and i.
    vector<int> d2(n);
    l = 0; r = -1;
    for (int i = 0; i < n; ++i) {
        int k = 0;
        if (i <= r) {
            k = min(d2[l + r - i + 1], r - i + 1);
        }
        // Expand the even-length palindrome centered between i-1 and i.
        while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k;
        if (i + k - 1 > r) {
            l = i - k;
            r = i + k - 1;
        }
    }

    int bestLen = 0;
    int bestL = 0;
    for (int i = 0; i < n; ++i) {
        int len1 = 2 * d1[i] - 1;
        if (len1 > bestLen) {
            bestLen = len1;
            bestL = i - d1[i] + 1;
        }

        int len2 = 2 * d2[i];
        if (len2 > bestLen) {
            bestLen = len2;
            bestL = i - d2[i];
        }
    }

    return s.substr(bestL, bestLen);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Read a single line of input from the user.
    string s;
    if (!getline(cin, s) || s.empty()) {
        return 0;
    }

    string longest = manacherLongestPalindrome(s);
    cout << "Longest Palindrome: " << longest << "\n"
         << "Length: " << longest.size();
    return 0;
}
