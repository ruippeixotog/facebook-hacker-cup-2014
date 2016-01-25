#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define ll long long

#define MAXN 100

using namespace std;

int n;

bool wins(int a1, int a2, int b1, int b2) {
  if(a1 + a2 != b1 + b2) return a1 + a2 > b1 + b2;
  return max(a1, a2) > max(b1, b2);
}

bool shouldBet(ll targetCases, int c1, int c2) {
  int worseHands = 0;

  int hands[MAXN + 1];
  memset(hands, 0, sizeof(hands));

  for(int i = 1; i <= n; i++) {
    if(i == c1 || i == c2) continue;
    for(int j = i + 1; j <= n; j++) {
      if(j == c1 || j == c2) continue;

      if(wins(c1, c2, i, j)) {
        worseHands++; hands[i]++; hands[j]++;
      }
    }
  }

  ll winCases = 0;
  for(int c3 = 1; c3 <= n; c3++) {
    if(c3 == c1 || c3 == c2) continue;
    for(int c4 = c3 + 1; c4 <= n; c4++) {
      if(c4 == c1 || c4 == c2) continue;
      if(wins(c3, c4, c1, c2)) continue;
      for(int c5 = 1; c5 <= n; c5++) {
        if(c5 == c1 || c5 == c2 || c5 == c3 || c5 == c4) continue;
        for(int c6 = c5 + 1; c6 <= n; c6++) {
          if(c6 == c1 || c6 == c2 || c6 == c3 || c6 == c4) continue;
          if(wins(c5, c6, c1, c2)) continue;

          winCases += worseHands
            - hands[c3] - hands[c4] - hands[c5] - hands[c6]
            + wins(c1, c2, c3, c5) + wins(c1, c2, c3, c6)
            + wins(c1, c2, c4, c5) + wins(c1, c2, c4, c6) + 2;
        }
      }
    }
  }
  return winCases > targetCases;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int h; cin >> n >> h;

    ll allCases = 1;
    for(int i = n - 2; i > n - 8; i--)
      allCases *= i;

    allCases /= 8;
    ll targetCases = allCases / 4;

    vector<int> all1, all2;
    for(int sum = 2 * n - 1; sum >= 3; sum--) {
      for(int i = n; i > sum / 2; i--) {
        int j = sum - i;
        if(j > 0 && j <= n) {
          all1.push_back(i); all2.push_back(j);
        }
      }
    }

    int st = 0, end = all1.size();
    while(st < end - 1) {
      int mid = (end + st) / 2;
      if(shouldBet(targetCases, all1[mid], all2[mid])) st = mid;
      else end = mid;
    }
    int t1 = all1[st], t2 = all2[st];

    string res;
    for(int k = 0; k < h; k++) {
      int c1, c2; cin >> c1 >> c2;
      res.push_back(wins(t1, t2, c1, c2) ? 'F' : 'B'); 
    }

    cout << "Case #" << tc << ": " << res << endl;
  }
  return 0;
}
