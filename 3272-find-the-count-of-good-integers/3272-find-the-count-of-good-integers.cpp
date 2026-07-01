#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> st;
        int d = (n + 1) / 2;
        int start = pow(10, d - 1);
        int end = pow(10, d) - 1;

        for (int num = start; num <= end; num++) {
            string leftHalf = to_string(num);
            string full;

            if (n % 2 == 0) {
                string rightHalf = leftHalf;
                reverse(rightHalf.begin(), rightHalf.end());
                full = leftHalf + rightHalf;
            } else {
                string rightHalf = leftHalf.substr(0, d - 1);  // Fixed here
                reverse(rightHalf.begin(), rightHalf.end());
                full = leftHalf + rightHalf;
            }

            // Avoid converting to number directly (to prevent overflow)
            long long mod = 0;
            for (char ch : full) {
                mod = (mod * 10 + (ch - '0')) % k;
            }
            if (mod != 0) continue;

            // Store sorted digits to count unique digit sets
            string sortedFull = full;
            sort(sortedFull.begin(), sortedFull.end());
            st.insert(sortedFull);
        }

        // Precompute factorials up to 20
        vector<long long> factorial(21, 1);
        for (int i = 1; i <= 20; i++) {
            factorial[i] = factorial[i - 1] * i;
        }

        long long result = 0;

        for (const string& s : st) {
            vector<int> count(10, 0);
            for (char ch : s) {
                count[ch - '0']++;
            }

            int totalDigits = s.length();
            long long perm = 0;

            // Count permutations that don't start with zero
            for (int firstDigit = 1; firstDigit < 10; ++firstDigit) {
                if (count[firstDigit] == 0) continue;

                count[firstDigit]--;
                long long curr = factorial[totalDigits - 1];
                for (int i = 0; i < 10; ++i)
                    curr /= factorial[count[i]];
                perm += curr;
                count[firstDigit]++;
            }

            result += perm;
        }

        return result;
    }
};
