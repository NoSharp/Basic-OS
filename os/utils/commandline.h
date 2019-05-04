#ifndef CMDLINE_H
#include "types.h"

int cursor = 0;
const uint8 sw = 80, sh = 25, sd = 2;

void printChar(char b){
    char *memory = (char*)0xb8000;
    memory[cursor] = b;
    memory[cursor + 1] = 0x07;
    cursor++;
    cursor++;
} 

void updateCursor(){
    char *memory = (char*)0xb8000;
    memory[cursor] = "_";
    
}

uint16 stringLength(string str) {
	uint16 i = 1;
	while (str[i++]);
	return --i;
}

void print(string words){
    int i = 0;
    int length = stringLength(words);
    for(i; i < length; i++){
        printChar(words[i]);
    }

}

void clearLine(uint16 from, uint16 to) {
    uint16 i = sw * from * sd;
    string mem = (string) 0xb8000;
    for(i; i < (sw * (to + 1) * sd); i++) {
        mem[i] = 0x0;
    }
}
void clearScreen(){
    clearLine(0, sh-1);

}

void update(){
    char *memory = (char*)0xb8000;
    memory[cursor] = 0x07;
}

#endif