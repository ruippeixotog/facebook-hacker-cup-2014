#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

#define INF 0x3f3f3f3f

using namespace std;

int solve(int n, int k, int c) {
  if(c <= 0) return 0;
  // cerr << "solve(" << n << "," << k << "," << c << ")" << endl;

  int z = INF;
  for(int i = min(n, k); i > 0 && z > n - i; i--) {
    int obt = k / i * i;
    z = min(z, solve(n, k - obt, c - obt) + (n - i));
  }
  return z;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n, k, c; cin >> n >> k >> c;
    cout << "Case #" << tc << ": " << c + solve(n, k, c) << endl;
  }
  return 0;
}
