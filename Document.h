# pragma once

# include <vector>
# include <regex> 
# include <iterator> 
# include <iostream>
using namespace std;

class Document {

private:
    vector<string> text; 
    int curr_row = 1;

public:
    Document() {}
    Document(string doc) {
        regex pattern(R"(\n)");
        copy(sregex_token_iterator(doc.begin(), doc.end(), pattern, -1),
        sregex_token_iterator(),back_inserter(text));  // put the rows of the file in vector
    }
    ~Document();

    int get_curr_row(); 

    string goto_row(int row);  // go to a spesific row in the text 
    string advance_rows(int num);  // advence in the given number of rows
    string go_back_rows(int num);  // go back in the given number of rows
    string last_row();  // go to the last row of the text
    void add_rows_after();  // add one or more rows after the current row
    void add_rows_before();  // add one or more rows before the current row
    void change_row();  // change the current row by one or more rows
    /* the above three methods stop when a '.' recieved from the user */
    void delete_row();  // delete the current row 
    void search_text(string text);  // search the given text in the following rows, and set
                                      // these row as curr_row
    void change_text(string old_txt, string new_txt);  // change the first instance of old_txt with
                                                        // new_txt (in the current row)
    void concat_rows();  // concat the current row with the following row
    void make_file();  // write the document into a file
};

