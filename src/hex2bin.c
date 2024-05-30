//
// Created by 13651 on 2024/5/30.
//
#include "stdio.h"
#include "string.h"

int main(int argc, char** argv)
{
    if(argc == 2)
    {
        unsigned long long num, cnt = 0;
        sscanf(argv[1], "%llx", &num);
        while(num)
        {
            printf("%1d", num & 1);
            num = num >> 1;
            if(cnt++ % 4 == 3)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}