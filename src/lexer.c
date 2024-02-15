#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "lexer.h"
#include "parser.h"

#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define CYAN    "\033[0;36m"
#define END     "\033[0;0m"

#define MAX_SIZE 999

extern int i;
extern int cmd;
extern int nwlnc;
extern int nmbcheck;
extern int optc;
extern int optct;
extern int chkt;
extern int z;
extern int w;
extern int wf;
extern int yf;
extern char parserch[MAX_SIZE];
extern char chk[MAX_SIZE];
extern char optf[MAX_SIZE];
extern char optft[MAX_SIZE];
extern char optn[MAX_SIZE];
extern char opt[MAX_SIZE];
extern char newf[MAX_SIZE];
extern char newn[MAX_SIZE];
extern char new[MAX_SIZE];
extern char strchk[MAX_SIZE];
extern char rfile[MAX_SIZE];
extern char file[MAX_SIZE];
char rfo[MAX_SIZE];
char rfpo[MAX_SIZE];
char *optftf;
int blankc = 0;
int h = 0;
int g;
int yfc = 0;
int v = 1;

int cparallel;
int yes;
int debug;
char *func;
char *modpath;
char path[999];

void lexer(void) {
    i = 0;
    nwlnc = 0; 
    nmbcheck = 0;
    FILE *fp = fopen(path, "r");
    FILE *fpt = fopen(path, "r");
    FILE *ffo = fopen(path, "r");
    if (fp == NULL) {
        printf("%snot found%s\n", RED, END);
        printf("Exiting.\n");
        exit(0);
    } else {
        printf("%sfound%s\n", GREEN, END);
    }
    printf("  Finding functions in parser\n");
    if (func == NULL) {
        printf("    FUNCTION NOT FOUND\n");
        printf("Exiting.\n");
        exit(0);
    } else {
        printf("    FUNCTION FOUND\n");
    }
    strcat(chk, func);
    strcat(chk, " <");
    while (fgets(rfile, sizeof rfile, fp) != NULL) {
        char *position = strstr(rfile, chk);
        if (position == chk) {
            break;
        } else {
            i++;
        }
        if (position == NULL) {
            printf("  %s/Utbsource >> %s[ LINE: %d]%s %s\n", modpath, RED, i, END, "NOT FOUND");
            nmbcheck = 1;
        } else {
            position[strlen(chk)] = '\0';
            printf("  %s/Utbsource >> %s[ LINE: %d]%s \'%s\' %s->%s %sfound%s\n", modpath, RED, i, END, position, CYAN, END, GREEN, END);
            nmbcheck = 2;
            break;
        }
        strcat(strchk, rfile);
    }
    if (debug == 1) {
        printf("%s!========================================================================!\n%s", RED, END);
    }
    if (nmbcheck == 1) {
        printf("  function named '%s' not found.\n", func);
        printf("Exiting.\n");
        exit(0);
    } else if (nmbcheck == 2) {
        NULL;
    } else {
        NULL;
    }
    while (fgets(rfile, sizeof rfile, fpt) != NULL) {
        strcat(file, rfile);  
    }
    for (int x = 0; x < strlen(strchk) + strlen(chk) + 1; x++) {
        file[x] = ' ';
    }
    for (int y = 0; y < strlen(file); y++) {
        if (file[y] == '>') {
            file[y] = '\0';
        }
    }
    file[strlen(file) - 1] = '\0';
    while (fgets(rfile, sizeof rfile, ffo) != NULL) {
        for (int x = 0; x < strlen(rfile); x++) {
            if (rfile[x] == '@') {
                optct++;
            }
        }
    }
    strcpy(rfpo, file);
    optct++;
    for (g = 1; g < optct; g++) {
        if (file[z + 2] == '@') {
            file[yf - v] = ' ';
        } 
        FILE *fpo = fopen(path, "r");
        FILE *ffpo = fopen(path, "r");
        while (fgets(rfile, sizeof rfile, fpo) != NULL) {
            for (int x = 0; x < strlen(rfile); x++) {
                if (rfile[x] == '=') {
                    strcat(optf, rfile);
                }
            }
        }
        for (int x = 0; x < strlen(optf); x++) {
            if (optf[x] == '=') {
                break;
            } else {
                optn[x] = ' ';
           }
        }
        while (fgets(rfile, sizeof rfile, ffpo) != NULL) {
            strcat(optft, rfile);
        }
        if (g > 1) {
            for (z = yfc; z < strlen(optft); z++) {
                if (optft[z] == '{') {
                    break;
                } else {
                    NULL;
                } 
            }
        } else {
            for (z = 0; z < strlen(optft); z++) {
                if (optft[z] == '{') {
                    break;
                } else {
                    yfc++;
                } 
            }
        }
        optc = 0;
        while (z < strlen(optft)) {
            z++;
            optc++;
            if (optft[z] == '}') {
                yfc++;
                break;
            } else {
                if (optn[optc] == ' ') {
                    z--;
                    blankc++;
                    yfc++;
                } else {
                    optn[optc - blankc] = optft[z];
                    yfc++;
                }
            } 
        }
        blankc = 0;
        z = 0;
        for (int x = 0; x < strlen(optn); x++) {
            optn[x - 1] = optn[x];
        }
        optn[strlen(optn)] = ' ';
        for (z = 0; z < strlen(optft); z++) {
            if (optft[z] == '{') {
                break;
            } else {
                NULL;
            } 
        }
        int j = 0;
        char optff[MAX_SIZE];
        for (int k = 1; k < optct; k++) {
            while (z < strlen(optft)) {
                z++;
                if (optft[z] == '}') {
                    break;
                } else {
                    j++;
                    optff[j] = optft[z];
                } 
            }
            if (optn == optff) {
                break;
            } else {
                NULL;
            }
        }
        strcpy(optft, optf);
        z = 0;
        int y;
        int h;
        for (y = 0; y < strlen(optf); y++) {
            if (optf[y] == optn[z]) {
                break;
            }
        }
        for (h = y; h < strlen(optf); h++) {
           if (optf[h] == '"'){
                break;
            } else {
                NULL;
            }
        }
        optc = 0;
        for (y = h; y < strlen(optf); y++) {
            opt[optc] = optf[y];
            optc++;
        }
        opt[0] = ' ';
        for (y = 0; y < strlen(opt); y++) {
            if (opt[y] == '"') {
                for (h = y; h < strlen(opt); h++) {
                    opt[h] = ' ';
                }
            }
        }
        for (y = 0; y < strlen(opt); y++) {
            opt[y-1] = opt[y];
        }
        if (debug == 1){
            printf("%s[DEBUG]: OPTION-NAME: %s%s\n", GREEN, optn, END);
            printf("%s[DEBUG]: OPTION: %s%s\n", GREEN, opt, END);
        }
        if (g > 1) {
            for (z = yfc; z < strlen(file); z++) {
                if (file[z] == '@') {
                    break;
                } else {
                    NULL;
                }
            }
        } else {
            for (z = 0; z < strlen(file); z++) {
                if (file[z] == '@') {
                    break;
                } else {
                    NULL;
                }
            }
        }
        for (h = 0; h < strlen(rfpo); h++) {
            if (rfpo[h] == '}') {
                h++;
                break;
            }
        }
        for (int c = h; c < strlen(rfpo); c++) {
            rfo[c - h] = rfpo[c];
        }
        rfo[0] = ' ';
        yf = 0;
        wf = 0;
        if (file[z] == '@') {
            for (yf = z; yf < z + strlen(opt); yf++) {
                wf++;
                file[yf] = opt[wf - 1]; 
            }
            v = 1;
            while (file[yf - v]) {
                if (file[yf - v] != ' ') {
                    break;
                } else {
                    v++;
                }
            }
            v--;
            file[yf - 2] = '\n';
            file[yf - 3] = ' ';
            file[yf - v] = ':';
        }
        optf[0] = 0;
        optn[0] = 0;
        optft[0] = 0;
        opt[0] = 0;
    }
}
