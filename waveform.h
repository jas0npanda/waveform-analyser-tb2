//
// Created by jason on 28/04/2026.
//

#ifndef WAVEFORM_ANALYSER_TB2_WAVEFORM_H
#define WAVEFORM_ANALYSER_TB2_WAVEFORM_H


struct WaveformSample {
    char timestamp;
    double phase_A_voltage;
    double phase_B_voltage;
    double phase_C_voltage;
    double line_current;
    double frequency;
    double power_factor;
    double thd_percent; ///Used double to avoid rounding errors and increased accuracy///
};

float calc_average(const struct WaveformSample *samples, int count);
float calc_max(const struct WaveformSample *samples, int count);

#endif