/*********************************************************************************************/
/* Code snippet to write to hello.txt from pages 41-44                                       */
/* C With Assembly by Steven Holzner - A Brady Book                                          */
/* Typed by Rick/MerlinTheSpook/TwistedFlickerBoot/SchematicRick                             */
/*********************************************************************************************/
#include <stdio.h>

main()
{
    FILE *file_pointer;
    if((file_pointer = fopen("hello.txt", "w")) == NULL) 
    {
        fprintf(file_pointer, "Hello, world!\n");
        fclose(file_pointer);
    }
    else printf("Error writing to hello.txt\n");
}
