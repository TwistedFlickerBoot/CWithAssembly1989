/*********************************************************************************************/
/* Code snippet copier.c from pages 62-68                                                    */
/* C With Assembly by Steven Holzner - A Brady Book                                          */
/* Typed by Rick/MerlinTheSpook/TwistedFlickerBoot/SchematicRick                             */
/*********************************************************************************************/
#define BUFFSIZE 32*1024
#include <stdio.h>
#include <fcntl.h>
#include <sys\types.h>
#include <sys\stat.h>
#include <io.h>

main()
{
    char *malloc();  // Pointer to malloc function
    char *buffer;  // Pointer to buffer
    char source[50];
    char target[50];
    int s_handle;
    int t_handle;
    int num; /*dd*/
    
    if((buffer = malloc(BUFFSIZE)) == NULL)  // Allocate buffer
    {
        printf("malloc() could not allocate\n");
        exit(1);
    }
    printf("Source file: ");
    scanf("%s", source);  // Get source file name
    printf("Target file: ");
    scanf("%s", target);  // Get target file name

    if((s_handle = open(source, O_RDONLY | O_BINARY)) == -1)  // Open source file
    {
        printf("Couldn't open source\n");
        exit(1);
    }
    if((t_handle = open(target, O_WRONLY | O_BINARY | O_CREAT | O_TRUNC, S_IWRITE)) == -1)  // Open target file
    {
        printf("Couldn't open target\n");
        exit(1);
    }
    while(num = read(s_handle, buffer, BUFFSIZE))  // Read from source file
        write(t_handle, buffer, num);  // Write to target file
    close(s_handle);  // Close source file
    close(t_handle);  // Close target file
}
