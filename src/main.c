#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#include "loadbar.h"
#include "parallel.h"
#include "parser.h"
#include "main.h"

#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define CYAN    "\033[0;36m"
#define END     "\033[0;0m"

#define MAX_SIZE 999

int i = 0;
int cmd;
int nwlnc = 0; 
int nmbcheck = 0;
int optc = 0;
int optct = 0;
int chkt;
int z;
int w;
int wf;
int y;
int yf;
char parserch[MAX_SIZE];
char chk[MAX_SIZE];
char optf[MAX_SIZE];
char optft[MAX_SIZE];
char optn[MAX_SIZE];
char opt[MAX_SIZE];
char newf[MAX_SIZE];
char newn[MAX_SIZE];
char new[MAX_SIZE];
char strchk[MAX_SIZE];
char rfile[MAX_SIZE];
char file[MAX_SIZE];

extern int cparallel;
extern int yes;
extern char *func;
extern char *modpath;
extern char path[999];
void utbsinf(void) { printf("%sUtbs -> %s", BLUE, END); }
int system(const char *command);
void loadbar(const int count);
void parallel(char *cmd);
void parser(int argc, char **argv);
void lexer(void);
int main(int argc, char **argv) {
    parser(argc, argv);
    printf("You started utbs.\n");
    utbsinf(); printf("Preparing process\n");
    printf("%s Utbsource file check -> %s", CYAN, END);
    lexer();
    printf("%s!========================================================================!\n%s", RED, END);
    printf("%sProcess to be maked%s %s->%s       \n", BLUE, END, CYAN, END);
    printf("%s\n", file);
    if (yes == 'y') {
        printf("%sUSED%s %s-y%s %sOPTION%s\n", GREEN, END, YELLOW, END, GREEN, END);
    } else {
        printf("%sHint: You can skip question via adding \'-y\' option.%s\n", YELLOW, END);
        printf("%sMake this process ?%s %s|%s %sN%s%s/%s%sy%s ", BLUE, END, CYAN, END, GREEN, END, YELLOW, END, RED, END);
        scanf("%c", parserch);
        if (!strcmp(parserch, "N")) {
            printf("Exiting.\n");
            return 0;
        } else if (!strcmp(parserch, "n")) {
            printf("Exiting.\n");
            return 0;
        } else if (!strcmp(parserch, "Y")) {
            NULL;
        } else if (!strcmp(parserch, "y")) {
            NULL;
        } else {
            printf("Exiting.\n");
            return 0;
        }
    }
    utbsinf(); printf("Starting %s process\n", func);
    for (int cfile = 0; cfile < strlen(file); cfile++) {
        if (file[cfile] == ':') {
            nwlnc++;
        }
    }
    int countf = nwlnc + 1;
    for (int tcfile = 0; tcfile < strlen(file); tcfile++) {
        if (file[tcfile] == ':') {
            char tcfilef[MAX_SIZE];
            strcpy(tcfilef, file);
            tcfilef[tcfile] = '\0';
            if (cparallel == 'P') {
                parallel(tcfilef);
            } else {
                system(tcfilef);
                if (countf > 0) {
                    countf--;
                    loadbar(countf);
                }
            }
            for (int tcfileb = 0; tcfileb < tcfile; tcfileb++) {
                file[tcfileb] = ' ';
            }
        }
    }
    utbsinf(); printf("Finished %s process\n", func);
    printf("Exiting.\n");
    return 0; 
}
