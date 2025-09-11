//
// Created by pinkod on 9/10/25.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUT_LEN_MAX 100

typedef enum {
    bd_time,
    xyz_time
} time_fmt_t;

static void print_bd_time(char* input);
static void print_xyz_time(const char* input);




int main() {
    char input[INPUT_LEN_MAX] = {0};
    const int scan_res = scanf("%99s", input);
    if (scan_res != 1) {
        return 1;
    }

    const size_t time_len = strlen(input);
    time_fmt_t time_fmt = bd_time;
    for(size_t i = 0; i < time_len; ++i) {
        if(input[i] == ':') {
            time_fmt = xyz_time;
            break;
        }
    }

    switch (time_fmt) {
        case bd_time:
            print_xyz_time(input);
            break;
        case xyz_time:
            print_bd_time(input);
            break;
    }

    fflush(stdout);
    return 0;
}




static void print_bd_time(char* input) {
    unsigned int hh = 0;
    unsigned int mm = 0;
    unsigned int ss = 0;

    const int scan_res = sscanf(input, "%u:%u:%u", &hh, &mm, &ss);
    if (scan_res != 3) {
        return;
    }

    const unsigned int total_ss = hh * 3600 + mm * 60 + ss;
    printf("%u\n", total_ss);
}

static void print_xyz_time(const char* input) {
    unsigned int total_ss = 0;
    const int scan_res = sscanf(input, "%u", &total_ss);
    if (scan_res != 1) {
        return;
    }

    if (total_ss > 86399) {
        total_ss = 86399;
    }

    const unsigned int hh = total_ss / 3600;
    const unsigned int remaining_after_hours = total_ss % 3600;
    const unsigned int mm = remaining_after_hours / 60;
    const unsigned int ss = remaining_after_hours % 60;

    printf("%02u:%02u:%02u\n", hh, mm, ss);
}