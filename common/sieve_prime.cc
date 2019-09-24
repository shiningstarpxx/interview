#include <stdio.h>
#include <time.h>

typedef long long LL;

int p[100010];
bool np[1000010];
int cntp;

void SievePrime(int n) {
  LL t;
  for (int i = 2; i <= n; ++i) {
    if (!np[i]) p[cntp++] = i;
    for (int j = 0; j < cntp && (t = 1ll * i * p[j]) <= n; ++j) {
      np[t] = true;
      // if (i % p[j] == 0) break;
    }
  }
}

void SievePrime2(int n) {
  for (int i = 2; i <= n; ++i) {
    for (int j = 2; j * i <= n; ++j) {
      np[i * j] = true;
    }
  }
}

int main() {
  {
    long begin_time = clock();
    SievePrime(100000);
    long end_time = clock();
    printf("%ld\n", end_time-begin_time);
  }
  {
    long begin_time = clock();
    SievePrime2(100000);
    long end_time = clock();
    printf("%ld\n", end_time-begin_time);
  }
  return 0;
}
