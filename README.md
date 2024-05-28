# Specs

    CPU: AMD Ryzen 5 5600U with Radeon Graphics 2.30 GHz
    RAM: 16.0 GB (15.3 GB usable)
    SSD: WDC PC SN530 512Gb
    GPU: Integrated with CPU
    OS: Windows 10 Pro 64-bit

# Introduction

### This project provides an implementation of a dynamic array container in C++ named `vector`, similar to `std::vector` from the C++ Standard Library. This custom `vector` class template provides various functionalities to handle dynamic arrays with an emphasis on performance, memory management, and ease of use. The class supports common operations such as insertion, deletion, resizing, and element access while handling memory allocation and deallocation internally.

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
