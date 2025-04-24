#include "iostream"
#include "string"
#include "fstream"
using namespace std;

int main() {
    ifstream inputFile("C:/Users/super/CLionProjects/proga/file.txt");
    ofstream outputFile("C:/Users/super/CLionProjects/proga/of.txt");

    if (!inputFile.is_open()) {//проверяем что файлы открылись
        cerr << "Не удалось открыть входной файл." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Не удалось создать выходной файл." << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        //Поиск для dd.mm.yyyy
        size_t dotPos1 = line.find('.');//первая точка
        size_t dotPos2 = line.find('.', dotPos1 + 1);//вторая точка
        if (dotPos1 != string::npos && dotPos2 != string::npos) {
            string dateStr = line.substr(dotPos1 - 2, 10);
            //проверяем, что все символы это числа
            if (dateStr.length() == 10 && isdigit(dateStr[0]) && isdigit(dateStr[1]) && isdigit(dateStr[3]) && isdigit(dateStr[4]) && isdigit(dateStr[6]) && isdigit(dateStr[7]) && isdigit(dateStr[8]) && isdigit(dateStr[9])) {
                int day = stoi(dateStr.substr(0, 2));//преобразование в числа
                int month = stoi(dateStr.substr(3, 2));
                int year = stoi(dateStr.substr(6, 4));

                if (month >= 1 && month <= 12 && day >= 1 && day <= 31) {//Проверка корректности даты
                    switch (month) {
                        case 2:  // Февраль
                            if (day <= 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
                                outputFile << line << "\n";
                        break;
                        case 4: case 6: case 9: case 11:  // Апрель, июнь, сентябрь, ноябрь
                            if (day <= 30)
                                outputFile << line << "\n";
                        break;
                        default:
                            outputFile << line << "\n";
                    }
                }
                }
        }

        // Поиск для dd month yyyy
        size_t spacePos1 = line.find(' ');
        size_t spacePos2 = line.find(' ', spacePos1 + 1);
        if (spacePos1 != string::npos && spacePos2 != string::npos) {
            string dayStr = line.substr(0, spacePos1);
            string monthStr = line.substr(spacePos1 + 1, spacePos2 - spacePos1 - 1);
            string yearStr = line.substr(spacePos2 + 1);

            if (dayStr.length() == 2 && yearStr.length() == 4 && isdigit(dayStr[0]) && isdigit(dayStr[1] && isdigit(yearStr[0]) && isdigit(yearStr[1]) && isdigit(yearStr[2]) && isdigit(yearStr[3]))) {
                int day = stoi(dayStr);//преобразовние дня и года в число
                int year = stoi(yearStr);

                // Проверка корректности дат
                if (day >= 1 && day <= 31 && year >= 1000 && year <= 9999) {
                    // Проверка названия месяца
                    if (monthStr == "January" || monthStr == "March" || monthStr == "May" || monthStr == "July" || monthStr == "August" || monthStr == "October" || monthStr == "December") {
                        if (day <= 31) {
                            outputFile << line << "\n";
                        }
                    }
                    else if (monthStr == "April" || monthStr == "June" || monthStr == "September" || monthStr == "November") {
                        if (day <= 30) {
                            outputFile << line << "\n";
                        }
                    }
                    else if (monthStr == "February") {
                        if (day <= 28 || (day == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))){
                            outputFile << line << "\n";
                        }
                    }
                }
            }
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}