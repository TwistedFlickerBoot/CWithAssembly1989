/*********************************************************************************************/
/* Code snippet compare.c from pages 187-189                                                 */
/* C With Assembly by Steven Holzner - A Brady Book                                          */
/* Typed by Rick/MerlinTheSpook/TwistedFlickerBoot/SchematicRick                             */
/*********************************************************************************************/
#define BUFFSIZE 128*1024
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>
#include <malloc.h>

char *buffer1;
char *buffer2;
char *end1;
char *end2;
char *match1;
char *match2;
char *difference1;
char *difference2;
int difference_found;

main()
{
    char file1[50];
    char file2[50];
    int f1_handle;
    int f2_handle;
    unsigned num = 0;
    unsigned long num1 = 0;
    unsigned long num2 = 0;

    printf("File 1:");
    scanf("%s", file1);
    printf("File 2:");
    scanf("%s", file2);

    if((buffer1 = halloc(BUFFSIZE, 1)) == NULL)
    {
        printf("Halloc could not allocate.");
        exit(1);
    }
    if((f1_handle = open(file1, O_RDONLY | O_BINARY)) == -1)
    {
        printf("Couldn't open file 1.");
        exit(1);
    }
    while(num = read(f1_handle, buffer1+num1, 64*1024 - 2))
        num1 += num;
    if((buffer2 = halloc(BUFFSIZE, 1)) == NULL)
    {
        printf("Halloc could not allocate.");
        exit(1);
    }
    if((f2_handle = open(file2, O_RDONLY | O_BINARY)) == -1)
    {
        printf("Couldn't open file 2.");
        exit(1);
    }
    while(num = read(f2_handle, buffer2+num2, 64*1024 - 2))
        num2 += num;
    
    end1 = buffer1 + num1;
    *end1 = 0;
    end2 = buffer2 + num2;
    *end2 = 0;
    match1 = buffer1;
    match2 = buffer2;

    while(1){
        find_next_difference();
        if(difference_found){
            find_end_of_difference();
            print_difference();
        }
        else break;
    }
}

find_next_difference()
{
/*Uses match1, match2. Sets difference1, difference2 */
while(*match1++ == *match2++);
if(match1 >= end1 __ match2 >= end2){
    difference_found = 0;
}
else{
    difference_found = 1;
    difference1 = --match1;
    difference2 = --match2;
}
}
find_end_of_difference()
{
/* Uses difference1, difference2, Sets match1, mnatch2 */
char temp_char;
char *temp;
char *d2temp;
int i;

for(i = 0; i < 1000; i++)
{
    temp = (difference1 + 100 > end1 ? end1 : difference1 + 100);
    temp_char = *temp;
    *temp = '\0';
    if((d2temp = strstr(difference2, difference1)) == NULL)
        *temp = temp_char;
        if(difference1 >= end1){
            difference1 = end1;
            difference2 = end2;
            break;
        }
        else{
            *temp = temp_char;
            match1 = difference1;
            match2 = d2temp;
            break;
        }
}
}
print_difference()
{
char *ptr1;
char *ptr2;

    printf("\n\n---------------------\nFile 1:\n");
    for(ptr1=(difference1-20 < buffer1 ? buffer1 : difference1-20);
        ptr1 < (match1+20 > end1 ? end1 : match1+20); ptr1++)
            putchar(*ptr1);
        printf("File 2:\n");
        for(ptr2=(difference2-20 < buffer2 ? buffer2 : difference2-20);
            ptr2 < (match2+20 > end2 ? end2 : match2+20); ptr2++)
                putchar(*ptr2);
}