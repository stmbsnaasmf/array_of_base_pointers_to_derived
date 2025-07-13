#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
public:
	int day, month, year;
	
	Date(int day, int month, int year) : day(day), month(month), year(year) {}
	
	Date(){}
	
	void setDate(int day, int month, int year)
	{
		this->day = day; this->month = month; this->year = year;
	}
	
	virtual void print()
	{
		cout << "Date: " << setw(2) << setfill('0') << day << ":" << setw(2) << setfill('0') << month << ":" << year << "\n";
	}
};

class ExpiryDate : public Date
{
public: 
	ExpiryDate(int day, int month, int year) : Date(day, month, year) {}
	ExpiryDate(){}
	
	void print()
	{
		cout << "Expiry date: " << setw(2) << setfill('0') << day << ":" << setw(2) << setfill('0') << month << ":" << year << "\n";
	}
};

/* The following functions are for an array of base class pointers allocated on heap. */
int dateToInt(Date* d);
void print(Date** arr, int arrSize);
void sortAsc(Date** arr, int arrSize);
void sortDsc(Date** arr, int arrSize);

/* The following functions are for an array of base class pointers on stack. */
int dateToInt(Date d);
void print(Date* arr, int arrSize);
void sortAsc(Date* arr, int arrSize);
void sortDsc(Date* arr, int arrSize);

int main(void)
{
	/* The second line does not work. 
	The array qrr is an array of Date objects in heap memory.
	It is not an array of Date pointers. 
	See https://stackoverflow.com/questions/13048301/pointer-to-array-of-base-class-populate-with-derived-class */
	Date* qrr = new Date[5];
//	qrr[0] = new ExpiryDate(02, 05, 2021);
	
	
	/* "dates" is an array of Date pointers on stack, and not heap.
	This works for demonstration, but is not ideal because the array of pointers should be on heap, not stack.
	This also matters because print(Date* arr, int arrSize) works only for a pointer array on stack. 
	For a pointer array on heap, we need print(Date** arr, int arrSize). Note the double stars(**). */
	Date* dates[5];
	dates[0] = new ExpiryDate(02, 05, 2021);
	dates[1] = new ExpiryDate(03, 05, 2021);
	dates[2] = new ExpiryDate(04, 05, 2021);
	dates[3] = new ExpiryDate(05, 05, 2021);
	dates[4] = new ExpiryDate(06, 05, 2021);
	print(dates, 5);
	cout << "\n";
	sortAsc(dates, 5);
	print(dates, 5);
	cout << "\n";
	sortDsc(dates, 5);
	print(dates, 5);
	cout << "\n\n\n";
	
	/* The code below does work and is correct.
	It declares an array of Date pointers on heap. */	
	Date** array = new Date*[5];
	for (int i = 0; i < 5; i++)
	{
		array[i] = new ExpiryDate();
	}

	array[0]->setDate(02, 05, 2021);
	array[1]->setDate(20, 12, 2019);
	array[2]->setDate(20, 12, 2019);
	array[3]->setDate(03, 05, 2022);
	array[4]->setDate(03, 05, 2020);

	print(array, 5);
	cout << "\n";
	sortAsc(array, 5);
	print(array, 5);
	cout << "\n";
	sortDsc(array, 5);
	print(array, 5);
	
	for (int i = 0; i < 5; i ++)
	{
		delete array[i];
	}
	delete[] array;
	
	return 0;
}

int dateToInt(Date* d)
{
	string str = to_string(d->year);
	str += (d->month < 10) ? "0" + to_string(d->month) : to_string(d->month);
	str += (d->day < 10) ? "0" + to_string(d->day) : to_string(d->day);
	
	return stoi(str);
}

void print(Date** arr, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		arr[i]->print();
	}
}

void sortAsc(Date** arr, int arrSize)
{
	for (int i = 0; i < arrSize - 1; i++)
	{
		for (int j = 0; j < arrSize - 1; j++)
		{
			if (dateToInt(arr[j]) > dateToInt(arr[j + 1]))
			{
				Date temp = *arr[j];
				*arr[j] = *arr [j + 1];
				*arr[j + 1] = temp;
			}
		}
	}
}

void sortDsc(Date** arr, int arrSize)
{
	for (int i = 0; i < arrSize - 1; i++)
	{
		for (int j = 0; j < arrSize - 1; j++)
		{
			if (dateToInt(arr[j]) < dateToInt(arr[j + 1]))
			{
				Date temp = *arr[j];
				*arr[j] = *arr [j + 1];
				*arr[j + 1] = temp;
			}
		}
	}
}



int dateToInt(Date d)
{
	string str = to_string(d.year);
	str += (d.month < 10) ? "0" + to_string(d.month) : to_string(d.month);
	str += (d.day < 10) ? "0" + to_string(d.day) : to_string(d.day);
	
	return stoi(str);
}

void print(Date* arr, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		arr[i].print();
	}
}

void sortAsc(Date* arr, int arrSize)
{
	for (int i = 0; i < arrSize - 1; i++)
	{
		for (int j = 0; j < arrSize - 1; j++)
		{
			if (dateToInt(arr[j]) > dateToInt(arr[j + 1]))
			{
				Date temp = arr[j];
				arr[j] = arr [j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void sortDsc(Date* arr, int arrSize)
{
	for (int i = 0; i < arrSize - 1; i++)
	{
		for (int j = 0; j < arrSize - 1; j++)
		{
			if (dateToInt(arr[j]) < dateToInt(arr[j + 1]))
			{
				Date temp = arr[j];
				arr[j] = arr [j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
