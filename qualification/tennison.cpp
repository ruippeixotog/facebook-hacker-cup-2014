#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

#define MAXK 100
#define MAXP 1000

using namespace std;

double dp[MAXK + 1][MAXK + 1][MAXP + 1];

inline double wif(int psun, double vthen, double velse) {
  return (psun * vthen + (MAXP - psun) * velse) / MAXP;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int k; double ps, pr, pi, pu, pw, pd, pl;
    cin >> k >> ps >> pr >> pi >> pu >> pw >> pd >> pl;
    int ipu = pu * MAXP, ipd = pd * MAXP;

    memset(dp, 0, sizeof(dp));
    dp[0][0][int(pi * MAXP)] = 1.0;

    for(int i = 0; i < k; i++) {
      for(int j = 0; j < k; j++) {
        for(int psun = 0; psun <= MAXP; psun++) {
          if(!dp[i][j][psun]) continue;
          double pwin = dp[i][j][psun] * wif(psun, ps, pr);
          if(pwin) {
            dp[i + 1][j][min(MAXP, psun + ipu)] += pwin * pw;
            dp[i + 1][j][psun] += pwin * (1.0 - pw);
          }

          double plose = dp[i][j][psun] - pwin;
          if(plose) {
            dp[i][j + 1][max(0, psun - ipd)] += plose * pl;
            dp[i][j + 1][psun] += plose * (1.0 - pl);
          }
        }
      }
    }
    double total = 0.0;
    for(int i = 0; i < k; i++) {
      for(int psun = 0; psun <= MAXP; psun++) {
        total += dp[k][i][psun];
      }
    }
    printf("Case #%d: %.6f\n", tc, total);
  }
  return 0;
}
