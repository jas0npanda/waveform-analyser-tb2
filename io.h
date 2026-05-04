//
// Created by jason on 30/04/2026.
//

#ifndef WAVEFORM_ANALYSER_TB2_IO_H
#define WAVEFORM_ANALYSER_TB2_IO_H
#include <stdio.h>
#include "waveform.h"

struct WaveformSample* load_csv(const char *filename, int *out_count);

void write_results(const char *filename,
                    double rms_a, double rms_b, double rms_c,
                    double p2p_a, double p2p_b, double p2p_c,
                   double dc_a, double dc_b, double dc_c,
                   int clip_a, int clip_b, int clip_c,
                   int tolerance_a, int tolerance_b, int tolerance_c);


#endif //WAVEFORM_ANALYSER_TB2_IO_H