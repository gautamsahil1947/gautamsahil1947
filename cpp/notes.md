c++ is statically typed, that is the types of the variables is defined at compiletime
preprocessor is a big find and replace tool
each c++ statement must end in `;`
`g++ -E file.cpp` shows the results of preprocessing
`g++ -c file.cpp` gives out the object file
`g++ -o name objfile1 objfile2` combines the two object files into one executable file
object files are binary files that are not executable
there can be functions with same name but different input types
but there cannot be functions that have same names and same inputs but different return types

```cpp
#include <iostream> // preproccessor directive
// used to include library
// this lib is used for input and output stream. let's us use std::cout to print to the console

int main(int argc, char *argv[]) {
        // the main function has an int return type
        // argc is the number of inputs (command line inputs)
        // char *argv[] is an array of char pointers, that point to the first characters of the command-line arguments
        // in java, it is like main(String[] args), because in java, arrays are objects, and an array object, knows its own length.
        // here in cpp, arrays are just series  of characters, and therefore we need to provide additional parameter length
        std::cout << "hello, world!\n"
        // std is called namespace and in that namespace, there is a lot of functionality.
        // cout is a variable in the std namespace, and is a stream, and << is called operator, and is called pipes.
        // :: is somehow related to scope and the scope of cout is within the std namespace
        // << is basically piping the string into the variable
        return 0;
        // main has a return type of int
        // system calls main, and therefore system wants to know that everything went smoothly.
        // you can return error codes other than 0, that tell if any error happened
}

```

```cpp
#include <iostream>

// this one might not be correct, but is written for the sake of letting
// sahil know that something like this also exists
namespace sahil {
        int i = 10;
}

int main(int argc, char *argv[]) {
        // creating a namespace

        std::cout << "hello, world!\n"
        return 0;
}
```

header files have the declarations

```cpp
int sum(int x, int y);
// atlease all the declarations should be known to cpp before using
```

```cpp
class Point {
        // anything that doesn't have a scope is private by default
        int m_x = 0;
        int m_y = 0;
public:
        Point(int x, int y);
        int getX();
        int getY();
};
```

```cpp
class Classname {

} (semicolon);
```

```cpp
#include <iostream>


int main(int argc, char *argv[]) {
        std::cout << "Hello, world!" << std::endl;
        return 0;
}
```

```cpp
#include <iostream>


int main(int argc, char *argv[]) {
        int a = 10;
        int b = 30;
        std::string first = "Sahil";
        std::string last = "Gautam";
        std::string name = first + " " + last;
        std::cout << first << " " << last << std::endl;
}
```

`using namespace std;` means that we are telling the compiler that we are going to be assuming that we are going
to be using stuff from std, and if you don't recoganise something, then assume that is comes from std

```cpp
#include <iostream>
#include <vector>


int main(int argc, char *argv[]) {
        std::vector<int> vec;
        vec.push_back(42);
        vec.push_back(10);

        // std::cout << vec << std::endl;;
        std::cout << vec[0] << std::endl;
        std::cout << vec[1] << std::endl;
        // in cpp you are on your own if going beyond the vector length
        std::cout << vec[2] << std::endl;
        std::cout << vec[3] << std::endl;
        std::cout << vec[4] << std::endl;
}
```

```cpp
#include <iostream>
#include <vector>


int main(int argc, char *argv[]) {
        std::vector<int> vec;
        vec.push_back(42);
        vec.push_back(10);
        // whenever you are iterating through an integer, use an unsigned type
        for (size_t i = 0; i < vec.size(); i++) {
                std::cout << vec[i] << "\n";
        }
        return 0;
}
```

```cpp
#include <iostream>
#include <vector>


int main() {
        std::vector<float> vec;
        vec.push_back(42.4f);
        vec.push_back(10.5f);

        for (int a : vec) {
                std::cout << a << "\n";
                // here i am taking the floats from the vector and printing it
        }
}
```

```cpp
for (auto a : vec) {
        std::cout << a << "\n";
        // auto means, take the type of the thing inside the vector
        // for whatever happens to be in the vector, take the same type
        // and then copy the value in the variable a and use it as defined inside the loop
}
```

but you would not want to do that when it comes to larger datatypes, other than ints, floats or bytes, it is better to use
`&` that is reference type instead of copies

```cpp
#include <iostream>
#include <vector>

class Student {
        // we can give values along with decelarations which old cpp couldn't do
        // m_smth is sayimg that m_smth is private
        std::string m_first = "First";
        std::string m_last = "Last";
        int m_id = 0;
        float m_avg = 0;
public:
        Student() {
                // this is called a constructor, that too a default one
                // it is for what will happen if i don't input anything when i construct the object
        }

        Student (std::string first, std::string last, int id, float avg)
                // this is called initialiser list
                // it creates the thing with the default values from the (paranthesis)
                :m_first(first), m_last(last), m_id(id), m_avg(avg)      {
        }

        int getAvg() const {
                return m_avg;
        }

        int getID() const {
                return m_id;
        }

        std::string getFirst() const {
                return m_first;
        }

        std::string getLast() const {
                return m_last;
        }

        void print() const {
                // const function means that it cannot change anything inside an object
                // ??? but what if it calls some other function that changes it. ???
                // the thing said above should not be allowed
                std::cout << m_first << " " << m_last << " ";
                std::cout << m_id << " " << m_avg << std::endl;
        }
};

void doMachimeLearning(const Data& d) {
        // here i am passing a reference to my hude dataset to this function,
        // and therefore i wouldn't want it to change it
        // hence i am making it const.
        //
        // and for not copying everything, a reference to the orignal thing.
        d.getValue();
        // if getValue() is not marked as const, we wouldn't be able to use it
}

int main() {
        Student s1;
        Student s2("sahil", "gautam", 1, 23);
        const Student s3("bharat", "gawar", 22222, 99.999999);

        s3.print();
        std::cout << s3.getLast() << "\n";

        return 0;
}

/*
 * if calling a function that on a const object of a class, shows error
 * this is because, that function/ or method can change the student object
 *
 * so i have a student that is const, but i am calling a student on it
 *
 * so every function inside the class, where we are not changing the object
 * should be marked const
 *
 *
 * also notide that the lsp inside neovim willnot show the methods or functions on a const object, which are not const
 * and also it marks the objects that are const as const*/
```

- what is the difference between pass by pointer and pass by reference in cpp
- is reference same as a copy of the name variable's data, that is it instead of passing pointer, which later has to be dereferenced
- it passes a normal variable's copy (of reference). . . NEED NOT MAKE SENSE RIGHT NOW

```cpp
#include <iostream>
#include <vector>
#include <fstream>

class Student {
        // we can give values along with decelarations which old cpp couldn't do
        // m_smth is sayimg that m_smth is private
        std::string m_first = "First";
        std::string m_last = "Last";
        int m_id = 0;
        float m_avg = 0;
public:
        Student() {
                // this is called a constructor, that too a default one
                // it is for what will happen if i don't input anything when i construct the object
        }

        Student (std::string first, std::string last, int id, float avg)
                // this is called initialiser list
                // it creates the thing with the default values from the (paranthesis)
                :m_first(first), m_last(last), m_id(id), m_avg(avg)      {
        }

        int getAvg() const {
                return m_avg;
        }

        int getID() const {
                return m_id;
        }

        std::string getFirst() const {
                return m_first;
        }

        std::string getLast() const {
                return m_last;
        }

        void print() const {
                // const function means that it cannot change anything inside an object
                // ??? but what if it calls some other function that changes it. ???
                // the thing said above should not be allowed
                std::cout << m_first << " " << m_last << " ";
                std::cout << m_id << " " << m_avg << std::endl;
        }
};

class Course {
        std::string m_name = "Course";
        std::vector<Student> m_students;
public:
        Course() {} // default constructor
        // std::string name will be copying the string name into the constructor
        // therefore we are passing reference to that string
        // and since we don't want it to change the orignal string, we are making the reference const
        Course(const std::string& name)
                :m_name(name) {
                // strings are big things
        }

        void addStudent(const Student& s) {
                m_students.push_back(s);
        }

        const std::vector<Student>& getStudents() const {
                // the first const means that the reference we are returning should not be changed
                // teh second one says, taht since this function doesn't change anything, it is const
                return m_students;
        }

        void loadFromFile(const std::string& filename) {
                // this function is not const, because we are going to load from a file into the object
                // that is changing the object, and therefore cannot be a const stuff
                // in order to load from a file, we need a file input stream | std because the input file stream class is within the namespace standard
                std::ifstream fin(filename);
                std::string tmp;

                while (fin >> tmp) {
                        std::cout << tmp << "\n";
                }



        }

        void print () const {
                for (const auto& s : m_students) {
                        // making it const here ensures that we don't change anything inside the
                        // loop that is a safety check to keep us from screwing up
                        s.print();
                }
        }
};


int main() {
        Course c("Comp 4300");
        c.loadFromFile("/home/sahil/gautamsahil1947/cpp/studentdata.txt");
        return 0;
}
```

```cpp
#include <iostream>
#include <vector>
#include <fstream>

class Student {
        // we can give values along with decelarations which old cpp couldn't do
        // m_smth is sayimg that m_smth is private
        std::string m_first = "First";
        std::string m_last = "Last";
        int m_id = 0;
        float m_avg = 0;
public:
        Student() {
                // this is called a constructor, that too a default one
                // it is for what will happen if i don't input anything when i construct the object
        }

        Student (std::string first, std::string last, int id, float avg)
                // this is called initialiser list
                // it creates the thing with the default values from the (paranthesis)
                :m_first(first), m_last(last), m_id(id), m_avg(avg)      {
        }

        int getAvg() const {
                return m_avg;
        }

        int getID() const {
                return m_id;
        }

        std::string getFirst() const {
                return m_first;
        }

        std::string getLast() const {
                return m_last;
        }

        void print() const {
                // const function means that it cannot change anything inside an object
                // ??? but what if it calls some other function that changes it. ???
                // the thing said above should not be allowed
                std::cout << m_first << " " << m_last << " ";
                std::cout << m_id << " " << m_avg << std::endl;
        }
};

class Course {
        std::string m_name = "Course";
        std::vector<Student> m_students;
public:
        Course() {} // default constructor
        // std::string name will be copying the string name into the constructor
        // therefore we are passing reference to that string
        // and since we don't want it to change the orignal string, we are making the reference const
        Course(const std::string& name)
                :m_name(name) {
                // strings are big things
        }

        void addStudent(const Student& s) {
                m_students.push_back(s);
        }

        const std::vector<Student>& getStudents() const {
                // the first const means that the reference we are returning should not be changed
                // teh second one says, taht since this function doesn't change anything, it is const
                return m_students;
        }

        void loadFromFile(const std::string& filename) {
                // this function is not const, because we are going to load from a file into the object
                // that is changing the object, and therefore cannot be a const stuff
                // in order to load from a file, we need a file input stream | std because the input file stream class is within the namespace standard
                std::ifstream fin(filename);
                std::string first, last;
                int id;
                float avg;

                while (fin >> first) {
                        // fin >> last;
                        // fin >> id;
                        // fin >> avg;
                        // while i have the valid first line character, read in the last name
                        // readin the id and convert it to int, and float for the last one
                        // or you can do it better

                        fin >> last >> id >> avg;
                        addStudent(Student(first, last, id, avg));
                }



        }

        void print () const {
                for (const auto& s : m_students) {
                        // making it const here ensures that we don't change anything inside the
                        // loop that is a safety check to keep us from screwing up
                        s.print();
                }
        }
};


int main() {
        Course c("Comp 4300");
        c.loadFromFile("/home/sahil/gautamsahil1947/cpp/studentdata.txt");
        c.print();
        return 0;
}
```

---

if new keyword is being used to create the object, then the allocation will be in heap memory
else it will be created in the stack memory

the amount of memory available on the stack is very less. therefore if used over the limits, causes stackoverflow
local variables without new are also stored on stack memory
program function calls and return addresses are also stored on the stack
stack is known as static memory because

- allocation happens at compiletime
- dynamic memory allocation happens on the heap memory dynamically

the moment we reach the end of the block, all the block things allocated in the stack are deallocated in the reverse order

###### imp

when the stack allocated primitives run out of scope, they are removed
whereas when a class object / class runs out of scope, the destructor of that class is called
for the most part, stack memory things are contiguously allocated

```cpp
int *sahil = new int;
// creating thing dynamically
// under the hood, malloc is being called by new to allocate the memory
// all that a pointer is (is an address) a memory address
// the memory addresses that the pointers hold are 64 bit unsigned integers
//


// the heap grows down. also the pointer itself is storing some address, and therefore takes some space
// it is allocated on heap. Pointer allocation happens at compiletime statically
// things get poped of from the stack
// also if the pointer is destroyed, the values that it stored on the heap memory remains there. there is no automatic garbage collection
delete sahil;
// this is manual feature to free that heap allocated memory
```

// under the hood new uses malloc and delete uses free
// therefore it is prefered to use as less heap memory as possible, because IT IS SLOW

```cpp
/*
stack allocation is like what is my current stack pointer
        put the thing at the next location*/

whereas

/*
when it comes to heap, malloc searches for the contiguous memory in heap, takes time
        then it writes to that location, and then saves the pointer to the given var

        not to forget the values that the previous programs left (the garbage values)*/

the speed of referencing the memory is the same.( that is reading the data)
STACK IS FAST BUT LIMITED
Heap is huge but slow
```

a pointer is a memory address with an associated type
if you modify the pointer, you modify the address
to modify the thing that it points to (that is the space in memory), you need to dereference it, that is go to the thing
raw pointers can be very unsafe (but what is a raw pointer)
raw poitners are normal poitners, which live indefinitely
whereas the other side, that is the smart pointers know when to destruct themselves
& means address of

if you create a pointer, it is created on the stack
if you don't give it some default value rightaway, it points to the garbage value at that stack location
therefore always initialise the pointers to some defalut value

`*` is called dereference
& is called address of

```cpp
int *arr = new int[3]; // dynamically allocated array
int arr[3]; // statically allocated array
// here both the arr are just pointers to arrays of integers but one in heap, other in stack, both with garbage values
same dereferencing stuff works like in c, just mallock has been replaced with java like syntax
```

in cpp, _(arr + n) and _(n + arr) are same, and therefore arr[n] and n[arr] are same
(arr + n) == &(arr[n])

// the size of the dynamically allocated array can be dynamically allocated, that is we need not have the size at compiletime
// whereas when it comes to the stack allocated array, that is `int arr[5];`, the size has to be mentoned at compiletime
in cpp, if you want to use inheritence, that is base class pointing to the derived class, you have to use pointers
passbyvalue/ passby reference
//pointers to large data

```cpp
// in cpp there are poitners and references
```

references are essentially safe pointers;
instead of using `*`, we use `&`

- a reference must point to existing data. It can never be nothing or nullptr, then it makes them almost always safe
- therefore it is prefered using references to pointers wherever possible.

---

### pass by value or pass by reference

in cpp, all values are by default pass by value, and pass by value has a cost for copying
whole thing is modified
what if you want to modify the thing that you are passing, then you cannot use pass by value
0000000000 or if you use that, then there will be a huge cost of copying data and then changing it, and returning it to the orignal thing, not to say internal memory errors too happen.

```cpp
#include <iostream>

void tennify(int a) {
        // a is local to this function
        // this function copies the value passed into the locally scoped variable a
        a = 10;
}

int main() {
        int i = 12;
        tennify(i);
        std::cout << i << std::endl;
        // does not change i
        // only the local copy is changed, because it is pass by value by default
}
```

but what we want is to change the value in the orignal `i` variable
we want to pass by reference from the nature of the function

- there are two ways to do this
  - pass by pointer
  - pass by

```cpp
// pass by pointer
#include <iostream>

void tennify(int *a) {
        // lookup the memory this address points to, and change this address
        *a = 10;
}

int main() {
        int i = 12;
        // here cpp is still pass by value, and therefore, we pass a copy of address of i
        // passing a copy of address of i
        tennify(&i);
        std::cout << i << std::endl;
}
// if that pointer is null, and if you are trying to dereference a null pointer, your program is going to crash
// if at that address, your os doesn't allow access, your program is going to crash
// and if the upper 2 cases don't happen, then the the compiler will assume that this is an integer and cast whatever is there to an integer
```

```cpp
#include <iostream>

void tennify(int& a) {
        // this is looking up the address and changes what lives at a to 10
        // reference will almost always be valid
        a = 10;
}

int main() {
        int i = 12;
        tennify(i);
        std::cout << i << std::endl;
}
// reference is still an address, but it is a safe address
// because we cannot call this tennify function on any address, it can be called only on a variable that exists in the memory
```

```cpp
#include <iostream>


int main() {
        int i = 10;
        int& reference = i;
        std::cout << "int i is " << i << std::endl;
        std::cout << "int & reference is " << reference << std::endl;

        i = 20;

        std::cout << "int i is " << i << std::endl;
        std::cout << "int & reference is " << reference << std::endl;

        reference = 50;

        std::cout << "int i is " << i << std::endl;
        std::cout << "int & reference is " << reference << std::endl;
}
```

```cpp
#include <iostream>

void machineLearn(BigData d);
// here suppose we want to pass some data to a function to learn from
// but the function above will pass a copy of the data, which will take a lot of resources
// and is also time consuming

int main() {
        BigData data(args);
        machineLearn(data);
}
```

```cpp
#include <iostream>

// this is a const reference
// const tells that the data cannot be changed inside the function
void machineLearning(const BigData& d);
// here we are passing a reference to that object
// and since we now from the tenify example that the orignal object can be modified using reference
// we need to make this reference const

int main() {
        BigData data(args);
        machineLearn(data);
}
// pass primitives by value
// because we only use referencing if data is larger than an integer
// references under the hood are infact similar to pointers
// `std::shared_ptr<T>` are smart pointers, should be passed by value
```

Resource Acquision is Initialisation (RAII)

```cpp
#include <iostream>

class IntArray {
        int * array;
public:
        // constructor acquires the resources
        IntArray(size_t size) {
                array = new int[size];
        }

        // destructor frees the resources
        ~IntArray() {
                delete [] array;
        }

        // operator overloading for accessing array members
        int & operator [] (size_t i) {
                return array[i];
        }
};

int main() {
}
```

```cpp

#include <iostream>
#include "IntArray.h" // putting this class in a header file

class IntArray {
        int * array;
public:
        IntArray(size_t size) {
                array = new int[size];
        }

        ~IntArray() {
                delete [] array;
        }

        int& operator [] (size_t i) {
                return array[i];
        }
};

int main() {
        IntArray arr(10); // memory allocated using the constructor
        arr[5] = 23;
}
// array destructed, memory deallocated
// every variable that was stack allocated in that scope will be deallocated
// therefore, if the class is written properly, we neednot worry about that thing
//
// in order to have an array and use RAII and manage my memory, we need a class to wrap around that
```

it would be very troublesome if we have to create classes for every raii managed datatype

- `smartpointers`

```cpp
std::shared_ptr<T> // just does want the code above did
        // it is a reference counted pointer
        // it keeps a track of how many things reference them (Reference Counted Pointer)
        // but it is also templated, that is it uses generics
        it has an internal coutner to how many things reference to it,
        if the counter becomes 0, it destructs itself. also if shared, counter increases by 1 each time

```

```cpp
auto p = std::make_shared<MyClass>(args);
```

- inheritences are of different types, that is public private and protected
- in those the thing that different is what the inheriting class gets
- sometines, it gets private members, sometimes protected, sometines public and protected

```cpp
// 43 min

```

```cpp
#include <iostream>


int main() {
        int a = 10;
        int b = 25;

        std::cout << &a << " " << a << " " << sizeof(a) << " " << std::endl;
        std::cout << &b << " " << b << " " << sizeof(b) << " " << std::endl;
        // the addresses of these numbers differ in 4, that is sizeof(int)
        return 0;
}
```

```cpp
#include <iostream>

void pp(int& a) {
        // try taking in only a and not int& a
        // shouldn't we pass primitives by value
        std::cout << &a << " " << a << " " << sizeof(a) << " " << std::endl;
}

int main() {
        int a = 10;
        int b = 25;

        pp(a);
        pp(b);
        // the addresses of these numbers differ in 4, that is sizeof(int)
        return 0;
}
```

```cpp

#include <iostream>
#include <SFML/Graphics.hpp>



int main(void)
{
        const int wWidth = 900;
        const int wHeight = 900;
        sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML works");
        sf::CircleShape circle(50);
        circle.setFillColor(sf::Color::Red);


        while (window.isOpen())
        {

        }
}
```

```cpp
indow/Keyboard.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    sf::Window window(sf::VideoMode::getDesktopMode(), "My window", sf::Style::Default);
    window.setVerticalSyncEnabled(true);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
             switch (event.type)
             {
                case sf::Event::Closed:
                    window.close();
            //     // case sf::Event::KeyPressed:
            //     //     std::cout << "Hello, world, key KeyPressed" << std::endl;
            //     // case sf::Event::Resized:
            //     //     std::cout << "new width: " << event.size.width << std::endl;
            //     //     std::cout << "new height: " << event.size.height << std::endl;
            //     case sf::Event::LostFocus:
            //         std::cout << "Lost focus" << std::endl;
            //     case sf::Event::GainedFocus:
            //         std::cout << "Gained Focus" << std::endl;
            //     // default:
            //     //     std::cout << "default of switch" << std::endl;
            //
            //
             }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::A)
                {
                    std::cout << event.key.code << std::endl;
                }

                if (event.key.code == sf::Keyboard::B)
                {
                    std::cout << "Pressed B";
                }

                if (event.key.code == sf::Keyboard::Enter)
                {
                    std::cout << "Pressed Enter";
                }
            }
        }
    }
}

// g++ cpp.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
```

```cpp

#include <iostream>
#include <SFML/Graphics.hpp>


int main ()
{
    sf::RenderWindow window(sf::VideoMode(900, 900), "My Window");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clears contents from the previous frames
        window.clear(sf::Color::Black);

        // then here you draw somethings or the others
        // these are drawn to a hidden buffer, as SFML implements double buffering

        // this one displays the hidden buffer contents to the main window
        window.display();

        // so it is like
        // clear ---> draw to hidden buffer ---> display ---> clear --> draw --> display  (not sure about it, need to experiment)
    }
}
```

```cpp
// draws hello world to the newly created window
#include <iostream>
#include <SFML/Graphics.hpp>


int main ()
{
    sf::RenderWindow window(sf::VideoMode(900, 900), "My Window");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // set a varaible of the font class
        sf::Font font;
        // load the font from a file, and if incase not loaded, do something
        if (!font.loadFromFile("AgaveNerdFont-Regular.ttf"))
        {
            std::cout << "Not able to load font" << std::endl;
        }

        // create an instance of text class
        sf::Text text;
        // set the font for that instance
        text.setFont(font);
        // give in string
        text.setString("Hello, world");
        // set character size
        text.setCharacterSize(55);
        // set fill color
        text.setFillColor(sf::Color::Red);

        // clear the window
        window.clear(sf::Color::Black);
        // draw the text
        window.draw(text);
        // display the text
        window.display();
    }
}
```

```cpp
#include <iostream>
#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 900), "My Window");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                std::cout << "Closing the window" << std::endl;
                window.close();
            }

            window.clear(sf::Color::Black);
            sf::CircleShape circle(200.f);
            window.draw(circle);
            window.display();
        }
    }
}
```

```cpp
// creates a circle and makes it move
#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "The Game Window");
    // if the circle is created inside the loop, then it will never move.
    sf::CircleShape circle(15.f);

    while (window.isOpen())
    {




        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                std::cout << "Closing The Window" << std::endl;
                window.close();
            }
        }

        float xVelocity = 0.1f;
        float yVelocity = 0.2f;


        circle.setPosition(circle.getPosition().x + xVelocity, circle.getPosition().y + yVelocity);

        window.clear();
        window.draw(circle);
        window.display();


    }
}
```

```cpp

#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "The Game Window");
    size_t rad = 13;
    // if this is inside the while loop, each time new object is created, and therefore no changes are visible
    sf::CircleShape circle(rad);

    // if these were inside the while loop, then the loop would set them to the default
    // values with each run, and therefore you don't get the desired results
    float xVelocity = 0.4f;
    float yVelocity = 0.2f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                std::cout << "Closing The Window" << std::endl;
                window.close();
            }
        }


        circle.setPosition(circle.getPosition().x + xVelocity, circle.getPosition().y + yVelocity);


        if (circle.getPosition().x + (2 * rad) >= 1000 || circle.getPosition().x <= 0)
        {
            circle.setFillColor(sf::Color::Yellow);
            xVelocity *= -1;
        }

        if (circle.getPosition().y + (2 * rad) >= 800 || circle.getPosition().y <= 0)
        {
            circle.setFillColor(sf::Color::Red);
            yVelocity *= -1;
        }


        window.clear();
        window.draw(circle);
        window.display();


    }
}
```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```
