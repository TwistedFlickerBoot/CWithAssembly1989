/*********************************************************************************************/
/* Code snippet filer.c from pages 49                                                        */
/* C With Assembly by Steven Holzner - A Brady Book                                          */
/* Typed by Rick/MerlinTheSpook/TwistedFlickerBoot/SchematicRick                             */
/*********************************************************************************************/
/* UPDATING ALONG THE CHAPTER, GIT SHOULD HAVE THE HISTORY BUT I WILL ALSO COMMENT OUT       */
/* INSTEAD OF DELETING                                                                       */
/******************************************************************************************* */
#include <stdio.h>

main()
{
    FILE *file_pointer;
    int num;

    if((file_pointer = fopen("number.dat", "w")) == NULL) {
        printf("Type some integers: \n");
        while(scanf("%d", &num) == 1) fprintf(file_pointer, "%d\n", num);
        fclose(file_pointer);
    }
    else printf("Error writing file.txt.\n");
}