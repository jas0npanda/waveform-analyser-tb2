//
// Created by jason on 28/04/2026.
//

#include "waveform.h"
#include <stdio.h>
#include <math.h> //Additional existing library used for mathematical functions


double compute_mean(const double *values, int count) { //Dc offset
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += values[i];
    }
    return sum / count;
}

double compute_rms(const double *values, int count) {
    double sum_sq = 0.0; //Math function utilised
    for (int i = 0; i < count; i++) {
        sum_sq += values[i] * values[i];
    }
    return sqrt(sum_sq / count);
}

double compute_peak_to_peak(const double *values, int count) {
    double min = values[0];
    double max = values[0];

    for (int i = 1; i < count; i++) {
        if (values[i] < min) min = values[i];
        if (values[i] > max) max = values[i];
    }
    return max - min;
}

int detect_clipping(const double *values, int count, double threshold) {
    int clipped_values = 0;
    for (int i = 0; i < count; i++) {
        if (values[i] >= threshold || values[i] <= -threshold) {
            clipped_values++;
        }
    }
    return clipped_values;
}

int check_tolerance(double rms, double nominal) {
    double lower = nominal * 0.9;
    double upper = nominal * 1.1;
    return (rms >= lower && rms <= upper);
}
