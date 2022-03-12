#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    /* input*/
    /* There are 512-bit block */
    int block[4];

    for(int i=0; i<4; i++){
        block[i] = argv[i+1][0];
        //printf("The block = %d\n", block[i]);
    }
    
    block[0] += block[1];
    block[3] ^= block[0];
    block[3] = block[3] << 16;

    block[2] += block[2];
    block[1] ^= block[2];
    block[1] = block[1] << 12;

    block[0] += block[1];
    block[3] ^= block[0];
    block[3] = block[3] << 8;

    block[2] += block[2];
    block[1] ^= block[2];
    block[1] = block[1] << 7;

    for(int i=0; i<4; i++){
        //block[i] = argv[i+1][0];
        printf("The block = %d\n", block[i]);
    }


    
}