# include "Editor.h"

void Editor::loop() {

    string command; 
    cin >> command; 

    while (command[0] != 'q') {
        switch (command[0]) {
        case '1':
            cout << document.goto_row(1) << endl; 
            break;
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
            exit(EXIT_FAILURE);
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
            if(command[0] != 'q') cout << "?" << endl;
            break;
        }
        cin >> command; 
    }
}
