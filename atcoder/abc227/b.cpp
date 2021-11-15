#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  set<int> st;
  for (int a = 1; a <= 1000; a++) {
    for (int b = 1; b <= 1000; b++) {
      st.insert(4 * a * b + 3 * a + 3 * b);
    }
  }
  int cnt = 0;
  for (int i = 0, s; i < n; i++) {
    cin >> s;
    if (!st.count(s)) cnt++;
  }
  cout << cnt << '\n';
}