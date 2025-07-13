# array_of_base_pointers_to_derived

As is.

# date.cpp

The class `ExpiryDate` inherits from `Date` and overrides the base virtual function print() to print `Expiray date: dd:mm:yyyy` instead of `Date: dd:mm:yyyy`.

In `main()`, first, an array of base class `Date` pointers is created at stack. It points to derived class `ExpiryDate` objects. The following functions are then called for demonstration: 

`void print(Date* arr, int arrSize)`

`void sortAsc(Date* arr, int arrSize)`

`void sortDsc(Date* arr, int arrSize)`

Then an array of base class `Date` pointers is allocated in **heap**. It also points to derived class `ExpiryDate` objects. The following functions are then called for demonstration:

`void print(Date** arr, int arrSize)`

`void sortAsc(Date** arr, int arrSize)`

`void sortDsc(Date** arr, int arrSize)`

Lastly, the allocated memory is freed.
