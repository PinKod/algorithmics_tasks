//
// Created by pinkod on 9/10/25.
//
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#define POW_10_TO_6 1000000
#define MOD 1000000007ULL

static unsigned int scan_len();




int main() {
    const unsigned int pass_len = scan_len();
    if(pass_len == 0) return 1;

    unsigned long long v = 10;
    unsigned long long g = 20;
    unsigned long long b = 1;
    unsigned long long s = 0;
    for (unsigned int i = 2; i <= pass_len; i++) {
        const unsigned long long v_new = (10 * (g + b + s)) % MOD;
        const unsigned long long g_new = (20 * v) % MOD;
        const unsigned long long b_new = v;
        const unsigned long long s_new = (2 * g) % MOD;
        v = v_new;
        g = g_new;
        b = b_new;
        s = s_new;
    }
    const unsigned long long result = (v + g + b + s) % MOD;
    printf("%llu\n", result);

    fflush(stdout);
    return 0;
}




static unsigned int scan_len() {
    unsigned int pass_len = 0;
    const int scan_res = scanf("%u", &pass_len);
    if(scan_res != 1 || pass_len < 6 || pass_len > POW_10_TO_6) {
        return 0;
    }
    return pass_len;
}
