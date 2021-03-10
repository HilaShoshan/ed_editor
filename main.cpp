# include <iostream> 
# include "Editor.h"

int main(int argc, char* argv[]) {
    Editor editor; // if there is no text file, it will leave like that
    if(argc == 2)  // a text file is given 
        editor = Editor(argv[1]);
    editor.loop();
    return 0; 
}