#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n;
  string s;
  cin >> n >> s;
  string t(s.rbegin(), s.rend());
  vector<vector<vector<int>>> diff(26);
  {
    vector<int> freq(26);
    for (int i = 0; i < n; i++) {
      diff[s[i] - 'a'].push_back(freq);
      freq[s[i] - 'a']++;
    }
  }
  ll res = 0;
  {
    vector<int> freq(26);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 26; j++) {
        if (t[i] - 'a' != j) {
          res += max(0, diff[t[i] - 'a'][freq[t[i] - 'a']][j] - freq[j]);
        }
      }
      freq[t[i] - 'a']++;
    }
  }
  cout << res << "\n";
}
