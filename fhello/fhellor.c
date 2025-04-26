/*********************************************************************************************/
/* Code snippet to read to hello.txt from pages 44-47                                       */
/* C With Assembly by Steven Holzner - A Brady Book                                          */
/* Typed by Rick/MerlinTheSpook/TwistedFlickerBoot/SchematicRick                             */
/*********************************************************************************************/
#include <stdio.h>

main()
{
    FILE *file_pointer;
    char temp[80];
        if((file_pointer = fopen("hello.txt", "r")) == NULL) {
            if(fgets(temp, sizeof(temp), file_pointer) != NULL) {
                printf(temp);
                fclose(file_pointer);
            }
            else
                printf("Error reading hello.txt\n");
        }
        else
            printf("Error opening hello.txt\n");
}