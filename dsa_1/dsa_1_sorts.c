#include "dsa_1_sorts.h"

int bubbleSort(int *a, int *n){
    int needContinue = 1;
    while(needContinue){
        needContinue = 0;
        for (int i = 1; i < *n; ++i) {
            if(a[i-1] > a[i]){
                int temp = a[i];
                a[i] = a[i-1];
                a[i-1] = temp;
                needContinue = 1;
            }
        }
    }
    return 0;
}

int selectSort(int *a, int *n){
    for (int i = 0; i < *n; ++i) {
        int mni = i;
        for(int j = i; j < *n; j++){
            if(a[j] < a[mni]){
                mni = j;
            }
        }
        int temp = a[i];
        a[i] = a[mni];
        a[mni] = temp;
    }
    return 0;
}

int insertSort(int *a, int *n){
    for (int i = 1; i < *n; ++i) {
        int num = a[i];
        int j = i - 1;
        while(j >= 0 && num < a[j]) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = num;
    }
    return 0;
}

int counterSort(int *a, int *n){
    int counter[10] = {0};
    for (int i = 0; i < *n; ++i) {
        if(a[i] < 0 || a[i] > 9) return 1;
        counter[a[i]] = counter[a[i]]+1;
    }
    int i = 0;
    int ln = counter[0];
    for (int j = 0; j < *n; ++j, ln--) {
        while(!ln) ln = counter[++i];
        a[j] = i;
    }
    return 0;
}