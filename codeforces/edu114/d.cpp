#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll n, m, sum;
  cin >> n;
  vector<vector<int>> a(n);
  vector<int> c(n), poss(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    a[i] = vector<int>(c[i]);
    for (int j = 0; j < c[i]; j++) {
      cin >> a[i][j];
    }
    sum += a[i][c[i] - 1];
    poss[i] = c[i] - 1;
  }
  cin >> m;
  set<vector<int>> st, seen;
  for (int i = 0; i < m; i++) {
    vector<int> b(n);
    for (int j = 0; j < n; j++) {
      cin >> b[j];
      b[j]--;
    }
    st.insert(b);
  }
  set<pair<ll, vector<int>>> has;
  has.insert({-sum, poss});
  seen.insert(poss);
  int kk = st.size();
  while (st.count(has.begin()->second) > 0) {
    vector<int> t = move(has.begin()->second);
    // for (int i = 0; i < n; i++) {
    //   cout << t[i] + 1 << " ";
    // }
    // cout << '\n';
    ll ss = -(has.begin()->first);
    has.erase(has.begin());
    for (int i = 0; i < n; i++) {
      if (t[i] != 0) {
        vector<int> temp = t;
        temp[i]--;
        if (seen.count(temp) == 0) {
          seen.insert(temp);
          has.insert({-(ss - a[i][temp[i] + 1] + a[i][temp[i]]), move(temp)});
        }
      }
    }
  }
  vector<int> t = has.begin()->second;

  for (int i = 0; i < n; i++) {
    cout << t[i] + 1 << " ";
  }
  cout << '\n';
}