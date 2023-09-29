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
    if (s[0] == 'B' || s.back() == 'B' || s.find("BB") != string::npos) {
      cout << count(s.begin(), s.end(), 'A') << "\n";
      continue;
    }
    int mini = int(s.size());
    for (int i = 0, j = 0; i < s.size(); i = j) {
      for (j = i; j < s.size() && s[i] == s[j];) j++;
      if (s[i] == 'A') mini = min(mini, j - i);
    }
    cout << count(s.begin(), s.end(), 'A') - mini << "\n";
  }
}
