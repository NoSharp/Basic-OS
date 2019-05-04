#include "./utils/commandline.h"
#include "./utils/keyboard.h"


kernelStart(){
    clearScreen();
    print("HELLO WORLD");
    getInput();
    
}

curs(){
    while(1==1){
        updateCursor();
    }
}