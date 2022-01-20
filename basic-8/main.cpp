//Inheritance Basic -  products, parts and subparts

#include <iostream>
#include "func.h"

using namespace std;

int main(){

    FullContact David("David Song", 1999, 7, 24, false,"david990724@gmail.com",
                    "29 Galleria Parkway, Thornhill, ON", 'M',"Galaxy Note 10+",
                    "2356326462354234523","647-807-2473");
    David.print();

    FullContact Sample(David);
    Sample.setName("Peter Parker");
    Sample.setBirthday(2000,5,12);
    Sample.setemailAddr("");
    Sample.setAddr("");
    Sample.setModel("iPhone 13");
    Sample.setIMEI("41320123643634");
    Sample.setphoneNumber("413-432-5434");

    Sample.print();
    David.print();

    //I guess it is fine to keep it like this. It contains my personal information - but not private ones.
    //As I have mentioned in func.h, IMEIs are fictional
    //Of course Peter Parker is a fictional character. You don't know who he is though. Do you? Then you are lying.

    return 0;
}

// Object-oriented programming concepts recap:

/*
<Inheritance>
Reference: https://www.geeksforgeeks.org/inheritance-in-c/?ref=lbp 
Creating sub-class (child) inherited from base class (parent)
For example:

class Parent{
    ...
};

class Child: public Parent{
    ...
};

Base Class       |     Type of inheritance             |
Access Specifier |  public   |  protected  |  private  |
_________________|___________|_____________|___________|
   public        |  public   |  protected  |  private  |
   protected     | protected |  protected  |  private  |
   private       |  hidden   |   hidden    |  hidden   |
@ hidden - not accessible. Use accessing functions (i.e. get~~()/set~~())

<Types of inheritance>
1) Single - one parent, one child
2) Multiple - multiple parent, one child
3) Multi-level- one grandparent, one parent, one child
4) Hierarchical - one parent, multiple child, like a tree
5) Hybrid/Virtual - combining more than one type of inheritance (ex - hierarchical and multiple)
6) Multipath - one grandparent, multiple (2+) parent which leads to one child. Ambiguity created
    - Avoiding ambiguity
        - screen resolution operator - still have multiple copies of grandparent
            obj.ClassB::a = 10;
            obj.ClassC::a = 100;
        - use virtual base class - child will have only one copy of grandparent
*/

/*
<Polymorphism>
Reference: https://www.geeksforgeeks.org/polymorphism-in-c/?ref=lbp
1) Compile time polymorphism
    - Function overloading - same name function, different arguments (check InfoList::LocateInList in basic-4)
    - Operator overloading - overload operators (check basic-5, there are few operator overloading)
2) Runtime polymorphism
    - Function overriding - using virtual function, base function is overridded by sub-class function
    class base{
            virtual void func1();
            void func2();
    };
    class derived: public base{
        public:
            void func1();
            void func2();
    };
    If we have base pointer and copy derived class -> func1() execute derived func1, func2() execute base func2
*/

/*
Encapsulation - binding together the data and functions that manipulates them
https://www.geeksforgeeks.org/encapsulation-in-c/?ref=lbp 
Abstraction - the way to hide variables. We hide (some) variables in private, and access (set/get) them using accessors
https://www.geeksforgeeks.org/abstraction-in-c/?ref=lbp 
All set~() or get~() functions. There are plenty of examples in func.cpp in this microproject, and previous ones as well
*/

/*
Constructor - initializes objects of a class. In C++, it is automatically called when object is created
https://www.geeksforgeeks.org/constructors-c/?ref=lbp 
    - Constructor can be created with or without arguments. There could be more than one constructor in class
    - Default constructor is provided when no constructors are explicitly declared
    - Copy constructor - calls method using pass-by reference, and copies the method.
    https://www.geeksforgeeks.org/copy-constructor-in-cpp/?ref=lbp 
        - Deep copy is possible only when copy constructor is user-defined
Destructor - destroys objects of a class
https://www.geeksforgeeks.org/destructors-c/?ref=lbp
    - If construct uses dynamically allocation (using new), destructor should use delete to free memory
    - Called when the program ends/delete operator called/block containing local variable ends/function ends
    - Private destructor is possible, but need to use friend function which calls delete object ptr to use destructor
    https://www.geeksforgeeks.org/private-destructor-in-cpp/?ref=lbp
*/

// How to compile this code
// g++ -std=c++11 -c main.cpp
// g++ -std=c++11 -c func.cpp 
// g++ -std=c++11 main.o func.o -o main.exe   