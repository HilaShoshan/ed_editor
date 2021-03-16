// # pragma once

# include "Document.h"

class Editor {

private:
    Document document; 

public:
    Editor() {}
    Editor(string file_name) {
        document = Document(file_name);
    }
    ~Editor() {}
    void loop(); 
};
