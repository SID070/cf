#include <bits/stdc++.h>
using namespace std;


int countDistinctPermutations(const string& s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    int fact = 1, denom = 1;
    for (int i = 1; i <= s.size(); ++i) fact *= i;  
    for (auto& pair : freq) {
        int f = pair.second;
        for (int i = 1; i <= f; ++i) denom *= i;  
    }
    return fact / denom;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        string bestResult = s;
        int minPermutations = countDistinctPermutations(s);

        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                string modified = s;
                modified[i] = s[j];  
                int currentPermutations = countDistinctPermutations(modified);
                if (currentPermutations < minPermutations) {
                    minPermutations = currentPermutations;
                    bestResult = modified;
                }
            }
        }

        cout << bestResult << endl;
    }
    return 0;
}
