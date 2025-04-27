/*********************************************************************************************/
/* Code snippet numbers.c from pages 53-54                                                   */
/* C With Assembly by Steven Holzner - A Brady Book                                          */
/* Typed by Rick/MerlinTheSpook/TwistedFlickerBoot/SchematicRick                             */
/*********************************************************************************************/
#include <stdio.h>
#define INDEX 15

main()
{
    FILE *file_pointer;
    float farray[INDEX] = {1.2, 3.78, 1.553, 9.1, -3.14159};

    if((file_pointer = fopen("numbers.dat", "w")) == NULL) fwrite(farray, sizeof(float), INDEX, file_pointer);
    else printf("Error writing numbers.dat\n");
    fclose(file_pointer);
}