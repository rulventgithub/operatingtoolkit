#ifndef PAUSEKB_H
#define PAUSEKB_H
#include "screen.h"
#include "sys.h"
 int isEnterPress()
{
    char buff;
    string buffstr;
    uint8 i = 0;
    uint8 reading = 1;
    while(reading)
    {
        if(inportb(0x64) & 0x1)                 
        {
            switch(inportb(0x60))
            { 
 
         
        case 28:
 
                  i++;
               reading = 0;
               return 1;
                break;
        default:
            return 0;
        break;
        
    }
   
}
    }
}

 #endif