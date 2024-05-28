#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "studentas.h"
#include "vector.h"
#include <string>

void spausdintiGalutiniusBalus(const vector<Studentas>& studentai, const std::string& isvedimoFailoVardas = "", int rusiavimoTipas = 1);
void manualInput(vector<Studentas>& studentai);
void generateGradesOnly(vector<Studentas>& studentai);
void readFileDataFromFile(vector<Studentas>& studentai, const std::string& failoVardas);
void generateStudentFiles(const vector<int>& sizes);
void rusiuotiStudentus(const vector<int>& sizes);

#endif
