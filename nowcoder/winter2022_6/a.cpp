#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

auto kmp(const vector<int>& txt, const vector<int>& pat) {
  int n = int(txt.size());
  int m = int(pat.size());
  vector<int> nex(m);  // nex[i]: LC prefix & suffix for pat[0..i]
  for (int i = 1, j = 0; i < m; i++) {
    while (j && pat[j] != pat[i]) j = nex[j - 1];
    if (pat[j] == pat[i]) j++;
    nex[i] = j;
  }
  vector<int> cnt(n + 1);
  for (int i = 0, j = 0; i < n; i++) {
    while (j && pat[j] != txt[i]) j = nex[j - 1];
    if (pat[j] == txt[i]) j++;
    cnt[j]++;
    if (j == m) {
      j = nex[j - 1];
    }
  }
  for (int i = n; i > 0; i--) {
    cnt[nex[i - 1]] += cnt[i];
  }
  return cnt;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  auto b = vector<int>(a.rbegin(), a.rend());
  auto t = kmp(b, a);
  for (int i = 0; i < n; i++) cout << t[i + 1] << " ";
  cout << "\n";
}
