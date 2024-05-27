#ifndef FUNKCIJOSVECTOR_H
#define FUNKCIJOSVECTOR_H

#include "studentas.h"
#include <vector>

void readDataVector(std::vector<Studentas>& studentai, const std::string& failoVardas);
void generateStudentFilesVector(int size);
void rusiuotStudentusVector(const std::string& failoVardas);
void rusiuotStudentusVector2(const std::string& failoVardas);
void rusiuotStudentusVector3(const std::string &failoVardas);

#endif // FUNKCIJOSVECTOR_H
