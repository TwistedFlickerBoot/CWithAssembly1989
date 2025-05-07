/*********************************************************************************************/
/* Code snippet printer.c from pages 229-231                                                 */
/* C With Assembly by Steven Holzner - A Brady Book                                          */
/* Typed by Rick/MerlinTheSpook/TwistedFlickerBoot/SchematicRick                             */
/*********************************************************************************************/
/* Printer.c formats and prints files. Codes:                                                */
/*                                                                                           */
/* @d --> double spacing                                                                     */
/* @s --> single spacing                                                                     */
/* @u --> underlining on                                                                     */
/* @v --> underlinging off                                                                   */
/* @b --> bold on                                                                            */
/* @c --> bold off                                                                           */
/*                                                                                           */
/* @# --> indent # spaces                                                                    */
/*********************************************************************************************/
#include <stdio.h>
#include <malloc.h>

main(argc, argv)
int argc;
char *argv[];
{
FILE *inptr = NULL;
FILE *outptr = NULL;
char *buffer, *endptr, thischar;
int numbytes, spacing = 1, padding = 0, i = 0;

switch(argc){
    case 1:
        printf("Usage: printer file.ext [file.out]");
        exit(1);
    case 2:
        if((inptr = fopen(*(argv + 1), "r")) == NULL){
            printf("Could not open input file");
            exit(1);
        }
        else
            outptr = stdprn;
        break;
    case 3:
        if((outptr = fopen(*(argv + 2), "w")) == NULL){
            printf("Could not open output file");
            exit(1);
        }
        else break;
    default:
        break;
}

buffer = malloc(20000);
numbytes = fread(buffer, sizeof(char), 20000, inptr);
endptr = buffer + numbytes;
*(buffer + numbytes) = '\0';
while(buffer < endptr){
    if(*buffer != '@' && *buffer != '\n')
        putc(*buffer++, outptr);
    else if(*buffer == '@')
    {
        buffer++;
        switch(thischar = *buffer)
        {
                case 'd':
                    spacing = 2;
                    break;
                case 's':
                    spacing = 1;
                    break;
                case 'u':
                    putc(27, outptr);
                    putc('-', outptr);
                    putc('1', outptr);
                    break;
                case 'v':
                    putc(27, outptr);
                    putc('-', outptr);
                    putc('0', outptr);
                    break;
                case 'b':
                    putc(27, outptr);
                    putc('G', outptr);
                    break;
                case 'c':
                    putc(27, outptr);
                    putc('H', outptr);
                    break;
                default:
                    if(thischar <= 'q' && thischar >= '0')
                        padding = thischar - '0';
                        break;
        }
        buffer++;
    }
    else
    {
        buffer++;
        putc('\n', outptr);
        if(spacing == 2)
        {
            putc('\r', outptr);
            putc('\n', outptr);
        }
        for(i = 0; i < padding; i++)
            putc(' ', outptr);
    }
}