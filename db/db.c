/*********************************************************************************************/
/* Code snippet db.c from pages 117-153                                                      */
/* C With Assembly by Steven Holzner - A Brady Book                                          */
/* Typed by Rick/MerlinTheSpook/TwistedFlickerBoot/SchematicRick                             */
/*********************************************************************************************/
#include <stdio.h>

char *field0ptrs[10];
double *field1ptrs[10];
double *field2ptrs[10];
int numrecs = 3;
char buffer[80];
float buffer2;

main()
{
    char string0[] = "Carson";
    double num1 = 712.26;
    double num2 = 23.56;
    char string1[] = "Adams";
    double num3 = 245.23;
    double num4 = 29.17;
    char string2[] = "Banks";
    double num5 = 633.90;
    double num6 = 87.17;
    double end1 = -1.;
    double end2 = -1.;
    int command;

    field0ptrs[0] = string0;
    field0ptrs[1] = string1;
    field0ptrs[2] = string2;
    field1ptrs[0] = &num1;
    field1ptrs[1] = &num3;
    field1ptrs[2] = &num5;
    field1ptrs[3] = &end1;
    field2ptrs[0] = &num2;
    field2ptrs[1] = &num4;
    field2ptrs[2] = &num6;
    field2ptrs[3] = &end2;

        while((printf("Command:"), command = getchar()) != 'q')
        {
            if(command >= '0' && command <= '9')
                display(command - '0');
            switch (command)
                {
                case 'f':
                    display(find(field2ptrs));
                    break;
                case 's':
                    sorter(field1ptrs, 3);
                    break;
                case 'a':
                    adder();
                    break;
                case 'c':
                    changer();
                    break;
                default:
                    break;
                }
        }
}

display(num)
int num;
{
    printf("Name: %s\n", *(field0ptrs + num));
    printf("Owes: %.2f\n", **(field1ptrs + num));
    printf("Monthly payment: %.2f\n", **(field2ptrs + num));
}

int find(ptr2ptrs)
double **ptr2ptrs;
{
    double **loc;
    loc = ptr2ptrs;
    while(**loc < 50 && **loc++ != -1.);
    return (loc - ptr2ptrs);
}

int sorter(ptr2ptrs)
double **ptr2ptrs;
{
    int i, j;
    char *temp1;
    double *temp2;

    for(i = 0; i < numrecs - 1; i++){
        for(j = i + 1; j < numrecs; j++){
            if(**(ptr2ptrs + i) > **(ptr2ptrs + j)){
                temp1 = *(field0ptrs + i);
                *(field0ptrs + i) = *(field0ptrs + j);
                *(field0ptrs + j) = temp1;
                temp2 = *(ptr2ptrs + i);
                *(field1ptrs + i) = *(ptr2ptrs + j);
                *(field1ptrs + j) = temp2;
                temp2 = *(ptr2ptrs + i);
                *(field2ptrs + i) = *(ptr2ptrs + j);
                *(field2ptrs + j) = temp2;
            }
        }
    }
}

adder()
{
    printf("Name: ");
    scanf("%s", buffer);
    *(field0ptrs + numrecs) = (char *) malloc(strlen(buffer));
    strcpy(*(field0ptrs + numrecs), buffer);
    printf("Owes: ");
    scanf("%f", &buffer2);
    **(field1ptrs + numrecs) = (double) buffer2;
    printf("Monthly payment: ");
    scanf("%f", &buffer2);
    **(field2ptrs + numrecs) = (double) buffer2;
    numrecs++;
    *(field1ptrs + numrecs) = (double *) malloc(sizeof(double));
    **(field1ptrs + numrecs) = -1.;
    *(field2ptrs + numrecs) = (double *) malloc(sizeof(double));
    **(field2ptrs + numrecs) = -1.;
}

changer()
{
    int thisrec;
    printf("Change what record:");
    scanf("%d", &thisrec);
    printf("New name:");
    scanf("%s", buffer);
    *(field0ptrs + thisrec) = (char *) malloc(strlen(buffer));
    strcpy(*(field0ptrs + thisrec), buffer);
    printf("Owes:");
    scanf("%f", &buffer2);
    **(field1ptrs + thisrec) = (double) buffer2;
    printf("Monthly payment:");
    scanf("%f", &buffer2);
    **(field2ptrs + thisrec) = (double) buffer2;
}