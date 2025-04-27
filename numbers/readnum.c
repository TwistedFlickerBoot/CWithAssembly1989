/*********************************************************************************************/
/* Code snippet readnum.c from pages 53-54                                                   */
/* C With Assembly by Steven Holzner - A Brady Book                                          */
/* Typed by Rick/MerlinTheSpook/TwistedFlickerBoot/SchematicRick                             */
/*********************************************************************************************/
#include <stdio.h>
#define INDEX 15

main()
{
    FILE *file_pointer;
    float farray[INDEX];
    int i;

    if((file_pointer = fopen("numbers.dat", "r")) == NULL) fread(farray, sizeof(float), INDEX, file_pointer);
    else printf("Error reading numbers.dat\n");
    for(i = 0; INDEX - i; i++) printf("%f\n", farray[i]);
    fclose(file_pointer);
}