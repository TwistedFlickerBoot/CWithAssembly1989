/***********************************************************************************************/
/* dehex.c Page 18-19 in C with Assembly Language by by Steven Holzner                         */
/* typed and tested in QuickC 2 by Rick Baker/MerlinTheSpook/TwistedFlickerBoot/SchematicRick  */
/* 4/25/2024-11:05 Updated to use switch instead of if                                         */
/*                 SWITCH is a good C construction when a variety of inputs need to be sorted  */
/********************************************************************************************* */
#include <stdio.h>

main()
{
    char x;

    scanf("%c", &x);

    switch (x) {
        case 'a':
            printf("The hex digit you typed is equal to 10\n");
            break;
        case 'b':
            printf("The hex digit you typed is equal to 11\n");
            break;
        case 'c':
            printf("The hex digit you typed is equal to 12\n");
            break;
        case 'd':
            printf("The hex digit you typed is equal to 13\n");
            break;
        case 'e':
            printf("The hex digit you typed is equal to 14\n");
            break;
        case 'f':
            printf("The hex digit you typed is equal to 15\n");
            break;
        default: {
            x -= '0':
                printf("The hex digit you typed is equal to %d\n", (int)x);
                break;
        }
    }


/* We can use a switch statement to check the value of x and convert it to decimal 
   We comment out this if statement and use a switch statement instead.  
   if(x >= 'a')
        x-= 'a' - 10;
    else
        x-= '0';
    printf("The hex digit you typed is equal to %d\n", (int)x);
*/

}