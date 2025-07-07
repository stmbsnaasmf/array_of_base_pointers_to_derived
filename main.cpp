#include <iostream>
using namespace std;

class Parent
{
	string name;
	
public:
	
	Parent(string name)
	{
		this->name = name;
	}
	
	virtual void print()
	{
		cout << name << "\n";
	}
};

class Child : public Parent
{
	int* Arr;
	int arrSize = 0;
	
public: 
	
	Child(string name, int arrSize) : Parent(name)
	//Child(int arrSize) 
	{
		Arr = new int[arrSize];
		this->arrSize = arrSize;
		
		for (int i = 0; i < arrSize; i++)
		{
			Arr[i] = i;
		}
	}
	
	void print()
	{
		for (int i = 0; i < arrSize; i++)
		{
			cout << Arr[i] << "\t";
		}
		cout << "\n";
	}
};

int main()
{
	int noOfPointers = 10;
	
	string str = "random";
	
	Parent p(str);
	p.print();
	
	Child c(str, 10);
	c.print();
	


	Parent** ArrayOfPointers = new Parent*[noOfPointers];
	
	for (int i = 0; i < noOfPointers; i++)
	{
		ArrayOfPointers[i] = new Child(str, i);
		ArrayOfPointers[i]->print();
	}
	
	//Do not forget to free memeory.
	
	for (int i = 0; i < noOfPointers; i++)
	{
		delete ArrayOfPointers[i];
	}
	delete[] ArrayOfPointers;
	
	return 0;
}

