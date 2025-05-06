/*********************************************************************************************/
/* Update Code snippet copier.c from pages 62-68 on page 169-170                             */
/* C With Assembly by Steven Holzner - A Brady Book                                          */
/* Typed by Rick/MerlinTheSpook/TwistedFlickerBoot/SchematicRick                             */
/*********************************************************************************************/
#define BUFFSIZE 64*1024-2
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>
#include <malloc.h>

main()
{
    char *buffer;
    char source[50];
    char target[50];
    int s_handle;
    int t_handle;
    unsigned int num;

    if((buffer = halloc((long)BUFFSIZE, 1)) == NULL)
    {
        printf("halloc could not allocate.\n");
        exit(1);
    }
    printf("Source file: ");
    scanf("%s", source);
    printf("Target file: ");
    scanf("%s", target);
    if((s_handle = open(source, O_RDONLY | O_BINARY)) == -1)
    {
        printf("Could not open source.\n");
        exit(1);
    }
    if((t_handle = open(target, O_WRONLY | O_BINARY | O_CREAT, S_IWRITE)) == -1)
    {
        printf("Could not open target.\n");
        exit(1);
    }
    while(num = read(s_handle, buffer, BUFFSIZE))
        write(t_handle, buffer, num);
    close(s_handle);
    close(t_handle);
}