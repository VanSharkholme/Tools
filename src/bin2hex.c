#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        int tmp = 0;
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            tmp = tmp << 1;
            tmp = argv[1][i] == '1' ? tmp + 1: tmp; 
        }
        printf("%X\n", tmp);
        
    }
    

    return 0;
}