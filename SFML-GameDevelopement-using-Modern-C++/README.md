#### Projects

- [Project1](./project1/README.md)

#### Basics of C++

```cpp
// hello world program
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Hello World" << std::endl;
    return 0;
}
```

```cpp
// demonstrating namespace
#include <iostream>

namespace sahil
{
    int i = 10;
}

int main() {
    std::cout << sahil::i << std::endl;
    return 0;
}
```

```cpp
#include <iostream>


class Point
{
    int m_x = 0;
    int m_y = 0;
public:
    Point(int x, int y) : m_x(x), m_y(y) {}

    int getX() {
        return m_x;
    }

    int getY() {
        return m_y;
    }
};

int main() {
    Point sahil(9, 9);
    std::cout << sahil.getX() << " " << sahil.getY() << std::endl;
    return 0;
}
```

```cpp
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
}
```

```cpp
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    for (auto& a : vec)
    {
        std::cout << a << std::endl;
    }

}
```

```cpp
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    for (auto a : vec)
    {
        std::cout << a << std::endl;
    }

}
```

- both of the above 2 are valid, but the last one copies the value in variable a, whereas
- the first one copies the reference to that variable, hence saving some computation
- `auto` means what

```cpp
#include <iostream>
#include <vector>

class Student {
    std::string m_first = "First";
    std::string m_last = "Last";
    int m_id = 0;
    int m_avg = 0;
public:
    Student() {}
    Student(std::string first, std::string last, int id, float avg) : m_first(first), m_last(last), m_id(id), m_avg(avg) {}

    int getAvg() const {
        return m_avg;
    }

    int getId() const {
        return m_id;
    }

    std::string getFirst() const {
        m_first = "gggg"; // shows error
        return m_first;
    }

    std::string getLast() const {
        return m_last;
    }

    void print() const {
        std::cout << m_first << " " << m_last << " ";
        std::cout << m_id << " " << m_avg << std::endl;
    }
};

int main() {
    // Student s1();
    // turns out that this doesn't call the empty constructor, instead
    // Student s1;  is how you declare an instance of that class which uses the empty constructor
    Student s1;
    Student s2("Sahil", "Gautam", 1, 33.33);
    const Student s3("Bharat", "Gawar", 2, 99.88);
    // for const class instances, only those methods will be called, which are const, that is they don't change the object/instance
    s3.print();
    s2.print();
    s1.print();


}
```

```cpp
#include <fstream>
#include <iostream>
#include <vector>

class Student {
    std::string m_first = "First";
    std::string m_last = "Last";
    int m_id = 0;
    int m_avg = 0;
public:
    Student() {}
    Student(std::string first, std::string last, int id, float avg) : m_first(first), m_last(last), m_id(id), m_avg(avg) {}

    int getAvg() const {
        return m_avg;
    }

    int getId() const {
        return m_id;
    }

    std::string getFirst() const {
        return m_first;
    }

    std::string getLast() const {
        return m_last;
    }

    void print() const {
        std::cout << m_first << " " << m_last << " ";
        std::cout << m_id << " " << m_avg << std::endl;
    }
};

class Course {
    std::string m_name = "Course";
    std::vector<Student> m_students;
public:
    Course() {}
    Course(const std::string& name) : m_name(name) {}
    // only taking reference to the strings because they are large objects

    void addStudent(const Student& stud) {
        m_students.push_back(stud);
    }

    const std::vector<Student>& getStudent() const {
        return m_students;
        // return a const reference to the vector of Student instances
        // and since it is just returning reference, this function should be const
    }

    void print() const {
        for (const auto& student : m_students) {
            // here auto takes Student type
            // const in loop means that inside the loop, the reference is unchanged
            student.print();
        }
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream fin(filename);
        std::string tmp;

        while (fin >> tmp) {
            std::cout << tmp << std::endl;
        }

    }

};

int main() {
    Student s1;
    Student s2("Sahil", "Gautam", 1, 33.33);
    const Student s3("Bharat", "Gawar", 2, 99.88);

    Course c1("computer");
    c1.addStudent(s1);
    c1.addStudent(s2);
    c1.addStudent(s3);
    // c1.addStudent(); creating a student insdie the constructor
    c1.print();
    c1.loadFromFile("/home/sahil/gautamsahil1947/SFML-GameDevelopement-using-Modern-C++/project1//data.txt");
}
```

---

#### Memory Allocation and Manipulation

```cpp
#include <iostream>


int main() {
    int *sahil = new int;
    // space allocated on heap for an integer
    // pointer allocation happens at compiletime
    delete sahil;
    // space deallocated from heap, that was aquired before
    //
}
```

```cpp
#include <iostream>


int main() {
    int* arr = new int[2];
    arr[2] = 10;
}
```

```cpp
#include <iostream>

void tennify(int a) {
    a = 10;
}

int main() {
    int i = 2;
    std::cout << i << " ";
    tennify(i);
    std::cout << i << " " << std::endl;
}
```

```cpp
#include <iostream>

void tennify(int& a) {
    a = 10;
}

int main() {
    int i = 2;
    std::cout << i << " ";
    tennify(i);
    std::cout << i << " " << std::endl;
}
```

```cpp

#include <iostream>

class IntArray {
    int* array;
public:
    IntArray(size_t size) {
        // array = new int[size];
        array = new int[size] {};
        // this initialises all the values in the heap to 0
    }

    ~IntArray() {
        delete [] array;
    }

    int& operator [] (size_t i) {
        return array[i];
    }
};


int main() {
    IntArray arr(10);
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << std::endl;
        // printing the barbage values
    }
}
```

- left `smartpointers`, `inheritence`, `sharedpointers`

##### Entity component system game programming

// operator overloading in cpp
// shared pointers in cpp

```cpp
#include <iostream>

class Vec2 {
public:
    float x = 0;
    float y  = 0;

    Vec2() {}

    Vec2(float xin, float yin)
    : x(xin), y(yin) {

    }

    Vec2 operator + (const Vec2& rhs) const {
        return Vec2(Vec2(x + rhs.x, y + rhs.y));
    }

    void add (const Vec2& v) {
        x += v.x;
        y += v.y;
    }

    void operator += (const Vec2& v) {
        x += v.x;
        y += v.y;
    }
};

int main() {

    Vec2 v1(199, 199);
    Vec2 v2(11, 10);

    Vec2 v3 = v1 + v2;
    std::cout << v3.x << " " << v3.y << std::endl;
}
```

in ecs or entity component systems, each of the things work independently, and interhelpingly
this way, it makes it easy to have a variety of things on the screen, doing a variety of things, which might not
be related to each other. this way it becomes a modular design.

one entity can atmost have one attachment of one component.

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
