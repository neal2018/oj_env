#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string f1(const string& s) {
  int n = int(s.size());
  array<int, 26> freq{};
  for (auto& c : s) freq[c - 'a']++;
  string res(n, '?');
  int i = 0, j = n - 1;
  int addon = 0;
  for (int c = 0; c < 26; c++) {
    if (freq[c] == 0) continue;
    while (freq[c] >= 2) {
      res[i++] = char(c + 'a');
      res[j--] = char(c + 'a');
      freq[c] -= 2;
    }
    if (freq[c] == 1) {
      addon++;
    }
    if (addon == 2) break;
  }
  if (addon > 0) {
    int pos = [&] {
      for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) return i;
      }
      return -1;
    }();
    if (addon == 1) {
      res[i] = char(pos + 'a');
    } else if (addon == 2) {
      freq[pos]--;
      int pos2 = [&] {
        for (int i = pos + 1; i < 26; i++) {
          if (freq[i] > 0) return i;
        }
        return -1;
      }();
      freq[pos2]--;
      res[i++] = char(pos + 'a');
      res[j--] = char(pos2 + 'a');
      for (int c = pos2; c < 26; c++) {
        while (freq[c] > 0) {
          res[j--] = char(c + 'a');
          freq[c]--;
        }
      }
    }
  }
  return res;
}

string f2(const string& s) {
  int n = int(s.size());
  array<int, 26> freq{};
  for (auto& c : s) freq[c - 'a']++;
  string res(n, '?');
  int i = 0, j = n - 1;
  int addon = 0;
  for (int c = 0; c < 26; c++) {
    if (freq[c] == 0) continue;
    while (freq[c] >= 2) {
      res[i++] = char(c + 'a');
      res[j--] = char(c + 'a');
      freq[c] -= 2;
    }
    if (freq[c] == 1) {
      addon++;
      break;
    }
    if (addon == 2) break;
  }
  if (addon == 1) {
    int pos = [&] {
      for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) return i;
      }
      return -1;
    }();
    res[j--] = char(pos + 'a');
    freq[pos]--;
    for (int c = pos; c < 26; c++) {
      while (freq[c] > 0) {
        res[i++] = char(c + 'a');
        freq[c]--;
      }
    }
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    auto t1 = f1(s);
    auto t2 = f2(s);
    auto tt1 = max(t1, string(t1.rbegin(), t1.rend()));
    auto tt2 = max(t2, string(t2.rbegin(), t2.rend()));
    // cout<<tt1<<"\n";
    // cout<<tt2<<"\n";
    // if (tt1 < tt2) {
    //   cout << t1 << "\n";
    // }else{
    //   cout << t2 << "\n";
    // }
    cout << min(tt1, tt2) << "\n";
  }
}
