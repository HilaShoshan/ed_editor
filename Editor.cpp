# include "Editor.h"

void Editor::loop() {

    string command; 
    cin >> command; 

    switch (command[0]) {
    case '3':
        cout << document.goto_row(3) << endl; 
        break;
    case '+':
        cout << document.advance_rows(2) << endl; 
        break; 
    case '-':
        cout << document.go_back_rows(1) << endl; 
        break;
    case '$':
        cout << document.last_row() << endl; 
        break; 
    case 'a':
        document.add_rows_after(); 
        break;
    case 'i':
        document.add_rows_before(); 
        break; 
    case 'c':
        document.change_row(); 
        break;
    case 'd':
        document.delete_row(); 
        break; 
    case '/':
        document.search_text("text"); 
        break; 
    case 's':
        document.change_text("old", "new"); 
        break;
    case 'j':
        document.concat_rows(); 
        break;
    case 'w': 
        document.make_file(); 
        break; 
    default:
        if(command != "q") {cout << "?" << endl;}
        else exit; 
        break;
    }
}
