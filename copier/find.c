/*********************************************************************************************/
/* Code snippet find.c from pages 69-74                                                      */
/* C With Assembly by Steven Holzner - A Brady Book                                          */
/* Typed by Rick/MerlinTheSpook/TwistedFlickerBoot/SchematicRick                             */
/*********************************************************************************************/
#define BUFFSIZE 32*1024
#include <stdio.h>
#include <fcntl.h>
#include <sys\types.h>
#include <sys\stat.h>
#include <io.h>
#include <string.h> /*add*/

main(argc, argv)
int argc;
char *argv[];
{
    char *malloc();
    char *buffer;
    char source[50];
    char tofind[50];
    int s_handle;
    int num, i;
    char *match, *start;

    strcpy(tofind, argv[1]);
    strcpy(source, argv[2]);

    if((buffer = malloc(BUFFSIZE)) == NULL) {
        printf("malloc() could not allocate\n");
        exit(1);
    }
    if((s_handle = open(source, O_RDONLY | O_BINARY)) == -1) {
        printf("Could not open source\n");
        exit(1);
    }
    while(num = read(s_handle, buffer, BUFFSIZE)) 
    {
        buffer[num] = 0;
        for(match = buffer; match = strstr(match, tofind); ++match) {
            start = ((match - 20)< buffer ? buffer : match - 20);
            for(i = 0; i < 40; i++, start++)
                putch(*start);
                printf("\n");
        }
    }
    close(s_handle);
}