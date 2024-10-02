#pragma once
#ifndef TRIAD_H
#define TRIAD_H

#include <iostream>
#include <string>
using namespace std;

class Triad {
protected:
    int first, second, third; // Переменные для хранения значений тройки
public:
    Triad(int f = 0, int s = 0, int t = 0); // Конструктор
    virtual ~Triad(); // Виртуальный деструктор

    virtual void inc(const string& field) = 0; // Чистый Виртуальный метод увеличения
    virtual void dec(const string& field) = 0; // Чистый Виртуальный метод уменьшения
    virtual void print() const; // Печать тройки
};

class Date : public Triad {
public:
    Date(int day = 1, int month = 1, int year = 2000); // Конструктор
    void inc(const string& field) override;   // Метод увеличения
    void dec(const string& field) override;   // Метод уменьшения
    void print() const override;                       // Печать даты
};

class Time : public Triad {
public:
    Time(int hour = 0, int minute = 0, int second = 0); // Конструктор
    void inc(const string& field) override;   // Метод увеличения времени (переопределение базового)
    void dec(const string& field) override;   // Метод уменьшения времени (переопределение базового)
    void inc(const string& field, Date& date); // Метод увеличения времени с изменением даты
    void dec(const string& field, Date& date); // Метод уменьшения времени с изменением даты
    void print() const override;                        // Печать времени
};

struct DateTimePair {
    Date date;
    Time time;
};

class Memories {
private:
    DateTimePair* memories; // Массив пар дата-время
    int size;               // Размер массива
    int index;              // Текущий индекс для добавления новой памяти
public:
    Memories(int count);    // Конструктор
    ~Memories();            // Деструктор
    void addMemory(const Date& date, const Time& time); // Добавление новой пары в память
    void printMemories() const; // Печать всех пар
};

#endif // TRIAD_H
