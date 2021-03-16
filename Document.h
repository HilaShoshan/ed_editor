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
    string file_name = "";

public:
    Document(){}
    Document(string file_name) {
        this->file_name = file_name; 
        ifstream file(file_name);
        if (file.is_open()) {
            string doc; 
            while (getline(file, doc)) {
                text.push_back(doc); 
            }
        } else {
            throw runtime_error("File didn't open");
        }
        file.close();
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
    bool change_row(string line, bool isFirst);  // change the current row by another row
    void delete_row(int index);  // delete the current row 
    void search_text(string text);  // search the given text in the following rows, and set
                                      // these row as curr_row
    void change_text(string old_txt, string new_txt);  // change the first instance of old_txt with
                                                        // new_txt (in the current row)
    void concat_rows();  // concat the current row with the following row
    void make_file(string output_filename);  // write the document into a file
};

