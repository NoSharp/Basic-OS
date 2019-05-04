#ifndef KEYBOARD_H
#include "types.h"
#include "ports.h"
#include "commandline.h"

uint16 stringLength(string str) {
	uint16 i = 1;
	while (str[i++]);
	return --i;
}

string getInput(){
    string bufferString;
    char buffer;
    uint32 i = 0;
    bool isReading;



    while(isReading &&  stringLength(bufferString) < 32 ) {
        if (inPortB(0x64) & 0x1) {
            uint8 inpt = inPortB(0x60);
            if(inpt <= 9){
                printChar(inpt);
                bufferString[i] = inpt;

                continue;
            }
            

        }
    }
}



#endif