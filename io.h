//
// Created by jason on 30/04/2026.
//

#ifndef WAVEFORM_ANALYSER_TB2_IO_H
#define WAVEFORM_ANALYSER_TB2_IO_H
#include <stdio.h>
#include "waveform.h"

struct WaveformSample* read_waveform(FILE *fp, int *out_count);


#endif //WAVEFORM_ANALYSER_TB2_IO_H