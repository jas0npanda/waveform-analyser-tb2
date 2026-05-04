//
// Created by jason on 28/04/2026.
//

#ifndef WAVEFORM_ANALYSER_TB2_WAVEFORM_H
#define WAVEFORM_ANALYSER_TB2_WAVEFORM_H



struct WaveformSample {
    double timestamp;
    double phase_A_voltage;
    double phase_B_voltage;
    double phase_C_voltage;
    double line_current;
    double frequency;
    double power_factor;
    double thd_percent; //Used double to avoid rounding errors and increased accuracy
};

double compute_rms(const double *values, int count); //Defining methods found in brief
double compute_mean(const double *values, int count);
double compute_peak_to_peak(const double *values, int count);
int detect_clipping(const double *values, int count, double threshold);
int check_tolerance(double rms, double nominal);

#endif