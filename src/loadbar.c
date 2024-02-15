#include <stdio.h>
#include <unistd.h>

#include "loadbar.h"

char space[101] = "                                                   ";
int barc = 0;

void loadbar(const int count) {
    char percentage[2] = "%";
    printf("\r%sutbs (%s%s%s%s%s)%s %s%d%s%s", "\033[0;34m", "\033[0;0m", "\033[0;36m", space, "\033[0;0m", "\033[0;34m", "\033[0;0m", "\033[0;32m", 100 / count, percentage, "\033[0;0m");
    fflush(stdout);
    printf("\n");
    while (barc < 100 / count) {
        barc++;
        space[barc-1] = '-';
        space[barc] = '>';
    }
}
