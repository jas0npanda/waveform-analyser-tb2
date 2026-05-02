//
// Created by jason on 30/04/2026.
//

#include <stdlib.h> //Used for malloc function
#include "io.h"

#define max_line 256 //Max line length

struct WaveformSample* load_csv(const char *filename, int *out_count) {
    //Loads csv file into array
    FILE *fp = fopen("power_quality_log.csv", "r");
    if (!fp)
        return NULL;

    char line[max_line];

    int count = 0; //Counter for no. of rows

    fgets(line, max_line, fp); //Skipping header line

    while (fgets(line, max_line, fp))
        count ++;


}
