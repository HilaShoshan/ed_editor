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

    string txt1, txt2, delimiter, token, addition;  // for / and s 
    size_t pos, iteration; 
    vector<string> txts; 

    while (command[0] != 'q') {
        switch (command[0]) {
        case '1':
            cout << document.goto_row(1) << endl; 
            break;
        case '3':
            cout << document.goto_row(3) << endl; 
            break;
        case '+':
            num = (int)command[1] - 48;  // convert to int
            cout << document.advance_rows(num) << endl; 
            break; 
        case '-':
            num = (int)command[1] - 48;  // convert to int
            cout << document.go_back_rows(num) << endl; 
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
            txt1 = command.substr(1, command.size()-2); 
            document.search_text(txt1); 
            cout << command << " " << document.get_curr_row() << endl;
            break; 
        case 's':
            if (command[command.size()-1] != '/') { // there is a " " and the command didnt really end
                cin >> addition; 
                command = command + " " + addition; 
            }
            delimiter = "/"; 
            pos = 0;
            iteration = 0; 
            while ((pos = command.find(delimiter)) != std::string::npos) {
                token = command.substr(0, pos);
                if (iteration == 1) txt1 = token;
                if (iteration == 2) txt2 = token; 
                command.erase(0, pos + delimiter.length());
                iteration++;
            }
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
