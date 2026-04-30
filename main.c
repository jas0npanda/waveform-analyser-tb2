#include <stdio.h>
#include "waveform.h"
#include "io.h"

int main() {
    FILE *fp = fopen("power_quality_log.csv","r"); //opening required csv file
    if (fp == NULL) {
        printf("Error: file not found\n");
        return 1; //process terminates here
    }

    int count = 0; // setting counter at value: 0


    return 0;
}
