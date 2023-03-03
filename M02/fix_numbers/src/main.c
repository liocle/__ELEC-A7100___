#include <stdio.h>

int main(void)
{
    char            varA; 
    unsigned char   varB;
    unsigned int    varB2;  // Error, exceeds the value range -> overflow dealt with by changing data type
    int             varC;  // ok, but initial value is unknown
    long            varD;

    varA = -50;
    varB = 200;
    varB2 = 500;
    varC = 0;  // ok, but initial value is unknown -> no initialized
    varD = 100000;
    /* Output the above values */
    printf("%d  %u  %u  %d  %ld\n", varA, varB, varB2, varC, varD);

    return 0;
}
