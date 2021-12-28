#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  auto f = [&]() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& x : p) cin >> x;
    string s;
    cin >> s;
    vector<int> one, zero;
    for (int i = 0; i < n; i++) ((s[i] == '1') ? one : zero).push_back(i);
    sort(one.begin(), one.end(), [&](int a, int b) { return p[a] < p[b]; });
    sort(zero.begin(), zero.end(), [&](int a, int b) { return p[a] < p[b]; });
    zero.insert(zero.end(), one.begin(), one.end());
    vector<int> res(n);
    for (int i = 0; i < n; i++) res[zero[i]] = i + 1;
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  };
  while (T--) f();
}