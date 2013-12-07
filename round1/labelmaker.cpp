#include <algorithm>
#include <iostream>
#include <string>

#define ll long long

using namespace std;

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    string letters; ll n;
    cin >> letters >> n; --n;

    string label;
    while(n >= 0) {
      label += letters[n % letters.size()];
      n = n / letters.size() - 1;
    }
    reverse(label.begin(), label.end());

    cout << "Case #" << tc << ": " << label << endl;
  }
  return 0;
}
