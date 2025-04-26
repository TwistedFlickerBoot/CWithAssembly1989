/*********************************************************************************************/
/* Code snippet  from pages 51                                                               */
/* C With Assembly by Steven Holzner - A Brady Book                                          */
/* Typed by Rick/MerlinTheSpook/TwistedFlickerBoot/SchematicRick                             */
/*********************************************************************************************/
#include <stdio.h>

main()
{
    FILE *file_pointer;
    int num;

    if((file_pointer = fopen("test.txt", "r")) == NULL)
    {
        while(fscanf(file_pointer, "%d", &num) != EOF) printf("%d\n", num);
        fclose(file_pointer);
    }
    else printf("Error reading file\n");
}