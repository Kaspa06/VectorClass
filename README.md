# Specs

    CPU: AMD Ryzen 5 5600U with Radeon Graphics 2.30 GHz
    RAM: 16.0 GB (15.3 GB usable)
    SSD: WDC PC SN530 512Gb
    GPU: Integrated with CPU
    OS: Windows 10 Pro 64-bit

# Introduction

#### This project provides an implementation of a dynamic array container in C++ named `vector`, similar to `std::vector` from the C++ Standard Library. This custom `vector` class template provides various functionalities to handle dynamic arrays with an emphasis on performance, memory management, and ease of use. The class supports common operations such as insertion, deletion, resizing, and element access while handling memory allocation and deallocation internally.

## Features

### Constructors

1. Default Constructor

   `vector():` Initializes an empty vector.

2. Fill Constructor

`explicit vector(size_type n, const T& t = T{}):` Initializes a vector with n elements, each initialized to t.

3. Copy Constructor

`vector(const vector& v):` Initializes a vector as a copy of another vector v.

4. Range Constructor

`template <class InputIterator> vector(InputIterator first, InputIterator last):` Initializes a vector with elements from the range `[first, last)`.

5. Move Constructor

`vector(vector&& v):` Initializes a vector by moving resources from another vector `v`.

6. Initializer List Constructor

`vector(const std::initializer_list<T> il):` Initializes a vector with elements from an initializer list il.

### Destructor

`~vector():` Destroys the vector and deallocates its memory.

### Assignment Operators

1. Copy Assignment

`vector& operator=(const vector& other):` Assigns the contents of `other` to the vector.

2. Move Assignment

`vector& operator=(vector&& other) noexcept:` Moves the contents of other to the vector.

### Iterators

1. `iterator begin()`
2. `const_iterator begin() const`
3. `iterator end()`
4. `const_iterator end() const`

### Capacity

1. `size_type size() const:` Returns the number of elements in the vector.

2. `size_type max_size() const:` Returns the maximum possible number of elements.

3. `void resize(size_type sz):` Resizes the vector to contain sz elements.

4.`void resize(size_type sz, const value_type& value):` Resizes the vector to contain `sz` elements, each initialized to value.

5. `size_type capacity() const:` Returns the number of elements that can be held in currently allocated storage.

6. `bool empty() const noexcept:` Checks if the vector is empty.

7. `void reserve(size_type n):` Reserves storage for at least `n` elements.

8. `void shrink_to_fit():` Reduces capacity to fit the size.

### Element Access

- `T& operator[](size_type n):` Accesses the element at position n.

- `const T& operator[](size_type n) const`
- `reference at(size_type n):` Accesses the element at position n with bounds checking.

- `const_reference at(size_type n) const`
- `reference front():` Accesses the first element.

- `const_reference front() const`
- `reference back():` Accesses the last element.

- `const_reference back() const`
- `value_type* data() noexcept:` Returns a pointer to the underlying array.
- `const value_type* data() const noexcept`

### Modifiers

- `template <class InputIterator> void assign(InputIterator first, InputIterator last):` Assigns values from the range [first, last).
- `void assign(size_type n, const value_type& val):` Assigns n copies of val to the vector.
- `void assign(std::initializer_list<value_type> il):` Assigns values from the initializer list il.
- `void push_back(const value_type& t):` Adds an element to the end.
- `void push_back(value_type&& val):` Adds an element to the end (move).
- `void pop_back():` Removes the last element.
- `iterator insert(iterator pos, const T& value):` Inserts an element at the specified position.
- `iterator erase(iterator position):` Erases the element at the specified position.
- `iterator erase(iterator first, iterator last):` Erases elements in the range [first, last).
- `void swap(vector& x):` Swaps the contents of this vector with x.
- `void clear() noexcept:` Clears the contents of the vector.

### Relational Operators

- `bool operator==(const vector<T>& other) const:` Checks if two vectors are equal.
- `bool operator!=(const vector<T>& other) const`
- `bool operator<(const vector<T>& other) const`
- `bool operator<=(const vector<T>& other) const`
- `bool operator>(const vector<T>& other) const`
- `bool operator>=(const vector<T>& other) const`

### Private Member Functions

- `void create():` Initializes an empty vector.
- `void create(size_type n, const T& val):` Allocates and initializes storage for n elements.
- `void create(const_iterator i, const_iterator j):` Allocates and initializes storage from the range [i, j).
- `void uncreate():` Destroys elements and deallocates storage.
- `void grow(size_type new_capacity = 1):` Grows the vector to accommodate more elements.
- `void unchecked_append(const T& val):` Appends an element without checking capacity.

### Testing `std::vector` and `vector` speed and reallocations

| Size     | std::vector Time | Custom vector Time | std::vector Reallocations | vector Reallocations |
| -------- | ---------------- | ------------------ | ------------------------- | -------------------- |
| 10000    | 0 s              | 0 s                | 14                        | 14                   |
| 100000   | 0.001994 s       | 0.001995 s         | 17                        | 17                   |
| 1000000  | 0.020944 s       | 0.016955 s         | 20                        | 20                   |
| 10000000 | 0.206448 s       | 0.183509 s         | 24                        | 24                   |
| 10000000 | 2.0415s          | 1.77326s           | 27                        | 27                   |

### Testing `std::vector` and `vector` file generating

| Size    | std::vector Time | Custom vector Time |
| ------- | ---------------- | ------------------ |
| 1000    | 0.013903s        | 0.010972s          |
| 10000   | 0.100278s        | 0.105718s          |
| 100000  | 0.964256s        | 1.06715s           |
| 1000000 | 9.63277s         | 10.2358s           |
| 1000000 | 117.533s         | 106.347s           |

### Testing `std::vector` and `vector` file read/sort/divide time

| `std::vector`                | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
| ---------------------------- | ------------- | -------------- | --------------- | ---------------- | ----------------- |
| Skaitymas uztruko:           | 0.015444s     | 0.166344s      | 1.59188s        | 15.4619s         | 165.159s          |
| Rusiavimas uztruko:          | 0.006081s     | 0.0552494s     | 0.538313s       | 6.18915s         | 60.0473s          |
| Studentu skirstymas uztruko: | 0.002001s     | 0.00835907s    | 0.0876151s      | 1.10855s         | 11.3426s          |

| vector                       | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
| ---------------------------- | ------------- | -------------- | --------------- | ---------------- | ----------------- |
| Skaitymas uztruko:           | 0.008976000s  | 0.085770000s   | 0.831775000s    | 8.325740000s     | 84.65230s         |
| Rusiavimas uztruko:          | 0.003989000s  | 0.092781000s   | 0.4375302s      | 5.6458932s       | 58.65063s         |
| Studentu skirstymas uztruko: | 0.000998000s  | 0.010970000s   | 0.099732000s    | 1.096098000s     | 11.39806s         |

### Installing Inno Setup Compiler

1. Open your web browser and go to the official Inno Setup website: Inno Setup.
2. Locate the downloaded setup file (e.g., `is-X.X.X.exe`).
3. Double-click the setup file to start the installation process.
4. Follow the on-screen instructions to complete the installation. You can use the default settings.

### Creating a Simple Installer Script

1. Open the Inno Setup Compiler from the Start Menu or desktop shortcut.
2. Click on "File" and then "New" to create a new script. The "New Script Wizard" will open.
3. Follow the steps in the wizard:

- Application Information: Enter your application's name, version, and publisher information.
- Application Folder: Specify the default installation folder (e.g., {pf}\MyApp for Program Files).
- Application Files: Add the files you want to include in your installer (e.g., executable files, DLLs, etc.).
- Application Icons: Specify any shortcuts to create (e.g., desktop or Start Menu shortcuts).
- Setup Languages: Select the languages you want to support in your installer.

4. Review your settings and click "Finish." The wizard will generate a basic script.

### Compiling and Running the Script

1. After the script is generated, review it in the Inno Setup Compiler. Make any necessary changes or customizations.
2. Save your script by clicking "File" and then "Save As." Give it a meaningful name (e.g., setup.iss).
3. To compile the script, click "Build" and then "Compile" (or press F9). The compiler will create an installer executable based on your script.
4. Once the compilation is complete, you will see a message indicating that the setup has been compiled successfully.
5. Locate the compiled installer executable (e.g., setup.exe) in the output directory specified in your script.
6. Run the installer to test it and ensure everything works as expected.

# Abstract Class "Zmogus"

#### An abstract class in C++ is a class that contains at least one pure virtual function. A pure virtual function is a virtual function for which we provide only the declaration in the base class, without providing any implementation. Abstract classes are designed to be used as base classes, and they cannot be instantiated directly. Instead, they are intended to serve as interfaces that define a common set of methods that derived classes must implement.

    class Zmogus {
    public:
        virtual void setVardas(std::string vardas) = 0;
        virtual std::string getVardas() const = 0;
        virtual void setPavarde(std::string pavarde) = 0;
        virtual std::string getPavarde() const = 0;
        virtual ~Zmogus() = default;

    };

### The key characteristics of an abstract class are:

- Contains Pure Virtual Functions: An abstract class contains at least one pure virtual function, which is declared with the virtual keyword and assigned the value 0 as its implementation.
- Cannot be Instantiated: Since abstract classes have at least one pure virtual function without an implementation, objects of abstract classes cannot be created directly. Attempting to create an instance of an abstract class will result in a compilation error.
- Used as Base Classes: Abstract classes are meant to be used as base classes. Derived classes inherit from abstract classes and provide concrete implementations for all the pure virtual functions defined in the abstract base class.

# Rule of Five and Overloaded Methods

## Rule of Five

In C++, the Rule of Five refers to a set of guidelines concerning resource management for classes that manage dynamic memory allocation or external resources. The Rule of Five consists of five special member functions that need to be defined or explicitly disabled if one of them is used:

### Destructor

##### Responsible for releasing resources acquired by the object.

    Studentas::~Studentas() {
    nd_rezultatai.clear();
    vardas.clear();
    pavarde.clear();
    egzaminas = 0;

}

### Copy Constructor

#### Creates a new object as a copy of an existing object.

    Studentas::Studentas(const Studentas &copy)
    : vardas(copy.vardas), pavarde(copy.pavarde), nd_rezultatai(copy.nd_rezultatai),egzaminas(copy.egzaminas) {}

### Copy Assignment Operator

#### Assigns the state of one object to another existing object.

    Studentas& Studentas::operator=(const Studentas& copy)
    {
        if(this !=&copy)
        {
            vardas = copy.vardas;
            pavarde = copy.pavarde;
            nd_rezultatai = copy.nd_rezultatai;
            egzaminas = copy.egzaminas;
        }
        return *this;
    }

### Move Constructor

#### Transfers resources from a temporary object to a new object.

        Studentas& Studentas::operator=(Studentas&& copy) noexcept {
            if (this!= &copy) {
                // Swap the members of the current object with the members of the other object
                std::swap(vardas, copy.vardas);
                std::swap(pavarde, copy.pavarde);
                std::swap(nd_rezultatai, copy.nd_rezultatai);
                std::swap(egzaminas, copy.egzaminas);
            }
            return *this;
        }

### Move Assignment Operator

#### Transfers resources from one object to another existing object.

        Studentas& Studentas::operator=(Studentas&& copy) noexcept {
            if (this!= &copy) {
                // Swap the members of the current object with the members of the other object
                std::swap(vardas, copy.vardas);
                std::swap(pavarde, copy.pavarde);
                std::swap(nd_rezultatai, copy.nd_rezultatai);
                std::swap(egzaminas, copy.egzaminas);
            }
            return *this;
        }

## Overloaded Methods

The `Studentas` class overloads the input and output operators (`operator<<` and `operator>>`) to provide serialization and deserialization capabilities. These overloaded methods allow objects of the `Studentas` class to be written to an output stream (e.g., `std::cout` or a file) and read from an input stream (e.g., `std::cin` or a file).

### Output Operator (`operator<<`)

#### The output operator `operator<<` is overloaded to serialize a `Studentas` object to an output stream. It prints the `vardas`, `pavarde`, `egzaminas`, and `nd_rezultatai` member variables to the output stream.

    std::ostream& operator<<(std::ostream& output, const Studentas &student) {
        output << student.vardas << " " << student.pavarde << " " << student.egzaminas << " ";
        for (int pazymys : student.nd_rezultatai) {
            output << std::to_string(pazymys) << " "; // Pries printinant pakeist int'a i string'a
        }
        return output;
    }

### Input Operator (`operator>>`)

#### The input operator `operator>>` is overloaded to deserialize a `Studentas` object from an input stream. It reads `vardas`, `pavarde`, `egzaminas`, and `nd_rezultatai` from the input stream and constructs a `Studentas` object accordingly.

    std::istream& operator>>(std::istream& input, Studentas &student) {
        input >> student.vardas >> student.pavarde;
        input >> student.egzaminas;
        student.nd_rezultatai.clear();
        int pazymys;
        while (input >> pazymys) {
            student.nd_rezultatai.push_back(pazymys);
        }
        return input;
    }

# Running a Makefile for C/C++ Projects

This guide will walk you through the process of running a Makefile for compiling and executing C/C++ programs on both macOS and Windows. If this tutorial does not work for you, try these solutions [Makefile](https://stackoverflow.com/questions/32127524/how-to-install-and-use-make-in-windows).

## Prerequisites

1.  **Make Installation:**

    - macOS: Make is usually pre-installed. You can verify by opening a terminal and typing `make -v`.
    - Windows: Install Make using a package manager like [Chocolatey](https://chocolatey.org/). Run `choco install make` in PowerShell or Command Prompt.

- **C/C++ Compiler:**

  - Ensure you have a C/C++ compiler installed. On macOS, Clang is typically pre-installed. On Windows, you can use MinGW or Cygwin.

- **Text Editor or IDE:**

  - Use a text editor or IDE to write your C/C++ code and Makefile. Popular choices include Visual Studio Code, Sublime Text, Atom, etc.

---

### 1\. Write Your Code

- Create your C/C++ code in one or more `.cpp` or `.c` files.

### 2\. Write Makefile

- Create a file named `Makefile` (without extension) in the same directory as your source code.
- Open `Makefile` in a text editor and define build rules.

### 3\. Open Terminal/Command Prompt

- macOS: Open Terminal.
- Windows: Open Command Prompt or PowerShell.

### 4\. Navigate to Project Directory

- Use `cd` command to navigate to the directory containing your code and Makefile.

### 5\. Run Make

- Type `make` and press Enter. This executes the default target (`all`) in the Makefile.

### 6\. Run Your Program

- After successful build, an executable file (e.g., `run` on macOS or `run.exe` on Windows) will be generated in the same directory.
- Run the program by typing `./run` on macOS or `run.exe` on Windows, and press Enter.

Congratulations! You've successfully compiled and executed your C/C++ program using a Makefile. If you encounter any errors during compilation, check your Makefile and source code for issues.

### 6\. How To Run Code With Flags

- Type `make optimize`
- Type `./run_o1 `
  `./run_o2`
  `./run_o3`
