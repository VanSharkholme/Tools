#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        int tmp;
        sscanf(argv[1], "%d", &tmp);
        printf("%X\n", tmp);
    }
    return 0;
}