//
// Created by pinkod on 9/10/25.
//
#include <stdio.h>


static long long max(long long i, long long i1);


int main() {
    long long N, M;
    if(scanf("%lld %lld", &N, &M) != 2) {
        return 0;
    }

    const long long max_edges = N * (N - 1) / 2;
    if (M > max_edges) {
        printf("-1");
        return 0;
    }

    const long long d_min = max(1LL, N - M);

    long long x = 1;
    while (x * (x - 1) / 2 < M) {
        x++;
    }
    const long long d_max = N - x + 1;

    printf("%llu %llu", d_min, d_max);


    return 0;
}




static long long max(const long long i, const long long i1) {
    return i > i1 ? i : i1;
}