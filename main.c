#include <stdio.h>
#include <stdlib.h>

#include "io.h"
#include "waveform.h"
int main(int argc, char *argv[]) {
    printf("Waveform Analyser started\n");

    // Check command-line arguments
    if (argc < 2) {
        printf("Error: No input file provided\n");
        printf("Usage: %s <inputfile>\n", argv[0]);
        return 1;
    }

    printf("Input file: %s\n", argv[1]);

    int count = 0;

    // Load CSV file
    printf("Loading CSV...\n");
    struct WaveformSample *sample = load_csv(argv[1], &count);

    if (!sample) {
        printf("Error: Failed to load data\n");
        return 1;
    }

    printf("Loaded %d samples\n", count);

    double *a = malloc(count* sizeof(double));
    double *b = malloc(count* sizeof(double));
    double *c = malloc(count* sizeof(double)); // Malloc calls for phase a,b and c

    if (a == NULL || b == NULL || c == NULL) {
        printf("Error: memory allocation failed\n");
        free(a);
        free(b);
        free(c);
        free(sample); //Free memory
        return 1;
    }

    for (int i = 0; i < count; i++) {
        a[i] = sample[i].phase_A_voltage;
        b[i] = sample[i].phase_B_voltage;
        c[i] = sample[i].phase_C_voltage; //Data is arrayed
    }

    double rms_a = compute_rms(a, count);
    double rms_b = compute_rms(b, count);
    double rms_c = compute_rms(c, count);//Calculating rms values

    double p2p_a = compute_peak_to_peak(a, count);
    double p2p_b = compute_peak_to_peak(b, count);
    double p2p_c = compute_peak_to_peak(c, count);

    double dc_a = compute_mean(a, count);
    double dc_b = compute_mean(b, count);
    double dc_c = compute_mean(c, count);

    int clip_a = detect_clipping(a, count, 324.9); //threshold clipping value from brief
    int clip_b = detect_clipping(b, count, 324.9);
    int clip_c = detect_clipping(c, count, 324.9);


    printf("RMS A: %.8lf, Peak-to-Peak A: %.8lf, DC Offset A: %.20lf, Clipping A: %d\n",
           rms_a, p2p_a, dc_a, clip_a);

    printf("RMS B: %.8lf, Peak-to-Peak B: %.8lf, DC Offset B: %.20lf, Clipping B: %d\n",
           rms_b, p2p_b, dc_b, clip_b);

    printf("RMS C: %.8lf, Peak-to-Peak C: %.8lf, DC Offset C: %.20lf, Clipping C: %d\n",
           rms_c, p2p_c, dc_c, clip_c);

    write_results("waveform_results.txt",
        rms_a, rms_b, rms_c,
        p2p_a, p2p_b, p2p_c,
        dc_a, dc_b, dc_c,
        clip_a, clip_b, clip_c);


    free(a);
    free(b);
    free(c);
    free(sample); //Free memory

    return 0;
}