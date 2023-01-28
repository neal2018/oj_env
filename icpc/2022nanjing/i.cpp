#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    array<int, 26> freq = {};
    for (auto& c : s) {
      freq[c - 'a']++;
    }
    cout << s.size() - *max_element(freq.begin(), freq.end()) << "\n";
  }
}