/*********************************************************************************************/
/* Code snippet  from pages 59                                                               */
/* C With Assembly by Steven Holzner - A Brady Book                                          */
/* Typed by Rick/MerlinTheSpook/TwistedFlickerBoot/SchematicRick                             */
/*********************************************************************************************/
/* UPDATING ALONG THE CHAPTER, GIT SHOULD HAVE THE HISTORY BUT I WILL ALSO COMMENT OUT       */
/* INSTEAD OF DELETING                                                                       */
/* I MAY BE TIRED FROM LOOKING AT CODE BUT I THINK THIS CHANGE WAS MEANT FOR THE PREVIOUS    */
/* EXAMPLE IN THE BOOK DEALING WITH NUMBERS.DAT CALLED NUMBERS.C. PG-59 IN BOOK              */
/* INSTEAD OF UPDATING READER.C I DECIDED TO JUST WRITE THE EXAMPLE IN A NEW FILE FOR FSEEK  */
/* ERRNO EXAMPLE                                                  PAGE 61                    */
/******************************************************************************************* */
#include <stdio.h>
#include <io.h>
#define INDEX 15

extern int errno; // Error number
struct entry
{
    char name[20];
    float owes;
}

main()
{
    FILE *file_pointer;
    struct entry buffer;
    int rec_num;
    if((file_pointer = fopen("numbers.dat", "r")) == NULL)
    {
        printf("Type the record number to recover:");
        scanf("%d", &rec_num);
        fseek(file_pointer, (long)(rec_num * sizeof(struct entry)), 0);
            fread(&buffer, sizeof(struct entry), 1, file_pointer);
    }
    else 
    {
        printf("Error number: %d returned\n", errno);
        printf("Error reading numbers.dat\n");
    }
    printf("%s owes %.2f\n", buffer.name, buffer.owes);
    fclose(file_pointer);
}