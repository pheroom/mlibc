#include "m_grep.h"

struct {
    unsigned int e : 1;
    unsigned int i : 1;
    unsigned int v : 1;
    unsigned int c : 1;
    unsigned int l : 1;
    unsigned int n : 1;
    unsigned int h : 1;
    unsigned int s : 1;
    unsigned int f : 1;
    unsigned int o : 1;
} flags;

int main(int argc, char **argv){
    if(argc < 3) {
        fprintf(stderr, ERROR_03);
        return 0;
    }
    PATTERNS patterns = {};
    int patternsCount = 0;
    char *patternFile;
    int paramExcept = 0;
    FILES files;
    int filesCount = 0;
    while(--argc){
        char *arg = *++argv;
        if(*arg == '-'){
            char flag;
            while ((flag = *++arg) != '\0'){
                switch (flag) {
                    case 'e':
                        flags.e = 1;
                        paramExcept = 1;
                        break;
                    case 'i':
                        flags.i = 1;
                        break;
                    case 'v':
                        flags.v = 1;
                        break;
                    case 'c':
                        flags.c = 1;
                        break;
                    case 'l':
                        flags.l = 1;
                        break;
                    case 'n':
                        flags.n = 1;
                        break;
                    case 'h':
                        flags.h = 1;
                        break;
                    case 's':
                        flags.s = 1;
                        break;
                    case 'f':
                        flags.f = 1;
                        paramExcept = 1;
                        break;
                    case 'o':
                        flags.o = 1;
                        break;
                    default:
                        fprintf(stderr, ERROR_02, flag);
                        return 0;
                }
            }
        } else if (paramExcept){
            if(flags.e){
                strcpy(patterns[patternsCount++],arg);
                flags.e = 0;
                paramExcept = 0;
            } else if(flags.f){
                patternFile = arg;
                paramExcept = 0;
            }
        } else{
            strcpy(files[filesCount++], arg);
        }
    }

    if(flags.i){
        for (int i = 0; i < patternsCount; ++i) toLower(patterns[i]);
    }

    int goodLines = 0;
    int isGoodFile = 0;
    if(!(flags.v && flags.o)){
        for (int i = 0; i < filesCount; ++i) {
            processFile(files[i], patterns, patternsCount, &goodLines, &isGoodFile);
            if(flags.l && isGoodFile) printf("%s\n", files[i]);
            isGoodFile = 0;
            if(flags.c) printf("%s:%d\n", files[i], goodLines);
            goodLines = 0;
        }
    }

    return 0;
}

void processFile(char *file, PATTERNS patterns, int patternsCount, int *goodLines, int *isGoodFile){
    FILE *fp = fopen(file, "r");
    if(fp){
        char s[BUFFER_SIZE];
        int linesCount = 0;
        while((fgets(s, BUFFER_SIZE, fp))!=NULL)
        {
            linesCount++;
            if(flags.i) toLower(s);
            if(!flags.v){
                for (int i = 0; i < patternsCount; ++i) {
                    if(strstr(s, patterns[i]) != NULL){
                        if(!flags.l){
                            if(!flags.c){
                                if(!flags.h) printf("%s:", file);
                                if(flags.n) printf("%d:", linesCount);
                                if(!flags.o){
                                    printf("%s", s);
                                }else{
                                    printf("%s\n", patterns[i]);
                                }
                            }else{
                                (*goodLines)++;
                            }
                        } else{
                            *isGoodFile = 1;
                            return;
                        }
                        if(!flags.o){
                            break;
                        }
                    }
                }
            } else{
                for (int i = 0; i < patternsCount; ++i) {
                    if(strstr(s, patterns[i]) != NULL){
                        break;
                    }
                    if(i == patternsCount - 1){
                        if(!flags.l){
                            if(!flags.c){
                                if(!flags.h) printf("%s:", file);
                                if(flags.n) printf("%d:", linesCount);
                                printf("%s", s);
                            }else{
                                (*goodLines)++;
                            }
                        } else{
                            *isGoodFile = 1;
                            return;
                        }
                    }
                }
            }

        }
    }else if(!flags.s){
        fprintf(stderr, ERROR_01, file);
    }
}

char* toLower(char* s) {
    for(char *p=s; *p; p++) *p=tolower(*p);
    return s;
}