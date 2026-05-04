//
// Created by jason on 30/04/2026.
//

#include <stdlib.h> //Used for malloc function
#include "io.h"

#define max_line 256 //Max line length

struct WaveformSample* load_csv(const char *filename, int *out_count) {
    //Loads csv file into array
    FILE *fp = fopen(filename, "r");
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

void write_results(const char *filename, //Calling from io.h
               double rms_a, double rms_b, double rms_c,
               double p2p_a, double p2p_b, double p2p_c,
               double dc_a, double dc_b, double dc_c,
               int clip_a, int clip_b, int clip_c,
               int tolerance_a, int tolerance_b, int tolerance_c) {
    FILE *fp = fopen(filename, "w");
    if (!fp) return;

    fprintf(fp, "RMS A: %.15lf\nRMS B: %.15lf\nRMS C: %.15f\n", rms_a, rms_b, rms_c);
    fprintf(fp, "Peak-to-Peak A: %.15f\nPeak-to-Peak B: %.15f\nPeak-to-Peak C: %.15f\n", p2p_a, p2p_b, p2p_c);
    fprintf(fp, "DC Offset A: %.15f\nDC Offset B: %.15f\nDC Offset C: %.15f\n", dc_a, dc_b, dc_c);
    fprintf(fp, "Clipping values A: %d\nClipping values B: %d\nClipping values C: %d\n",clip_a, clip_b, clip_c);
    fprintf(fp,"RMS A within tolerance: %d\n", tolerance_a);
    fprintf(fp,"RMS B within tolerance: %d\n", tolerance_b);
    fprintf(fp,"RMS C within tolerance: %d\n", tolerance_c);

    fclose(fp);
}
