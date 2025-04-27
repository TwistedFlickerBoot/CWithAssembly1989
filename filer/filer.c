/*********************************************************************************************/
/* Code snippet filer.c from pages 49                                                        */
/* C With Assembly by Steven Holzner - A Brady Book                                          */
/* Typed by Rick/MerlinTheSpook/TwistedFlickerBoot/SchematicRick                             */
/*********************************************************************************************/
/* UPDATING ALONG THE CHAPTER, GIT SHOULD HAVE THE HISTORY BUT I WILL ALSO COMMENT OUT       */
/* INSTEAD OF DELETING                                                                       */
/* I MAY BE TIRED FROM LOOKING AT CODE BUT I THINK THIS CHANGE WAS MEANT FOR THE PREVIOUS    */
/* EXAMPLE IN THE BOOK DEALING WITH NUMBERS.DAT CALLED NUMBERS.C. PG-55 IN BOOK              */
/******************************************************************************************* */
#include <stdio.h>
#define INDEX 15

struct entry 
{
    char name[20];
    float owes;
}
main()
{
    FILE *file_pointer;
    struct entry farray[INDEX];

    if((file_pointer = fopen("numbers.dat", "w")) == NULL) 
        fwrite(farray, sizeof(struct entry), INDEX, file_pointer);
    else printf("Error writing numbers.dat\n");  
/*  
    // This code is commented out because it is not even remotely close to the example on
    // page 55. I think the author meant to use numbers.c instead of filer.c but this is
    // good practice for muscle memory.   
    int num;

    if((file_pointer = fopen("number.dat", "w")) == NULL) {
        printf("Type some integers: \n");
        while(scanf("%d", &num) == 1) fprintf(file_pointer, "%d\n", num);
        fclose(file_pointer);
    }
    else printf("Error writing file.txt.\n");
    */
}