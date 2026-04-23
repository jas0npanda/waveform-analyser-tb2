#include <stdio.h>
#include "waveform.h"

int main(void) {



FILE *fptr;

fptr = fopen("C:\\Users\\wf2-chen\\CLionProjects\\waveform-analyser-tb2\\power_quality_log.csv", "r");

if (fptr == NULL) {
    printf("The file is not opened.");
}
else {
    printf("The file has been opened.");
}


return 0;
}
