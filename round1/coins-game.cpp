#include <iostream>

using namespace std;

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n, k, c; cin >> n >> k >> c;

    int b = n;
    while(c > k / b * b) b--;

    cout << "Case #" << tc << ": " << (c + n - b) << endl;
  }
  return 0;
}
