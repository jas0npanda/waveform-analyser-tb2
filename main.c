#include <stdio.h>
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
    struct WaveformSample *data = load_csv(argv[1], &count);

    if (!data) {
        printf("Error: Failed to load data\n");
        return 1;
    }

    printf("Loaded %d samples\n", count);

}