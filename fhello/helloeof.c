/*********************************************************************************************/
/* Code snippet to read to hello.txt from pages 46-47                                        */
/* C With Assembly by Steven Holzner - A Brady Book                                          */
/* Typed by Rick/MerlinTheSpook/TwistedFlickerBoot/SchematicRick                             */
/*********************************************************************************************/
#include <stdio.h>

main()
{
    int buff1;
    FILE *file_pointer;

    if(file_pointer = fopen("hello.txt", "r"))
    {
        while((buff1 = getc(file_pointer)) != EOF)
            printf("%c", buff1);
            printf("\n");
            fclose(file_pointer);
    }
    else
    {
        printf("Couldn't open hello.txt\n");
    }
}