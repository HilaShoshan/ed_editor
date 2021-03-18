# include "Editor.h"
# include <regex>
# include <algorithm>

void Editor::loop() {

    string command; 
    cin >> command; 

    string line; 

    int num;  // for + and - 

    bool isFirst = true;  // for change_row method
    bool isEntered;     // too 

    int curr_index;  // for delete row

    string output_filename;  // for w file method

    string txt1, txt2;  // for / and s 
    stringstream stream; 
    std::string segment;
    std::vector<std::string> seglist;

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
            document.set_surr_row(document.get_curr_row()-1); 
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
            stream = stringstream(command); 
            while(getline(stream, segment, '/')) {
                seglist.push_back(segment);
            }
            txt1 = seglist[0]; 
            document.search_text(txt1); 
            break; 
        case 's':
            stream = stringstream(command); 
            while(getline(stream, segment, '/')) {
                seglist.push_back(segment);
            }
            txt1 = seglist[1]; 
            txt2 = seglist[2]; 
            document.change_text(txt1, txt2); 
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
