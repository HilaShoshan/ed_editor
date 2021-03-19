# include "Document.h"

int Document::get_curr_row() {
    return this->curr_row; 
}

void Document::set_surr_row(int new_curr) {
    this->curr_row = new_curr; 
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
        auto it = text.begin() + curr_row; 
        text.insert(it, line);
        curr_row ++; 
    }
}

void Document::add_row_before(string line) {  // i 
    if (!line.empty()) {
        auto it = text.begin() + curr_row - 1; 
        text.insert(it, line);
        curr_row++;  // the line is the same, only its index has changed
    }
}

bool Document::change_row(string line, bool isFirst) {  // c
    int index = curr_row - 1;  // the index of curr_row
    if (!line.empty()) {
        int this_size = text.size(); 
        if (isFirst)  // this is the first row we add -> should replace curr_row
            text[index] = line; 
        else 
            add_row_after(line); 
        return true;  // we enter new line
    }
    else return false;  // fail to enter new line
}

void Document::delete_row(int index) {  // d
    auto it = text.begin() + index; 
    text.erase(it); 
}

void Document::search_text(string txt) {  // /text/
    int i = curr_row;  // *index* to begin with (curr_row index + 1)
    size_t found; 
    while (i != curr_row-1) {
        if (i >= text.size()) 
            i = 0;
        found = text[i].find(txt); 
        if (found != string::npos) {  // found txt in the ith line
            curr_row = i; 
            return; 
        }
        i++; 
    }
}

void Document::change_text(string old_txt, string new_txt) {  // ‫‪s/old/new/‬‬
    try {
        text.at(curr_row).replace(text.at(curr_row).find(old_txt), old_txt.size(), new_txt);
    } catch(std::out_of_range) {
        cout << "?" << endl; 
    }
}

void Document::concat_rows() {  // j
    if (curr_row > text.size()) {
        throw runtime_error("Concatenation failed: there is no netxt row"); 
    }
    text[curr_row-1] = text[curr_row-1] + text[curr_row]; 
    delete_row(curr_row); 
}

void Document::make_file(string output_filename) {  // w file
    ofstream output_file(output_filename);
    for (const auto &e : text) output_file << e << "\n";
}