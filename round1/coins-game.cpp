#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n, k, c; cin >> n >> k >> c;

    int moves = -1;
    for(int i = n; i > 0; i--) {
      int sz = k / i;
      int obt = i * sz + min(k - i * sz, (n - i) * (sz - 1));
      if(obt >= c) { moves = c + (n - i); break; }
    }
    cout << "Case #" << tc << ": " << moves << endl;
  }
  return 0;
}
