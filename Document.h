// # pragma once

# include <vector>
# include <iterator> 
# include <iostream>
# include <fstream>
using namespace std;

class Document {

private:
    vector<string> text; 
    int curr_row = 1;

public:
    Document(){}
    Document(string file_name) {
        ifstream file(file_name);
        string doc; 
        while (getline(file, doc)) {
            text.push_back(doc); 
        }
    }
    ~Document(){}

    int get_curr_row(); 

    vector<string> get_text(); 

    string goto_row(int row);  // go to a spesific row in the text 
    string advance_rows(int num);  // advence in the given number of rows
    string go_back_rows(int num);  // go back in the given number of rows
    string last_row();  // go to the last row of the text
    void add_row_after(string line);  // add one row after the current row
    void add_row_before(string line);  // add one row before the current row
    void change_row(string line);  // change the current row by another row
    void delete_row();  // delete the current row 
    void search_text(string text);  // search the given text in the following rows, and set
                                      // these row as curr_row
    void change_text(string old_txt, string new_txt);  // change the first instance of old_txt with
                                                        // new_txt (in the current row)
    void concat_rows();  // concat the current row with the following row
    void make_file();  // write the document into a file
};

