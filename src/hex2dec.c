#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        int tmp = 0;
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            tmp *= 16;
            char digit = argv[1][i];
            if (digit >= '0' && digit <= '9')
            {
                tmp += digit - '0';
            }
            
            else if ((digit >= 'A' && digit <= 'F') || (digit >= 'a' && digit <= 'f'))
            {
                if (digit > 70)
                {
                    digit -= 32;
                }
                switch (digit)
                {
                case 'A':
                    tmp += 10;
                    break;
                case 'B':
                    tmp += 11;
                    break;
                case 'C':
                    tmp += 12;
                    break;
                case 'D':
                    tmp += 13;
                    break;
                case 'E':
                    tmp += 14;
                    break;
                case 'F':
                    tmp += 15;
                    break;                
                default:
                    break;
                }
            }
        }
        printf("%d\n", tmp);
    }
    return 0;
}