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

    rewind(fp);
    fgets(line, max_line, fp); //Skip header line again

    struct WaveformSample* samples = malloc(count * sizeof(struct WaveformSample));
    if (!samples) return NULL;

    int i = 0; //i acts as a counter
    while (fgets(line, max_line, fp)) {
        sscanf(line, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
            &samples[i].timestamp,
            &samples[i].phase_A_voltage,
            &samples[i].phase_B_voltage,
            &samples[i].phase_C_voltage,
            &samples[i].line_current,
            &samples[i].frequency,
            &samples[i].power_factor,
            &samples[i].thd_percent);

        //printf("Parsed A as: %f\n", samples[i].phase_A_voltage); //Debug message used in testing

        i++; //counter incremented by one

    }



    fclose(fp);
    *out_count = count;
    return samples;

}
