# include <iostream> 
# include "Editor.h"

int main(int argc, char* argv[]) {
    switch (argc) {
    case 1:
        Editor editor; 
        break;
    case 2: 
        Editor editor = Editor(argv[1]); // with params
    default:
        throw "illegal input"; 
        break;
    }

    editor.loop();
    return 0; 
}