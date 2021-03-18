# include "Editor.h"

void Editor::loop() {

    string command; 
    cin >> command; 

    string line; 

    int num;  // for + and - 

    bool isFirst = true;  // for change_row method
    bool isEntered;     // too 

    int curr_index;  // for delete row

    string output_filename;  // for w file method

    while (command[0] != 'q') {
        switch (command[0]) {
        case '1':
            cout << document.goto_row(1) << endl; 
            break;
        case '3':
            cout << document.goto_row(3) << endl; 
            break;
        case '+':
            num = int(command[1]); 
            cout << document.advance_rows(num) << endl; 
            break; 
        case '-':
            num = int(command[1]); 
            cout << document.go_back_rows(1) << endl; 
            break;
        case '$':
            cout << document.last_row() << endl; 
            break; 
        case 'a':
            cout << "current row: " << document.get_curr_row() << endl; 
            cout << "Please enter text to add after current row: " << endl; 
            getline(cin, line);
            while (line != ".") {
                document.add_row_after(line);
                cout << "text size: " << document.get_text().size() << endl; 
                getline(cin, line);  // ask for another line
            }            
            break;
        case 'i':
            cout << "Please enter text to add before current row: " << endl; 
            getline(cin, line);
            while (line != ".") {
                document.add_row_before(line);
                cout << "text size: " << document.get_text().size() << endl; 
                getline(cin, line);  // ask for another line
            }            
            cout << "################" << document.get_curr_row() << endl; 
            document.set_surr_row(document.get_curr_row()-1); 
            cout << "################" << document.get_curr_row() << endl;
            break; 
        case 'c':
            cout << "Replace current row with (one or more lines): " << endl; 
            getline(cin, line);
            while (line != ".") {
                isEntered = document.change_row(line, isFirst);
                if (isEntered && isFirst) 
                    isFirst = false;  // from now isFirst will always be false!
                cout << "text size: " << document.get_text().size() << endl; 
                getline(cin, line);  // ask for another line
            }            
            break; 
        case 'd':
            curr_index = document.get_curr_row() - 1;
            cout << "text size: " << document.get_text().size() << endl; 
            document.delete_row(curr_index);
            cout << "after deleting: " << document.get_text().size() << endl;  
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
            cin >> output_filename; 
            cout << output_filename << endl; 
            document.make_file(output_filename); 
            break; 
        default:
            if(command[0] != 'q') cout << "?" << endl;
            break;
        }
        cin >> command; 
    }
}
