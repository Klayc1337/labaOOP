#include "triad.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "russian");
    Date date(1, 9, 2024); // Инициализируем дату
    Time time(8, 0, 0);    // Инициализируем время

    Memories memories(5);  // Создаем объект Memories для хранения 5 пар (дата, время)

    string command, field;
    cout << "Текущая дата 01.09.2024 - 08.00.00"<<endl;
    cout << "Виды комманд: " << endl;
    cout << "1) увеличить дату/время." << endl;
    cout << "2) уменьшить дату/время." << endl;
    cout << "3) сохранить текущую дату." << endl;\
    cout << "4) выход." << endl;
    while (true) {
        //cout << "Команда (inc/dec/addMemory/exit): ";
        cout << "Введите команду: ";
        cin >> command; // Чтение команды (inc, dec, addMemory, exit)

        if (command == "4") break; // Выход из программы

        if (command == "3") {
            memories.addMemory(date, time); // Сохраняем текущие дату и время в Memories
            continue;
        }

        cout << "Введите поле (year, month, day, hour, minute, second): ";
        cin >> field; // Чтение поля, которое нужно изменить

        if (command == "1") {
            if (field == "year" or field == "month" or field == "day") {
                date.inc(field); // Увеличиваем дату
            }
            else if (field == "hour" or field == "minute" or field == "second") {
                time.inc(field, date); // Увеличиваем время с изменением дня
            }
        }
        else if (command == "2") {
            if (field == "year" or field == "month" or field == "day") {
                date.dec(field); // Уменьшаем дату
            }
            else if (field == "hour" or field == "minute" or field == "second") {
                time.dec(field, date); // Уменьшаем время с изменением дня
            }
        }

        // Выводим текущие дату и время
        cout << "Текущая дата и время: ";
        date.print();
        cout << " - ";
        time.print();
        cout << endl;
    }
    cout << endl;
    // Печатаем все запомненные пары дата-время
    cout << "Запомненные даты и времена:\n";
    memories.printMemories();

    return 0;
}
