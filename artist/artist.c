/*********************************************************************************************/
/* Code snippet artist.c from pages 79-107                                                   */
/* C With Assembly by Steven Holzner - A Brady Book                                          */
/* Typed by Rick/MerlinTheSpook/TwistedFlickerBoot/SchematicRick                             */
/*********************************************************************************************/
#include <stdio.h>
#include <graph.h>

main()
{
    int in, index = 1;
    int xloc = 0, yloc = 0, x1 = 0, y1 = 0;
    FILE *fpointer;
    void *gpointer;
    char fillarray[] = {0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,};

    _asetvideomode(_MRES4COLOR);

    _setcolor(1);

    _setfillmask(fillarray);

    while((in = getch()) != 'q')
    {
        if(!in) in = getch() + 128;
        switch(in)
        {
            case 208: /* up arrow */
                yloc++;
                break;
            case 203: /* left arrow */
                xloc--;
                break;
            case 205: /* right arrow */
                xloc++;
                break;
            case 200: /* down arrow */
                yloc--;
                break;
            case 'p': /* per pixel*/
                _setpixel(xloc, yloc)
                _moveeto(xloc, yloc);
                x1 = xloc;
                y1 = yloc;
                break;
            case 'l': /* line */
                _lineto(xloc, yloc);
                break;
            case 'r': /* rectangle */
                _rectangle(_GBORDER, x1, y1, xloc, yloc);
                break;
            case 'e': /* ellipse */
                _ellipse(_GBORDER, x1, y1, xloc, yloc);
                break;
            case 'x': /*fill*/
                _floodfill(xloc, yloc, 1);
                break;
            case ' ': /*change color*/
                (index >= 3 ? index = 1 : index++);
                _setcolor(index);
                break;
            case 'd': /* delete */
                _setcolor(0);
                break;
            case 's': /* save */
                fpointer = fopen("screen.dmp", "wb");
                gpointer = 0xb8000000;
                fwrite(gpointer, 16*1024, 1, fpointer);
                fclose(fpointer);
                break;
            case 'f': /* restore from file */
                fpointer = fopen("screen.dmp", "rb");
                gpointer = 0xb8000000;
                fread(gpointer, 16*1024, 1, fpointer);
                fclose(fpointer);
                break;
            default:
                ;
        }
    }
}