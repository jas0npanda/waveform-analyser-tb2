//
// Created by wf2-chen on 23/04/2026.
//

#ifndef WAVEFORM_ANALYSER_TB2_WAVEFORM_H
#define WAVEFORM_ANALYSER_TB2_WAVEFORM_H

struct WaveformSample {
    char timestamp;
    float phase_A_voltage;
    float phase_B_voltage;
    float phase_C_voltage;
    float line_current;
    float frequency;
    float power_factor;
    float thd_percent;
};

#endif //WAVEFORM_ANALYSER_TB2_WAVEFORM_H
