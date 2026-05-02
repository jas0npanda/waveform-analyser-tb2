//
// Created by jason on 30/04/2026.
//

#ifndef WAVEFORM_ANALYSER_TB2_IO_H
#define WAVEFORM_ANALYSER_TB2_IO_H
#include <stdio.h>
#include "waveform.h"

struct WaveformSample* load_csv(const char * filename, int *out_count);

void write_results(const char *filename,
                    double rms_a, double rms_b, double rms_c,
                    double ptp_a, double ptp_b, double ptp_c,
                   double dc_a, double dc_b, double dc_c,
                   int clipping_a, int clipping_b, int clipping_c);)


#endif //WAVEFORM_ANALYSER_TB2_IO_H