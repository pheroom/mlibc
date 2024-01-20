#include "m_cat.h"

struct {
    unsigned int b : 1;
    unsigned int e : 1;
    unsigned int n : 1;
    unsigned int s : 1;
    unsigned int t : 1;
} flags;

int main(int argc, char **argv){
    char files[10][100];
    int filesCount = 0;
    while(--argc){
        char *arg = *++argv;
        if(*arg == '-'){
            char flag;
            while ((flag = *++arg) != '\0'){
                switch (flag) {
                    case 'b':
                        flags.b = 1;
                        break;
                    case 'e': case 'E':
                        flags.e = 1;
                        break;
                    case 'n':
                        flags.n = 1;
                        break;
                    case 's':
                        flags.s = 1;
                        break;
                    case 't': case 'T':
                        flags.t = 1;
                        break;
                    default:
                        fprintf(stderr, ERROR_02, flag);
                        return 0;
                }
            }
        } else{
            strcpy(files[filesCount++], arg);
        }
    }

    int linesCount = 0;
    int status = 0;
    for (int i = 0; i < filesCount; ++i) {
        processFile(files[i], &linesCount, &status);
        if(status) return status;
    }

    return 0;
}

void processFile(char *file, int *linesCount, int *status){
    FILE *fp = fopen(file, "r");
    if(fp != NULL){
        int isPrevLineEmpty = 0;
        int sym, ln = 0;
        while((sym = getc(fp)) != EOF){
            if(sym == '\n'){
                if(!ln){
                    if(!flags.s){
                        if(flags.n && !flags.b) printf("\t%d  ", ++*linesCount);
                        if(flags.e) printf("$");
                        printf("\n");
                    }
                    isPrevLineEmpty = 1;
                } else{
                    if(flags.e) printf("$");
                    printf("\n");
                }
                ln = 0;
            }else{
                if(!ln){
                    if(flags.s && (!(flags.n && !flags.b) || linesCount) && isPrevLineEmpty){
                        if(flags.n && !flags.b) printf("\t%d  ", ++*linesCount);
                        if(flags.e) printf("$");
                        printf("\n");
                    }
                    isPrevLineEmpty = 0;
                    if(flags.n || flags.b) printf("\t%d  ", ++*linesCount);
                }
                if(flags.t && sym == '\t') printf("^I");
                else printf("%c", sym);
                ln++;
            }
        }
    } else{
        fprintf(stderr, ERROR_01, file);
        *status = 1;
    }
}
