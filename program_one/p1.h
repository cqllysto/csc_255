#ifndef __P1H
#define __P1H

#include <string>

class stringList {
    private:
	std::string *a; //A pointer to the array into which the list values will be stored
	int listCapacity; //Memorialize the capacity of the list
	int listSize; //An integer to track the number of entries on the list

    public:
	stringList(int listCapacity = 100);
	~stringList();
	
	bool insert(std::string text);
	bool add(std::string text);
	bool insertAt(int index, std::string text);
	bool deleteAt(int index, std::string &text);
	void clear();
	void printIt() const;
	int getIndex(std::string text) const;
	bool readAt(int index, std::string &text) const;
	int count() const
}

#endif

