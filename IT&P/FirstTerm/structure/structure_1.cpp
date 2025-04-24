//Создать структуру Hotel, содержащую следующие данные: ФИО туриста, дату прибытия и дату отъезда.
//Определить сколько дней каждый турист проведет в отеле. Необходима проверка на корректность ввода дат.

#include "iostream"
#include "string"
using namespace std;

struct Hotel {
    string name;//Имя
    string inDate;//Прибытие
    string outDate;//Отъезд
};

int main() {
    Hotel tourist;
    int stay = 0;
    cout << "Enter name(FIO): ";
    getline(cin, tourist.name);

    cout << "Enter in date: ";
    getline(cin, tourist.inDate);

    cout << "Enter out date: ";
    getline(cin, tourist.outDate);

    // Разбор дат
    int inDay = stoi(tourist.inDate.substr(0, 2));
    int inMonth = stoi(tourist.inDate.substr(3, 2));
    int inYear = stoi(tourist.inDate.substr(6, 4));

    int outDay = stoi(tourist.outDate.substr(0, 2));
    int outMonth = stoi(tourist.outDate.substr(3, 2));
    int outYear = stoi(tourist.outDate.substr(6, 4));

    //Коррекность дат
    bool valid = true;
    switch(inMonth) {//Прибытие
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if(inDay < 1 || inDay > 31)
                valid = false;
            break;
        case 4: case 6: case 9: case 11:
            if(inDay < 1 || inDay > 30)
                valid = false;
            break;
        case 2:
            if((inYear % 4 == 0 && inYear % 100 != 0) || inYear % 400 == 0) {
                if(inDay < 1 || inDay > 29)
                    valid = false;
            } else {
                if(inDay < 1 || inDay > 28)
                    valid = false;
            }
            break;
        default:
            valid = false;
    }

    if(inYear < 1900 || inYear > 2100)
        valid = false;

    switch(outMonth) {//Отъезд
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if(outDay < 1 || outDay > 31)
                valid = false;
            break;
        case 4: case 6: case 9: case 11:
            if(outDay < 1 || outDay > 30)
                valid = false;
            break;
        case 2:
            if((outYear % 4 == 0 && outYear % 100 != 0) || outYear % 400 == 0) {
                if(outDay < 1 || outDay > 29)
                    valid = false;
            } else {
                if(outDay < 1 || outDay > 28)
                    valid = false;
            }
            break;
        default:
            valid = false;
    }
    if(outYear < inYear || (outYear == inYear && outMonth < inMonth) || (outYear == outYear && outMonth == inMonth && outDay < inDay)) {//проверка что уедет позже чем приехал
        valid = false;
    }
    if(outYear < 1900 || outYear > 2100) {
        valid = false;
    }

    if(!valid) {
        cout << "incorrect date " << endl;
        return 1;
    }

    //Длительность прибывания
    stay += (outDay - inDay);
    stay += (outMonth - inMonth) * 30;
    stay += (outYear - inYear) * 365;

    cout << tourist.name << " " << stay << " days" << endl;

    return 0;
}
