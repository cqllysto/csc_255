// Andrew Chapuis and Aidan Wright
// CSC 255
// Program 3 CPP File
// 09/11/2023

using namespace std;

//******************************************************************************
// Aidan Wright
// cStringList constructor

cStringList::cStringList(int listCapacity) {
    this->listCapacity = listCapacity;
    listCount = 0;
    first = 0;
    last = 0;
    a = new string[listCapacity];
}

//******************************************************************************
// Aidan Wright
// cStringList destructor
cStringList::~cStringList() {
    if(a) {
	delete [] a;
    }
}

//******************************************************************************
// Aidan Wright

bool cStringList::insert(string text) {
    bool rc = false;
    if
}
