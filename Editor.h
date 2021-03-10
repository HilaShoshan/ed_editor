// # pragma once

# include "Document.h"

class Editor {

private:
    Document document; 

public:
    Editor(){
        document = Document();
    }
    Editor(string file) {
        document = Document(file);
    }
    ~Editor() {}
    void loop(); 
};
