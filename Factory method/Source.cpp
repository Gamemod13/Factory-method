#include <iostream>
#include <string>

class Document {
public:
	virtual void show() = 0;
};
class TextDocument : public Document {
public:
	void show() {
		std::cout << "This is text Document" << std::endl;
	}
};
class PictureDocument : public Document {
public:
	void show() {
		std::cout << "This is picture" << std::endl;
	}
};
class Creator {
public:
	virtual Document* create() = 0;
};
class TextDocumentCreator : public Creator {
public:
	Document* create() {
		return new TextDocument();
	}
};
class PictureDocumentCreator : public Creator {
public:
	Document* create() {
		return new PictureDocument();
	}
};
int main() {
	Creator *creator = new TextDocumentCreator();
	Document* myDocument = creator->create();

	creator = new PictureDocumentCreator();
	Document* myDocument2 = creator->create();
	myDocument->show();
	myDocument2->show();
}