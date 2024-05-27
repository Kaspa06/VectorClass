#include "funkcijos.h"
#include "studentas.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <chrono>

bool sortByVardas(const Studentas &a, const Studentas &b)
{
    return a.getVardas() < b.getVardas();
}

bool sortByPavarde(const Studentas &a, const Studentas &b)
{
    return a.getPavarde() < b.getPavarde();
}

bool sortByVidurkis(const Studentas &a, const Studentas &b)
{
    double vidurkisA = 0.4 * a.calcVidurkis() + 0.6 * a.getEgzaminas();
    double vidurkisB = 0.4 * b.calcVidurkis() + 0.6 * b.getEgzaminas();
    return vidurkisA < vidurkisB;
}

bool sortByMediana(const Studentas &a, const Studentas &b)
{
    double medianaA = 0.4 * a.calcMediana() + 0.6 * a.getEgzaminas();
    double medianaB = 0.4 * b.calcMediana() + 0.6 * b.getEgzaminas();
    return medianaA < medianaB;
}

void spausdintiGalutiniusBalus(const std::vector<Studentas> &studentai, const std::string &isvedimoFailoVardas, int rusiavimoTipas)
{
    std::ostream *out;
    std::ofstream fileOut;

    if (!isvedimoFailoVardas.empty())
    {
        fileOut.open(isvedimoFailoVardas);
        out = &fileOut;
    }
    else
    {
        out = &std::cout;
    }

    std::vector<Studentas> surusiuotiStudentai = studentai;

    switch (rusiavimoTipas)
    {
    case 1:
        sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), sortByVardas);
        break;
    case 2:
        sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), sortByPavarde);
        break;
    case 3:
        sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), sortByVidurkis);
        break;
    case 4:
        sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), sortByMediana);
        break;
    }

    *out << std::fixed << std::setprecision(2);
    *out << "Studentų galutiniai balai:\n";
    *out << "----------------------------------------------------------------\n";
    *out << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << std::endl;
    *out << "----------------------------------------------------------------\n";

for (const Studentas &studentas : surusiuotiStudentai)
    {
        double galutinisVidurkis = 0.4 * studentas.calcVidurkis() + 0.6 * studentas.getEgzaminas();
        double galutineMediana = 0.4 * studentas.calcMediana() + 0.6 * studentas.getEgzaminas();
        *out << std::left << std::setw(15) << studentas.getVardas() << std::setw(15) << studentas.getPavarde() << std::setw(20) << galutinisVidurkis << std::setw(20) << galutineMediana << "\n";
    }
    *out << "----------------------------------------------------------------\n";

    if (!isvedimoFailoVardas.empty())
    {
        fileOut.close();
    }
}

void manualInput(std::vector<Studentas> &studentai)
{
    char testi = 't';
    while (testi == 't' || testi == 'T')
    {
        Studentas naujasStudentas;
        std::string temp;

        std::cout << "Įveskite studento vardą: ";
        std::cin >> temp;
        naujasStudentas.setVardas(temp);

        std::cout << "Įveskite studento pavardę: ";
        std::cin >> temp;
        naujasStudentas.setPavarde(temp);

        std::cout << "Įveskite namų darbų pažymius (0 norint baigti): ";
        int pazymys;
        while (true)
        {
            std::cin >> pazymys;
            if (std::cin.fail() || pazymys < 0 || pazymys > 10)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Neteisingai įvestas pažymys. Turi būti sveikasis skaičius nuo 0 iki 10." << std::endl;
                continue;
            }
            if (pazymys == 0)
            {
                break;
            }
            naujasStudentas.getNamuDarbai().push_back(pazymys);
        }

        std::cout << "Įveskite egzamino rezultatą: ";
        while (true)
        {
            std::cin >> pazymys;
            if (std::cin.fail() || pazymys < 0 || pazymys > 10)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Neteisingai įvestas egzamino rezultatas. Turi būti sveikasis skaičius nuo 0 iki 10." << std::endl;
                continue;
            }
            break;
        }
        naujasStudentas.setEgzaminas(pazymys);

        studentai.push_back(naujasStudentas);

        std::cout << "Ar norite įvesti dar vieną studentą? (t/n): ";
        std::cin >> testi;
    }
}


void generateGradesOnly(std::vector<Studentas> &studentai)
{
    for (Studentas &studentas : studentai)
    {
        studentas.randomND();
    }
}

void readFileDataFromFile(std::vector<Studentas> &studentai, const std::string &failoVardas)
{
    std::ifstream failas(failoVardas);
    if (!failas.is_open())
    {
        throw std::runtime_error("Nepavyko atidaryti failo: " + failoVardas);
    }

    std::string eilute;
    while (getline(failas, eilute))
    {
        std::istringstream eilutesSrautas(eilute);

        std::string vardas, pavarde;
        eilutesSrautas >> vardas >> pavarde;

        Studentas studentas(vardas, pavarde);

        int pazymys;
        studentas.setNamuDarbai({});
        while (eilutesSrautas >> pazymys && pazymys != -1)
        {
            studentas.getNamuDarbai().push_back(pazymys);
        }

        studentas.setEgzaminas(pazymys);

        studentai.push_back(studentas);
    }

    failas.close();
}
void generateStudentFiles(const std::vector<int> &sizes) //padarius su istringstream laikai pamazes (pataisysiu)
{
    for (int size : sizes)
    {
        std::string fileName = "studentai" + std::to_string(size) + ".txt";
        std::ofstream outFile(fileName);

        outFile << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde";
        for (int i = 1; i <= 15; ++i)
        {
            outFile << std::setw(10) << "ND" + std::to_string(i);
        }
        outFile << std::setw(10) << "Egz." << std::endl;

        for (int i = 1; i <= size; i++)
        {
            outFile << std::left << std::setw(15) << "Vardas" + std::to_string(i)
                    << std::setw(15) << "Pavarde" + std::to_string(i);
            for (int j = 0; j < 15; j++)
            {
                outFile << std::setw(10) << (rand() % 10 + 1);
            }
            outFile << std::setw(10) << (rand() % 10 + 1);
            outFile << std::endl;
        }

        outFile.close();
    }
}

void rusiuotiStudentus(const std::vector<int> &sizes)
{
    for (size_t index = 0; index < sizes.size(); ++index)
    {
        std::string fileName = "studentai" + std::to_string(sizes[index]) + ".txt";
        std::ifstream inFile(fileName);

        if (!inFile)
        {
            std::cerr << "Nepavyko atidaryti failo: " << fileName << std::endl;
            continue;
        }

        std::vector<Studentas> studentai, kietiakiai, vargsiukai;
        std::string eilute;
        std::getline(inFile, eilute); // Skipping the header line

        auto startRead = std::chrono::high_resolution_clock::now();

        while (std::getline(inFile, eilute))
        {
            std::istringstream eiluteStream(eilute);
            Studentas tempStudentas;
            std::string vardas, pavarde;
            eiluteStream >> vardas >> pavarde;
            tempStudentas.setVardas(vardas);   // Set vardas using a public setter method
            tempStudentas.setPavarde(pavarde); // Similarly set pavarde if needed

            // Read grades for each student
            int pazymys;
            while (eiluteStream >> pazymys)
            {
                tempStudentas.addNamuDarbai(pazymys); // Add grade using a public member function
            }

            // Process grades (calculate average, etc.)
            std::vector<int> grades = tempStudentas.getNamuDarbai();
            if (!grades.empty())
            {
                tempStudentas.setEgzaminas(grades.back()); // Set exam grade using a public setter method
                grades.pop_back();                          // Remove last grade from nd_rezultatai
                tempStudentas.setNamuDarbai(grades);        // Update grades vector using a public member function
            }

            studentai.push_back(tempStudentas);
        }

        inFile.close();

        auto endRead = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedRead = endRead - startRead;
        std::cout << "Duomenų nuskaitymas iš " << fileName << " užtruko: " << elapsedRead.count() << " sekundžių." << std::endl;

        auto startSort = std::chrono::high_resolution_clock::now();

        std::sort(studentai.begin(), studentai.end(), [](const Studentas &a, const Studentas &b)
                  { return (0.4 * a.calcVidurkis() + 0.6 * a.getEgzaminas()) < (0.4 * b.calcVidurkis() + 0.6 * b.getEgzaminas()); });

        for (const auto &studentas : studentai)
        {
            double galutinisBalas = studentas.calcGalutinis(true);
            if (galutinisBalas < 5.0)
            {
                vargsiukai.push_back(studentas);
            }
            else
            {
                kietiakiai.push_back(studentas);
            }
        }

        auto endSort = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedSort = endSort - startSort;
        std::cout << "Studentų rūšiavimas užtruko: " << elapsedSort.count() << " sekundžių." << std::endl;

        std::ofstream kietiakiaiFile("kietiakiai.txt"), vargsiukaiFile("vargsiukai.txt");

        for (const auto &studentas : kietiakiai)
        {
            kietiakiaiFile << studentas.getVardas() << " " << studentas.getPavarde() << " ";
            for (int pazymys : studentas.getNamuDarbai())
            {
                kietiakiaiFile << pazymys << " ";
            }
            kietiakiaiFile << studentas.getEgzaminas() << std::endl;
        }

        for (const auto &studentas : vargsiukai)
        {
            vargsiukaiFile << studentas.getVardas() << " " << studentas.getPavarde() << " ";
            for (int pazymys : studentas.getNamuDarbai())
            {
                vargsiukaiFile << pazymys << " ";
            }
            vargsiukaiFile << studentas.getEgzaminas() << std::endl;
        }

        kietiakiaiFile.close();
        vargsiukaiFile.close();

        std::cout << "Studentai iš " << fileName << " buvo sekmingai išrūšiuoti ir išsaugoti į atitinkamus failus." << std::endl;
    }
}
