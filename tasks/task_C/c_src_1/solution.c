#include <limits.h>
#include <stdio.h>

#define MAX_N 10000
#define MAX_HEX_DIGITS (MAX_N * 2 + 1)

static unsigned int scan_reg_num();
static void num_detector_calc(unsigned int reg_num, int *hex_digits, unsigned int *length);
static void print_hex(const int *hex_digits, unsigned int length);




int main() {
    const unsigned int reg_num = scan_reg_num();
    if(reg_num == 0) return 1;

    int hex_digits[MAX_HEX_DIGITS] = {0};
    unsigned int length = 1;
    hex_digits[0] = 1;

    num_detector_calc(reg_num, hex_digits, &length);
    print_hex(hex_digits, length);
    printf("\n");

    fflush(stdout);
    return 0;
}

static unsigned int scan_reg_num() {
    unsigned int reg_num = 0;
    if(scanf("%u", &reg_num) != 1) {
        return 0;
    }
    return reg_num;
}

static void num_detector_calc(const unsigned int reg_num, int *hex_digits, unsigned int *length) {
    const unsigned int p = 8 * reg_num - 1;
    const unsigned int full_4bit_shifts = p / 4;
    const unsigned int rem_shift = p % 4;

    if(full_4bit_shifts > 0) {
        for(unsigned int i = *length - 1; i != UINT_MAX; --i)
            hex_digits[i + full_4bit_shifts] = hex_digits[i];
        for(unsigned int i = 0; i < full_4bit_shifts; ++i)
            hex_digits[i] = 0;
        *length += full_4bit_shifts;
    }

    if(rem_shift > 0) {
        int carry = 0;
        for(unsigned int i = 0; i < *length; ++i) {
            const unsigned int shifted = (hex_digits[i] << rem_shift) | carry;
            hex_digits[i] = shifted & 0xF;
            carry = shifted >> 4;
        }
        if(carry) {
            hex_digits[*length] = carry;
            (*length)++;
        }
    }
}

static void print_hex(const int *hex_digits, const unsigned int length) {
    int started = 0;
    for(unsigned int i = length-1; i != UINT_MAX; --i) {
        if(!started && hex_digits[i] == 0) continue;
        started = 1;
        printf("%X", hex_digits[i]);
    }
    if(!started) printf("0");
}
