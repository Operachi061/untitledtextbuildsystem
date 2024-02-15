#include <argp.h>
#include <string.h>

#include "parser.h"
#include "lexer.h"

extern int cparallel;
extern int yes;
extern int debug;
extern char *func;
extern char *modpath;
extern char path[999];

static char doc[] = "UntitledTextBuildSystem - utbs. Part of UntitledTextPack";
static struct argp_option options[] = {
    { "path", 'p', "<path>", 0, "Path to Utbsource file." },
    { "function", 'f', "<function>", 0, "Function in Utbsource file to start." },
    { "yes", 'y', 0, 0, "Confirming question." },
    { "parallel", 'P', 0, 0, "Parallel process (faster)." },
    { "debug", 'd', 0, 0, "Debuging utbs." },
    { 0 }
};
static error_t
    parse_opt (int key, char *arg, struct argp_state *state) {
        switch (key) {
            case 'f':
                func = arg;
                break;
            case 'p':
                modpath = arg;
                strcpy(path, modpath);
                strcat(path, "/Utbsource");
                break;
            case 'y':
                yes = 'y';
                break;
            case 'P':
                cparallel = 'P';
                break;
            case 'd':
                debug = 1;
                break; 
            default:
                return ARGP_ERR_UNKNOWN;
        }
        return 0;
    }
void parser(int argc, char **argv) {
    static struct argp argp = { options, parse_opt, NULL, doc };
    argp_parse (&argp, argc, argv, 0, 0, 0);
}
