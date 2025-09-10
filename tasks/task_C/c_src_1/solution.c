//
// Created by pinkod on 9/10/25.
//
#include <stdint.h>
#include <stdio.h>

static unsigned int scan_reg_num();
static uint64_t num_detector_calc(unsigned int reg_num);



int main() {
    const unsigned int reg_num = scan_reg_num();
    if(reg_num == 0) return 1;


    const uint64_t num_detector = num_detector_calc(reg_num);
    printf("%lx\n", num_detector);

    fflush(stdout);
    return 0;
}




static unsigned int scan_reg_num() {
    unsigned int reg_num = 0;
    const int scan_res = scanf("%u", &reg_num);
    if(scan_res != 1) {
        return 0;

    }
    return reg_num;
}

static uint64_t num_detector_calc(const unsigned int reg_num) {
    const unsigned int p = 8 * reg_num - 1;
    const uint64_t D = 1ULL << p;
    return D;
}