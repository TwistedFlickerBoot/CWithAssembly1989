/*********************************************************************************************/
/* Code snippet  from pages 51                                                               */
/* C With Assembly by Steven Holzner - A Brady Book                                          */
/* Typed by Rick/MerlinTheSpook/TwistedFlickerBoot/SchematicRick                             */
/*********************************************************************************************/
/* UPDATING ALONG THE CHAPTER, GIT SHOULD HAVE THE HISTORY BUT I WILL ALSO COMMENT OUT       */
/* INSTEAD OF DELETING                                                                       */
/* I MAY BE TIRED FROM LOOKING AT CODE BUT I THINK THIS CHANGE WAS MEANT FOR THE PREVIOUS    */
/* EXAMPLE IN THE BOOK DEALING WITH NUMBERS.DAT CALLED NUMBERS.C. PG-56 IN BOOK              */
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
    if((file_pointer = fopen("numbers.dat", "r")) == NULL) 
        fread(farray, sizeof(struct entry), INDEX, file_pointer);
    // In the book on page 56 the message in the error states writing when
    // clearly this is reading. 
    else printf("Error reading numbers.dat\n");
    printf("%s owes %.2f\n", farray[0].name, farray[0].owes);
    printf("%s owes %.2f\n", farray[1].name, farray[1].owes);

/*
    // This code is commented out because it is not even remotely close to the example on
    // page 56. I think the author meant to use numbers.c reader instead of reader.c but 
    // this is good practice for muscle memory. 
    int num;

    if((file_pointer = fopen("test.txt", "r")) == NULL)
    {
        while(fscanf(file_pointer, "%d", &num) != EOF) printf("%d\n", num);
        fclose(file_pointer);
    }
    else printf("Error reading file\n");
*/
}