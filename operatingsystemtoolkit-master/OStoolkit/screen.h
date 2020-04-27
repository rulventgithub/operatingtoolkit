#ifndef SCREEN_H
#define SCREEN_H
#include "string.h"
#include "define.h"
int cursorX = 0, cursorY = 0;
const unsigned char sw = 80,sh = 25,sd = 2;      
 
#include "sys.h"

void newLine(){
    print("\n");

}
void bios_print(char* text ){


char*mem = (char* )0xb8000;
while(*text){
*mem++ = *text++;
*mem++ = 0x03;

}

}


void scrnClear(){
    char *mem = (char*)0xb8000;
    int i=0;
    do{
     mem[i++] = 0;

        
    }while (i < 4000);
   
    


}

                                               
void clearLine(uint8 from,uint8 to)
{
        uint16 i = sw * from * sd;
        string vidmem=(string)0xb8000;
        for(i;i<(sw*to*sd);i++)
        {
                vidmem[i] = 0x0;
        }
}
void updateCursor()
{
    unsigned temp;

    temp = cursorY * sw + cursorX;                                                      

    outportb(0x3D4, 14);                                                              
    outportb(0x3D5, temp >> 8);                                                       
    outportb(0x3D4, 15);                                                    
    outportb(0x3D5, temp);                                                         
}
void clearScreen()
{
        clearLine(0,sh-1);
        cursorX = 0;
        cursorY = 0;
        updateCursor();
}

void scrollUp(uint8 lineNumber)
{
        string vidmem = (string)0xb8000;
        uint16 i = 0;
        clearLine(0,lineNumber-1);                                          
        for (i;i<sw*(sh-1)*2;i++)
        {
                vidmem[i] = vidmem[i+sw*2*lineNumber];
        }
        clearLine(sh-1-lineNumber,sh-1);
        if((cursorY - lineNumber) < 0 ) 
        {
                cursorY = 0;
                cursorX = 0;
        } 
        else 
        {
                cursorY -= lineNumber;
        }
        updateCursor();
}


void newLineCheck()
{
        if(cursorY >=sh-1)
        {
                scrollUp(1);
        }
}

void printch(char c)
{
    string vidmem = (string) 0xb8000;     
    switch(c)
    {
        case (0x08):
                if(cursorX > 0) 
                {
	                cursorX--;									
                        vidmem[(cursorY * sw + cursorX)*sd]=0x00;	                              
	        }
	        break;
        case ('\r'):
                cursorX = 0;
                break;
        case ('\n'):
                cursorX = 0;
                cursorY++;
                break;
        default:
                vidmem [((cursorY * sw + cursorX))*sd] = c;
                vidmem [((cursorY * sw + cursorX))*sd+1] = 0x02;
                cursorX++; 
                break;
	
    }
    if(cursorX >= sw)                                                                   
    {
        cursorX = 0;                                                                
        cursorY++;                                                                    
    }
    updateCursor();
    newLineCheck();
}

void print (string ch)
{
        uint16 i = 0;
        uint8 length = strlength(ch)-1;            
        for(i;i<length;i++)
        {
                printch(ch[i]);
        }
}


// update color released, new c o l o r features!
int color = 0x0F;

void setScreenColor(int text_color,int bg_color)
{
	color =  (bg_color << 4) | text_color;;
}
void setScreenColorCode(int color_code)
{
	color = color_code;
}
void cprint(string ch,int text_color,int bg_color)
{
	int current_color = color;
	setScreenColor(text_color,bg_color);
	print(ch);
	setScreenColorCode(current_color);
}
 #endif

