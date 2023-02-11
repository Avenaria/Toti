#include <string>//Подключение строки 
#include <time.h> //Подключение структуры веремени которой я не пользовалась 
#include<stdlib.h>//одержит в себе функции, занимающиеся выделением памяти
#include<iostream>// стандартная библиотека 

using namespace std;// глобальные переменные 
    int dey;
    int dey2;
    int month;
    int month2;
    int year;
    int year2;

struct listtodo {//вводятся в структуру все данные 
    string listData;  // Класс string предназначен для работы со строками типа char*, которые представляют собой строку с завершающим нулем.
    int priority;//приоритет возможно 
    

    listtodo* next;
};

listtodo* start = NULL, * cancel = NULL; // приравнение обьекта  к нулю что б было значение// самое сомнительное действие но по другому оно не работало (подсмотренно)

void addit_list(string item, int priority) { ///создаём задачу + принимаем приоритет и добавляем егов структуру 
    listtodo* temp; listtodo* last;// создание временных 

    temp = new listtodo;///назначение 
    temp->listData = item;
    temp->priority = priority;

    if (start == NULL || priority <= start->priority) // проверка элемнтов на наличие 
    {

        temp->next = start;
        start = temp;

    }
    else
    {

        last = start;

        while (last->next != NULL && last->next->priority <= priority)// подобие сортировки 
        {
            last = last->next;

        }

        temp->next = last->next;
        last->next = temp;
    }
}

void delite() {
    listtodo* temp; if (start == NULL) { cout << ("\tНет таких вариантов \a\n"); }//Проверка на наличие задачи 
    else {
        temp = start; cout << "\tЗавершение задачи -> \n" << temp->listData << endl; start = start->next; cancel = temp;// удаление задачи через завершение 

    }
} void showlist() { if (cancel != NULL) {
    listtodo* temp; temp = cancel; temp->next = start; 
    //start = temp; cancel = NULL;
    cout << "\t Задачи \a" << temp<<endl; }
else { cout << "\t Задач нет" << endl; } } // проверка на наличие задач

void findlist() {// нахождение  задачи
    listtodo* ptr; ptr = start;//временный обьект 

    if (start == NULL) {// проверка на наличие задач
        cout << "\t Тут ничео нет!\n"<< "\a";
    }
    else
    {
        while (ptr != NULL)// проверка на наличие 
        {
            cout << "Запись " << ptr->listData << " Приоритет :" << ptr->priority << "\n";// вывод на экран 
            ptr = ptr->next;
        }
    }

}
int countOfDayInMonth(int month) {// дней в месяце тут проверка на 30/31
    int sumDay = 0;// переменная для сбора 
    for (int i = 1; i < month; i++) {
        switch (i)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            sumDay += 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            sumDay += 30;
            break;
        case 2:
            sumDay += 28;
            break;
        default:
            break;
        }
    }
    return sumDay;// возврат итоговой суммы 
}
bool IsLeap(int year) {//Проверем високосность 
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));// условия високосности 
}
int DayInYear(int year1, int year2) {//считаем дни в годах +ссылка на проверку високосности 
    int sumDay = 0;//переменная для подсчёта
    for (int i = min(year1, year2); i < max(year1, year2); i++) {
        IsLeap(i) ? sumDay += 366 : sumDay += 365;//тернанрый если високосный или нет от этого зависит количество дней в году
    }
    return sumDay;// возвращаем сумум с учётом годов
}
void countAllDays(int year1, int month1, int day1,// итоговая формула расчёта времени от одной даты до другой 
    int year2, int month2, int day2) {

    int sumDay1 = countOfDayInMonth(month1),//дни в месяцах
        sumDay2 = countOfDayInMonth(month2);//
    sumDay1 += day1;//
    sumDay2 += day2;

    (year1 > year2) ?
        cout << abs(sumDay1 - sumDay2) + DayInYear(year1, year2) << endl :// вывод на экран 
        cout << DayInYear(year1, year2) - abs(sumDay1 - sumDay2) << endl;//вы
}
 



int main() {
    setlocale(LC_ALL, "Russian"); 
 int choice = 0, priority;// пеерменные для выбора и приоритета задачи
 string variable;//строка примающая //контейнер Тип, описывающий специализацию шаблона basic_string класса с элементами типа char в виде string.
system("color 5E");//цвет
while (choice != 5) {// цикл пока пользвотель не выберет 5
 cout << "\t\t++++Список дел!++++++\n";
 cout << "\t==============================\n";
 cout << "\tЧто вы хотетите предпринять? \n";
 cout << "\t* 1 - Добавить задачу \n";
 cout << "\t* 2 - Удалить задачу \n"; 
cout << "\t* 3 - Найти задачу \n";
 cout << "\t* 4 - Посмотреть весь список задач \n";
 cout << "\t* 5 - Выход \n";
 cout << " \t============================== \n";
 cin >> choice; // выбор пользвателя
switch (choice) { // исходя из выбора начинает работать один из кейсов 
case 1:
    cout << "\t * Ведите задачу : " <<"___";
    getline(cin >> ws, variable);// извлекает символы из ввода  потока и добавляет их к строковому объекту до тех пор, пока не встретится символ-разделитель.
    //ws нужна для отброски пробелов пример (std::getline(iss >> std::ws, line);)
    cout << "\t * Введите приоритет от 1 до 5, где 5 максимально допустимый  "; 
    cin >> priority; // приоритет задачи выбранный пользвателем 
    if (priority > 5 || priority < 1) { cout << "\t\tОшибка!! Приоритет не может быть больше 5 и меньше 1\a"; }
    addit_list(variable, priority);
    cout << "\t*Укажите месяц и год начало задачи->";
    cin >> month >> year;
    cout << "\t*Укажите день начала задачи ->";
    cin >> dey;
    if (year > 2023 || year < 1 || month>12 || month < 1 || dey>31 || dey < 1) {//Проверка на корректность ввода данных
        cout << "\tДанные указаны не верно!" << "\a";
    }
    cout << "\t*Определите месяц и год завершения -> ";
    cin >> month2>>year2 ;
    cout << "\t*Oпределите день завершения задачи -> ";
    cin >> dey2;
    if (year2 > 2023 || year2 < 1 || month2>12 || month2 < 1 || dey2>31 || dey2 < 1) {//Повторная проверка на правильность
        cout << "\t<<Данные окончания задачи указаны не верно!" << "\a";
    }
    cout << "\t<< Времени на исполнение задачи осталось  :";
    countAllDays(year, month, dey, year2, month, dey2);
    cout << ">>";
    break;
        case 2:
        delite();
        break;

    case 3:
        findlist();
        break;

    case 4:
        showlist();
        break;

    case 5:
        cout << " ********\t До новых задач! ********* ";
        break;

    default:
        cout << "\a";
        cout << "!!!!!!!!!! Такого пункта нет в меню!!\n";
}
}
}



//Какие преимущества и недостатки дает использование класса string в сравнении с типом char* ?
//Создание нового типа string было обусловлено недостатками работы с строками символов, который демонстрировал тип char* .В сравнении с типом char* тип string имеет следующие основные преимущества :
//
//возможность обработки строк стандартными операторами C++ (=, +, = =, <> и т.п.).Как известно, при использовании типа char* даже наиболее простые операции со строками выглядели сложно и требовали написания чрезмерного программного кода;
//обеспечение лучшей надежности(безопасности) программного кода.Например, при копировании строк, тип string обеспечивает соответствующие действия, которые могут возникнуть в случае, если строка - источник имеет больший размер чем строка - приемник;
//обеспечение строки, как самостоятельного типа данных.Объявление типа string как строки есть единым для всех переменных в программе, которая обеспечивает непротиворечивость данных.
//Основным недостатком типа string в сравнении с типом char*, есть замедленная скорость обработки данных.Это связано с тем, что тип string – это, фактически, контейнерный класс.А работа с классом требует дополнительной реализации программного кода, который, в свою очередь занимает лишнее время.

//string s1 = "s-1";
//string s2 = "s-2";
//string s3;
//bool b;
//
//// операция '=' (присваивание строк)
//s3 = s1; // s3 = "s-1"
//
//// операция '+' - конкатенация строк
//s3 = s3 + s2; // s3 = "s-1s-2"
//
//// операция '+=' - присваивание с конкатенацией
//s3 = "s-3";
//s3 += "abc"; // s3 = "s-3abc"
//
//// операция '==' - сравнение строк
//b = s2 == s1; // b = false
//b = s2 == "s-2"; // b = true
//
//// операция '!=' - сравнение строк (не равно)
//s1 = "s1";
//s2 = "s2";
//b = s1 != s2; // b = true
//
//// операции '<' и '>' - сравнение строк
//s1 = "abcd";
//s2 = "de";
//b = s1 > s2; // b = false
//b = s1 < s2; // b = true
//
//// операции '<=' и '>=' - сравнение строк (меньше или равно, больше или равно)
//s1 = "abcd";
//s2 = "ab";
//b = s1 >= s2; // b = true
//b = s1 <= s2; // b = false
//b = s2 >= "ab"; // b = true
//
//// операция [] - индексация
//char c;
//s1 = "abcd";
//c = s1[2]; // c = 'c'
//c = s1[0]; // c = 'a'
//Как и любой класс, класс string имеет ряд конструкторов.Основные из них следующие :
//
//string();
//string(const char* str);
//string(const string& str);