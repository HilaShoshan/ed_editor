# include "Document.h"

int Document::get_curr_row() {
    return this->curr_row; 
}

vector<string> Document::get_text() {
    return this->text; 
}

string Document::goto_row(int row) {  // number (1,3)
    if(row > text.size()) {  // there is no such row
        throw "no such row"; 
    }
    curr_row = row; 
    return text[curr_row-1];  
}

string Document::advance_rows(int num) {  // +
    int new_row = curr_row + num; 
    if(new_row > text.size()) {  // there is no such row
        throw "no such row"; 
    }
    curr_row = new_row; 
    return text[curr_row-1];
}

string Document::go_back_rows(int num) {  // -
    int new_row = curr_row - num; 
    if(new_row < 1) {  // there is no such row
        throw "no such row"; 
    }
    curr_row = new_row; 
    return text[curr_row-1];
}

string Document::last_row() {  // $
    curr_row = text.size(); 
    return text[curr_row-1];
}

void Document::add_row_after(string line) {  // a
    if (!line.empty()) {
        auto it = text.begin() + curr_row + 1; 
        text.insert(it, line);
        curr_row ++; 
    }
}

void Document::add_row_before(string line) {  // i 
    if (!line.empty()) {
        auto it = text.begin() + curr_row; 
        text.insert(it, line);
    }
}

bool Document::change_row(string line, bool isFirst) {  // c
    if (!line.empty()) {
        int this_size = text.size(); 
        if (isFirst)  // this is the first row we add -> should replace curr_row
            text[curr_row] = line; 
        else 
            add_row_after(line); 
        return true;  // we enter new line
    }
    else return false;  // fail to enter new line
}

void Document::delete_row() {}

void Document::search_text(string text) {}

void Document::change_text(string old_txt, string new_txt) {}

void Document::concat_rows() {}

void Document::make_file() {}