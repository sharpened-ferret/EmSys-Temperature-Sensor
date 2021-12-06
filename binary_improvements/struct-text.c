#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

    typedef struct {
        char gid1[4];
        char gid2[4];
        unsigned int cmd:16;
        unsigned int avg:16;
        unsigned int time0:16;
        unsigned int temp0:16;
        unsigned int time1:16;
        unsigned int temp1:16;
        unsigned int time2:16;
        unsigned int temp2:16;
        unsigned int time3:16;
        unsigned int temp3:16;
        unsigned int time4:16;
        unsigned int temp4:16;
        unsigned int time5:16;
        unsigned int temp5:16;
        unsigned int time6:16;
        unsigned int temp6:16;
        unsigned int time7:16;
        unsigned int temp7:16;
        unsigned int time8:16;
        unsigned int temp8:16;
        unsigned int time9:16;
        unsigned int temp9:16;
        unsigned int time10:16;
        unsigned int temp10:16;
        unsigned int time11:16;
        unsigned int temp11:16;
        unsigned int time12:16;
        unsigned int temp12:16;
        unsigned int time13:16;
        unsigned int temp13:16;
        unsigned int time14:16;
        unsigned int temp14:16;
        unsigned int time15:16;
        unsigned int temp15:16;
    } testStruct;

    typedef struct {
        char gid1[4];
        char gid2[4];
        unsigned int cmd:16;
        unsigned int avg:16;
    } minStruct;

    printf("sizeof test = %zu\n", sizeof(testStruct));
    printf("sizeof test = %zu\n", sizeof(minStruct));

    exit(EXIT_SUCCESS);

}
