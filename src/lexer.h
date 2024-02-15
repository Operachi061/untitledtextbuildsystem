#ifdef _LEXER_H_
#define _LEXER_H_

#include "main.h"

extern int i = 0;
extern int cmd;
extern int nwlnc = 0; 
extern int nmbcheck = 0;
extern int optc = 0;
extern int optct = 0;
extern int chkt;
extern int z;
extern int w;
extern int wf;
extern int y;
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

void lexer(void);

#endif /* _LEXER_H_ */
