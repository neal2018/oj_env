#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  string s;
  cin >> n >> s;
  auto a = s.find("ABC");
  if (a == string::npos) {
    cout << "-1\n";
  } else {
    cout << (a) + 1 << "\n";
  }
}
