#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
  double a,b,c,d;

double calc(double e) {
  double sone = (a+b+e)/2;
  double aone = abs(sone * (sone -a) * (sone-b) * (sone-e));
  aone = pow(aone, 0.5);
  double stwo = (c+d+e)/2;
  double atwo = abs(stwo * (stwo -c) * (stwo-d) * (stwo-e));
  atwo = pow(atwo, 0.5);

  return aone + atwo;
}


int main() {

  cin >> a >> b >> c >> d;
  cout << fixed << setprecision(10);

  double l = max(abs(a-b), abs(c-d));
  double r = min(a+b, c+d);
  double ans = 0;

  while(l + 1e-10 <r) {
    double mid1 = (l+l+r)/3;
    double mid2 = (l+r+r)/3;
    double one = calc(mid1);
    double two = calc(mid2);
    ans = one;

    if (one<two){
      l=mid1;
    }else{
      r=mid2;
    }
  }

  cout << ans << '\n';

}