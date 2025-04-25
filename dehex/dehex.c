/***********************************************************************************************/
/* dehex.c Page 18-19 in C with Assembly Language by by Steven Holzner                         */
/* typed and tested in QuickC 2 by Rick Baker/MerlinTheSpook/TwistedFlickerBoot/SchematicRick  */
/********************************************************************************************* */
#include <stdio.h>

main()
{
    char x;

    scanf("%c", &x);

    if(x >= 'a')
        x-= 'a' - 10;
    else
        x-= '0';
    printf("The hex digit you typed is equal to %d\n", (int)x);
}