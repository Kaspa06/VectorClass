#include "studentas.h"
#include <iostream>
#include <fstream>

void testRuleOfFive()
{
    // Create a student
    Studentas original("Jonas", "Jonaitis");
    original.addNamuDarbai(1);
    original.addNamuDarbai(2);
    original.addNamuDarbai(3);
    original.addNamuDarbai(4);
    original.setEgzaminas(5);

    // Test copy constructor
    Studentas copy(original);
    std::cout << copy << std::endl;
    std::cout << original << std::endl;

    // Test copy assignment
    Studentas copyAssignment;
    copyAssignment = original;
    std::cout << copyAssignment << std::endl;
    std::cout << original << std::endl;

    // Test move constructor
    Studentas moved(std::move(original));
    std::cout << original << std::endl;
    std::cout << moved << std::endl;

    // Test move assignment
    Studentas moveAssignment;
    moveAssignment = std::move(moved);
    std::cout << moved << std::endl;
    std::cout << moveAssignment << std::endl;

    std::cout << "The Rule of Five test was successful" << std::endl;
}

void testSerializationDeserialization()
{
    // Create a student
    Studentas student("Jonas", "Jonaitis");
    student.addNamuDarbai(8);
    student.addNamuDarbai(9);
    student.setEgzaminas(10);

    // Serialize the student to a file
    std::ofstream outFile("testSerializationDeserialization.txt");
    if (outFile.is_open())
    {
        outFile << student;
        outFile.close();
        std::cout << "Student serialized to file successfully!" << std::endl;
    }
    else
    {
        std::cerr << "Unable to open file for writing!" << std::endl;
    }

    // Deserialize the student from the file
    Studentas deserializedStudent;
    std::ifstream inFile("student.txt");
    if (inFile.is_open())
    {
        inFile >> deserializedStudent;
        inFile.close();
        std::cout << "Student deserialized from file successfully!" << std::endl;
    }
    else
    {
        std::cerr << "Unable to open file for reading!" << std::endl;
    }

    // Output the deserialized student
    std::cout << deserializedStudent << std::endl;
}
