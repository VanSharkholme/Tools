#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        int tmp = -1;
        sscanf(argv[1], "%d", &tmp);
        if(tmp >= 33 && tmp <= 126)
            printf("%c\n", tmp);
        else
        {
            switch (tmp)
            {
            case 0:
                printf("\\0\n");
                break;
            case 1:
                printf("SOH\n");
                break;
            case 2:
                printf("STX\n");
                break;
            case 3:
                printf("ETX\n");
                break;
            case 4:
                printf("EOT\n");
                break;
            case 5:
                printf("ENQ\n");
                break;
            case 6:
                printf("ACK\n");
                break;
            case 7:
                printf("\\a\n");
                break;
            case 8:
                printf("\\b\n");
                break;
            case 9:
                printf("\\t\n");
                break;
            case 10:
                printf("\\n\n");
                break;
            case 11:
                printf("\\v\n");
                break;
            case 12:
                printf("\\f\n");
                break;
            case 13:
                printf("\\r\n");
                break;
            case 14:
                printf("SO\n");
                break;
            case 15:
                printf("SI\n");
                break;
            case 16:
                printf("DLE\n");
                break;
            case 17:
                printf("DC1\n");
                break;
            case 18:
                printf("DC2\n");
                break;
            case 19:
                printf("DC3\n");
                break;
            case 20:
                printf("DC4\n");
                break;
            case 21:
                printf("NAK\n");
                break;
            case 22:
                printf("SYN\n");
                break;
            case 23:
                printf("ETB\n");
                break;
            case 24:
                printf("CAN\n");
                break;
            case 25:
                printf("EM\n");
                break;
            case 26:
                printf("SUB\n");
                break;
            case 27:
                printf("ESC\n");
                break;
            case 28:
                printf("FS\n");
                break;
            case 29:
                printf("GS\n");
                break;
            case 30:
                printf("RS\n");
                break;
            case 31:
                printf("US\n");
                break;
            case 127:
                printf("DEL");
                break;
            default:
                printf("Error\n");
                break;
            }
        }
        
    }
    
    return 0;
}