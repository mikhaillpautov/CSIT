//Реализовать функции для работы с датой: определение количества прошедших дней, определение даты через N дней, корректность даты,
//определение дня недели, определение сколько времени прошло между двумя датами.
#include<iostream>
#include<cmath>
#include<string>

using namespace std;

struct Date{
    int day;
    int month;
    int year;
};

int DaysOfMonth(int m, int y){ // количество дней в месяце
switch (m) {
case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
case 4: case 6: case 9: case 11: return 30;
case 2:
    if((y%4 == 0 && y%100 != 0) || y%400 == 0)
        return 29;
    else
        return 28;}
}

Date STR_date(string str){ //перевод из строки в дату
    Date data;
    string str1 = str.substr (0, 2);
    int dd = atoi(str1.c_str());
    data.day = dd;
    str1 = str.substr (3, 2);
    dd = atoi(str1.c_str ());
    data.month = dd;
    str1 = str.substr (6, 4);
    dd = atoi(str1.c_str ());
    data.year = dd;
    return data;
}

bool correct(string str ){ //проверка корректности данных
    if (str.length() != 10) 
        return false;
    for(string::size_type i = 0; i < str.length(); i++)
        if (i != 2 && i != 5){
            if (! isdigit (str[i])) 
                return false;
        }
    Date data = STR_date(str);
    if (data.day <= 0 || data.day > DaysOfMonth(data.month, data.year)) 
        return false;
    if (data.month <= 0 || data.month > 12) 
        return false;
    if (data.year == 0) 
        return false;
    return true;
}

int Period (Date date1, Date date2){ // количество дней между двумя датами
    int days = 0;
    days -= date1.day;
    days += date2.day;
    for (int i = 1; i < date2.month; i++) 
        days += DaysOfMonth(i, date2.year);
    for (int i = 1; i < date1.month; i++) 
        days -= DaysOfMonth(i, date1.year);
    days += (date2.year - date1.year)*365;
    return abs(days);
}

void WeekDay(Date date){ // определение дня недели
    int D = date.day;
    int M = date.month;
    int Y = date.year;
    int a, y, m, R;
    a = (14 - M) / 12;
    y = Y - a;
    m = M + 12 * a - 2;
    R = 7000 + (D + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
    cout << "day of the week: ";
    R = R % 7;
    switch(R){
        case 0:
            cout << "sunday\n";
            break;
        case 1:
            cout << "monday\n";
            break;
        case 2:
            cout << "thuesday\n";
            break;
        case 3:
            cout << "wednesday\n";
            break;
        case 4:
            cout << "thursday\n";
            break;
        case 5:
            cout << "friday\n";
            break;
        case 6:
            cout << "saturday\n";
            break;
    }
}

void After(Date date, int n){ // определение даты через N дней
    string nd,nm,ny;
    while(n > 30){
        n -= DaysOfMonth(date.month, date.year);
        date.month += 1;
        if (date.month == 13){
            date.year += 1;
            date.month = 1;
        }
    }
    if (DaysOfMonth(date.month, date.year) <= n){
        n -= DaysOfMonth(date.month, date.year);
        date.month += 1;
        if (date.month == 13){
            date.year += 1;
            date.month = 1;
        }
    }
    date.day += n;
    if (date.day > DaysOfMonth(date.month, date.year)){
        date.day -= DaysOfMonth(date.month, date.year);
        date.month += 1;
        if (date.month == 13){
            date.year += 1;
            date.month = 1;
        }
    }

    cout << "Date after n days: " << date.day << "." << date.month << "." << date.year << "\n";
}

void print(Date date1, Date date2, int n){
    Date date3 = date1;
    Date start = STR_date("01.01.2000");
    cout << "Days from 01.01.2000 = " << Period(date1, start) << "\n";
    After(date1, n);
    WeekDay(date1);
    cout << "Between 2 dates : " << Period(date1, date2) << " days";
}

int main(){
    string date_1, date_2;
    cout << "Enter 2 dates ";
    cin >> date_1 >> date_2;
    if (!correct(date_1) || !correct(date_2)){
            cout << "Incorrect date\n";
            return 0;
        }

    Date date1 = STR_date(date_1), date2 = STR_date(date_2);

    int n;
    cout << "Enter n days = ";
    cin >> n;

    cout << "\nDate 1:\n";
    print(date1, date2, n);

    cout << "\n\n Date 2:\n";
    print(date2, date1, n);

    return 0;
}