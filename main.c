#include <stdio.h>
#include <stdlib.h>

#include "waveform.h"
#include "io.h"
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
        free(sample);
        return 1;
    }

    for (int i = 0; i < count; i++) {
        a[i] = sample[i].phase_A_voltage;
        b[i] = sample[i].phase_B_voltage;
        c[i] = sample[i].phase_C_voltage; //Data is arrayed
    }

    double rms_a = compute_rms(a, count);
    double p2p_a = compute_peak_to_peak(a, count);
    double dc_a = compute_mean(a, count);
    int clip_a = detect_clipping(a, count, 324.9); //threshold clipping value from brief

    printf("RMS A: %lf, Peak-to-Peak A: %lf, DC Offset A: %.20lf, Clipping A: %d\n",
           rms_a, p2p_a, dc_a, clip_a);


    return 0;
}