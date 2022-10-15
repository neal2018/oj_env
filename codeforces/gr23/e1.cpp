#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool ask(int l, int r, vector<int>& a) {
  cout << "? " << r - l << " ";
  for (int i = l; i < r; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  string s;
  cin >> s;
  return s == "YES";
}

bool answer(int x) {
  cout << "! " << x << endl;
  string s;
  cin >> s;
  if (s == ":)") exit(0);
  return s == ":)";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  iota(a.begin(), a.end(), 1);
  while (a.size() > 2) {
    int sz = int(a.size());
    int mid1 = sz / 3, mid2 = 2 * sz / 3;
    int not_l = 0, not_r = 0;
    if (ask(0, mid1, a) || ask(0, mid1, a)) {
      if (ask(mid1, mid2, a)) {
        not_l = mid2, not_r = sz;
      } else {
        not_l = mid1, not_r = mid2;
      }
    } else {
      not_l = 0, not_r = mid1;
    }
    vector<int> nex;
    for (int i = 0; i < sz; i++) {
      if (!(not_l <= i && i < not_r)) nex.push_back(a[i]);
    }
    swap(nex, a);
  }
  for (auto& i : a) {
    answer(i);
  }
}
