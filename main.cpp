#include "containers.h"
#include "funkcijosVector.h"
#include "funkcijos.h"
#include "studentas.h"
#include "testRules.h"
#include <iostream>
#include <vector>
#include <limits>
#include <deque>
#include <list>
#include <string>
#include <chrono>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <random>
#include <dirent.h>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <stdexcept>
#include "vector.h"
#include "VectorTest.h"

using namespace std;

std::vector<string> listFilesInDirectory() {
    std::vector<string> files;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(".")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            string filename = ent->d_name;
            if (filename != "." && filename != "..") {
                files.push_back(filename);
            }
        }
        closedir(dir);
    } else {
        cerr << "Could not open the directory." << endl;
    }
    return files;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    std::vector<Studentas> studentai;
    int pasirinkimas;
    int rusiavimoTipas;
    std::vector<int> sizes = {1000, 10000, 100000, 1000000, 10000000};
    std::vector<Studentas> kietiakiai, vargsiukai;

    do
    {
        try
        {
            std::cout << "Meniu:" << std::endl
                      << "1 - ivesti studentu duomenis rankiniu budu" << std::endl
                      << "2 - Generuoti pazymius esamiems studentams" << std::endl
                      << "3 - Generuoti naujus studentus su atsitiktiniais pazymiais" << std::endl
                      << "4 - Skaityti duomenis is failo" << std::endl
                      << "5 - Pakeisti rusiavimo tipa" << std::endl
                      << "6 - Rusiuoti studentus sugeneruotuose failuose" << std::endl
                      << "7 - Testuoti The Rule of Five ir >> && << operatorius" << std::endl
                      << "8 - Testuoti VectorClass"<< std::endl
                      << "0 - Baigti darba" << std::endl
                      << "Pasirinkite veiksma: ";
            std::cin >> pasirinkimas;
            if (!std::cin)
            {
                throw std::invalid_argument("Netinkamas pasirinkimas.");
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (pasirinkimas)
            {
            case 1:
                try
                {
                    manualInput(studentai);
                    spausdintiGalutiniusBalus(studentai, "isvedimas.txt");
                }
                catch (const std::exception &e)
                {
                    std::cerr << "ivedimo klaida: " << e.what() << '\n';
                }
                break;
            case 2:
                try
                {
                    generateGradesOnly(studentai);
                }
                catch (const std::exception &e)
                {
                    std::cerr << "Pazymiu generavimo klaida: " << e.what() << '\n';
                }
                break;
            case 3:
                try
                {
                    cout << fixed << setprecision(2);
                    cout << "Studentu galutiniai balai:\n";
                    cout << "----------------------------------------------------------------\n";
                    cout << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Vid.)"
                         << setw(20) << "Galutinis (Med.)\n";
                    cout << "----------------------------------------------------------------\n";

                    for (int i = 0; i < 6; i++)
                    {
                        Studentas naujasStudentas;
                        naujasStudentas.randomStudentai(); 
                        studentai.push_back(naujasStudentas);

                        double galutinisVidurkis = naujasStudentas.calcGalutinis(true);
                        double galutineMediana = naujasStudentas.calcGalutinis(false);
                        cout << left << setw(15) << naujasStudentas.getVardas() << setw(15)
                             << naujasStudentas.getPavarde() << setw(20) << galutinisVidurkis << setw(20)
                             << galutineMediana << "\n";
                    }
                    cout << "----------------------------------------------------------------\n";
                }
                catch (const std::exception &e)
                {
                    std::cerr << "Studentu generavimo klaida: " << e.what() << '\n';
                }
                break;
             case 4: {
                    // List files in the directory
                    std::vector<string> files = listFilesInDirectory();
                    // Display available files
                    cout << "Pasirinkite faila:" << endl;
                    for (size_t i = 0; i < files.size(); ++i) {
                        cout << i + 1 << " - " << files[i] << endl;
                    }
                    // Get user choice
                    int failoPasirinkimas;
                    cout << "Pasirinkimas: ";
                    cin >> failoPasirinkimas;
                    if (cin.fail() || failoPasirinkimas < 1 || failoPasirinkimas > static_cast<int>(files.size())) {
                        throw invalid_argument("Netinkamas failo pasirinkimas.");
                    }
                    // Use the selected file
                    string selectedFile = files[failoPasirinkimas - 1];
                    cout << "Pasirinktas failas: " << selectedFile << endl;
                    break;
                }
            case 5:
                try
                {
                    std::cout << "Pasirinkite nauja rusiavimo buda:" << std::endl
                              << "1 - Pagal varda" << std::endl
                              << "2 - Pagal pavarde" << std::endl
                              << "3 - Pagal vidurki" << std::endl
                              << "4 - Pagal mediana" << std::endl
                              << "Pasirinkimas: ";
                    std::cin >> rusiavimoTipas;
                    if (std::cin.fail())
                    {
                        throw std::invalid_argument("Netinkamas rusiavimo budo pasirinkimas.");
                    }
                    spausdintiGalutiniusBalus(studentai, "isvedimas.txt", rusiavimoTipas);
                }
                catch (const std::exception &e)
                {
                    std::cerr << "Rusiavimo budo keitimo klaida: " << e.what() << '\n';
                }
                break;
            case 6:
            {
                runApp();
                break;
            }
            case 7:
            {
                int test;
                std::cout<<"Ka norite testuoti?"<<std::endl;
                std::cout<<"1 - test Rule Of Five"<<std::endl;
                std::cout<<"2 - test Serialization and Deserialization"<<std::endl;
                std::cout<<"Pasirinkimas: ";
                std::cin>>test;
                if(test == 1)
                {
                    testRuleOfFive();
                }
                else if(test == 2)
                {
                    testSerializationDeserialization();
                }
            }
            case 8:
            {
                std::cout<<"Pradedama testuoti VectorClass"<<std::endl;
                    test_default_constructor();
                    test_fill_constructor();
                    test_copy_constructor();
                    test_move_constructor();
                    test_initializer_list_constructor();
                    test_assignment_operator();
                    test_move_assignment_operator();
                    test_element_access();
                    test_modifiers();
                    test_comparisons();
                    test_fill_time();
            }

            case 0:
                std::cout << "Programa baigia darba." << std::endl;
                break;
            default:
                std::cout << "Neatpazintas pasirinkimas. Bandykite dar karta." << std::endl;
                break;
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Klaida: " << e.what() << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        catch (const std::exception &e)
        {
            std::cerr << "Isimtis: " << e.what() << '\n';
        }
    } while (pasirinkimas != 0);

    return 0;
}
