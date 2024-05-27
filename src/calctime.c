#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define DIFFER 1
#define UNTIL 2
#define VALID 1
#define INVALID 0

typedef struct
{
    int H;
    int M;
    int S;
} TimeStruct;

typedef struct
{
    TimeStruct begin;
    TimeStruct end;
    TimeStruct diff;
} CalcStruct;

int modeparse(char* modestr)
{
    if (strcmp(modestr, "-d") == 0)
    {
        return DIFFER;
    }
    else if (strcmp(modestr, "-t") == 0)
    {
        return UNTIL;
    }
    else
    {
        return 0;
    }    
}

int time_valid(TimeStruct t)
{
    return (t.H >= 0 && t.H <= 60) && (t.M >= 0 && t.M <= 60) && (t.S >= 0 && t.S <= 60);
}

int argparse(int mode, char** argv, CalcStruct* res)
{
    switch (mode)
    {
    case DIFFER:
        sscanf(argv[2], "%d.%d.%d", &res->begin.H, &res->begin.M, &res->begin.S);
        sscanf(argv[3], "%d.%d.%d", &res->end.H, &res->end.M, &res->end.S);
        res->diff.H = res->diff.M = res->diff.S = 0;
        if(time_valid(res->begin) && time_valid(res->end))
            return VALID;
        break;
    case UNTIL:
        sscanf(argv[2], "%d.%d.%d", &res->begin.H, &res->begin.M, &res->begin.S);
        sscanf(argv[3], "%d.%d.%d", &res->diff.H, &res->diff.M, &res->diff.S);
        res->end.H = res->end.M = res->end.S = 0;
        if(time_valid(res->begin))
            return VALID;
    default:
        return INVALID;
        break;
    }
}

void calculate(CalcStruct* strCalc, int mode)
{
    if (mode == DIFFER)
    {
        int start_secs = strCalc->begin.H * 3600 + strCalc->begin.M * 60 + strCalc->begin.S;
        int end_secs = strCalc->end.H * 3600 + strCalc->end.M * 60 + strCalc->end.S;
        if (end_secs >= start_secs)
        {
            int interval = end_secs - start_secs;
            strCalc->diff.H = interval / 3600;
            strCalc->diff.M = (interval % 3600) / 60;
            strCalc->diff.S = interval % 60;
            printf("difference: %02dh%02dm%02ds(%.2fh or %.2fm or %ds)\n",
                strCalc->diff.H, strCalc->diff.M, strCalc->diff.S,
                interval * 1.0 / 3600, interval * 1.0 / 60, interval);
        }
        else
        {            
            int interval = start_secs - end_secs;
            strCalc->diff.H = interval / 3600;
            strCalc->diff.M = (interval % 3600) / 60;
            strCalc->diff.S = interval % 60;
            printf("difference: -%02dh%02dm%02ds(-%.2fh or -%.2fm or -%ds)\n",
                strCalc->diff.H, strCalc->diff.M, strCalc->diff.S,
                interval * 1.0 / 3600, interval * 1.0 / 60, interval);
        }
    }
    else if (mode == UNTIL)
    {
        int start_secs = strCalc->begin.H * 3600 + strCalc->begin.M * 60 + strCalc->begin.S;
        int diff_secs = strCalc->diff.H * 3600 + strCalc->diff.M * 60 + strCalc->diff.S;
        int end = diff_secs + start_secs;
        strCalc->end.H = (end / 3600) % 24;
        strCalc->end.M = (end % 3600) / 60;
        strCalc->end.S = end % 60;
        printf("end: %2dh%2dm%2ds\n", strCalc->end.H, strCalc->end.M, strCalc->end.S);
    }
    else
    {
        /* code */
    }
    
}

int main(int argc, char** argv)
{
    if (argc == 4)
    {
        int mode = modeparse(argv[1]);
        CalcStruct strCalc = {0};
        if (argparse(mode, argv, &strCalc))
        {
            calculate(&strCalc, mode);
        }
    }
    return 0;
}