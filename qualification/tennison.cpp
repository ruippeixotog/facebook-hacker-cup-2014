#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

#define MAXK 100

using namespace std;

double pres[MAXK + 1][MAXK + 1];
double psun[MAXK + 1][MAXK + 1];

inline double wif(double p, double vthen, double velse) {
  return p * vthen + (1.0 - p) * velse;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int k; double ps, pr, pi, pu, pw, pd, pl;
    cin >> k >> ps >> pr >> pi >> pu >> pw >> pd >> pl;

    memset(pres, 0, sizeof(pres));
    memset(psun, 0, sizeof(psun));
    pres[0][0] = 1.0;
    psun[0][0] = pi;

    for(int i = 0; i < k; i++) {
      for(int j = 0; j < k; j++) {
        if(!pres[i][j]) continue;

        double wpsun = psun[i][j] / pres[i][j];

        double pwin = pres[i][j] * wif(wpsun, ps, pr);
        if(pwin) {
          psun[i + 1][j] += pwin * wif(pw, min(1.0, wpsun + pu), wpsun);
          pres[i + 1][j] += pwin;
        }

        double plose = pres[i][j] * (1.0 - wif(wpsun, ps, pr));
        if(plose) {
          psun[i][j + 1] += plose * wif(pl, max(0.0, wpsun - pd), wpsun);
          pres[i][j + 1] += plose;
        }
      }
    }
    double total = 0.0;
    for(int i = 0; i < k; i++) total += pres[k][i];
    printf("Case #%d: %.6f\n", tc, total);
  }
  return 0;
}
