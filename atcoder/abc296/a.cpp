#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  string s;
  cin >> n >> s;
  if (unique(s.begin(), s.end()) == s.end()) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
