#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll ask(ll x, ll y) {
  cout << "? " << x << y << endl;
  ll res = 0;
  cin >> res;
  return res;
}

void answer(vector<ll>& a) {
  cout << "! ";
  for (auto& x : a) cout << x << " ";
  cout << endl;
}

void solve() {
  ll n;
  cin >> n;
}

int main() {
  ll T;
  cin >> T;
  unordered_map<int, int> mp;
  mp.insert({1,2});
  mp.insert({2,3});
  mp.begin()++;
  while (T--) {
    solve();
  }
}
