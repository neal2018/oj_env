#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
  string a, b, c;
  cin >> a >> b >> c;

  a = a+b+c;
  sort(a.begin(), a.end());

  int bestDay = 99;
  int bestMonth = 99;
  int bestYear = 9999;
  int ans = 0;

  while(true) {
    int day = 10*(a[0]-'0') + a[1]-'0';
    int month = 10*(a[2]-'0') + a[3]-'0';
    int year = 1000*(a[4]-'0') + 100*(a[5]-'0') + 10*(a[6]-'0') + a[7]-'0';
    bool good = true;
    if(year <= 1999) good = false;
    if(month == 0 || month > 12) good = false;
    if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) good = false;
    if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) good = false;
    bool leap = false;
    if(year % 400 == 0 || (year % 4 == 0 && year % 100)) leap = true;
    if(month== 2 && leap && day > 29) good = false;
    if(month == 2 && !leap && day > 28) good = false;
    if(day == 0) good = false;

    if(good) {
      int best = false;
      ans++;
      if(year < bestYear) best = true;
      if(year == bestYear && month < bestMonth) best = true;
      if(year == bestYear && month == bestMonth && day < bestDay) best = true;
      if(best) {
        bestDay = day;
        bestMonth = month;
        bestYear = year;
      }
    }

    if(!next_permutation(a.begin(), a.end())) break;
  }

  cout << ans << ' ';
  if(ans) {
    if(bestDay < 10) cout << 0;
    cout << bestDay << ' ';
    if(bestMonth < 10) cout << 0;
    cout << bestMonth << ' ' << bestYear << '\n';
  }
  else cout << '\n';
}

int main() {

  int t;
  cin >> t;
  while(t--) {
    solve();
  }

}