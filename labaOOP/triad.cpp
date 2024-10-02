#include "triad.h"
#include <iomanip>

// ���������� ������� Triad
Triad::Triad(int f, int s, int t) : first(f), second(s), third(t) {}

Triad::~Triad() = default;

void Triad::print() const {
    cout << first << "." << second << "." << third;
}

// ���������� ������� Date
Date::Date(int day, int month, int year) : Triad(day, month, year) {}

void Date::inc(const string& field) {
    if (field == "day") {
        ++first;
        if (first > 30) {
            first = 1;
            inc("month");
        }
    }
    else if (field == "month") {
        ++second;
        if (second > 12) {
            second = 1;
            inc("year");
        }
    }
    else if (field == "year") {
        ++third;
    }
}

void Date::dec(const string& field) {
    if (field == "day") {
        --first;
        if (first < 1) {
            first = 30;
            dec("month");
        }
    }
    else if (field == "month") {
        --second;
        if (second < 1) {
            second = 12;
            dec("year");
        }
    }
    else if (field == "year") {
        --third;
    }
}

void Date::print() const {
    cout << setfill('0') << setw(2) << first << "."
        << setw(2) << second << "." << third;
}

// ���������� ������� Time
Time::Time(int hour, int minute, int second) : Triad(hour, minute, second) {}

void Time::inc(const string& field) {
    // ���������� ������ ���������� ������� ��� ��������� ����
    if (field == "second") {
        ++third;
        if (third >= 60) {
            third = 0;
            inc("minute");
        }
    }
    else if (field == "minute") {
        ++second;
        if (second >= 60) {
            second = 0;
            inc("hour");
        }
    }
    else if (field == "hour") {
        ++first;
        if (first >= 24) {
            first = 0;
        }
    }
}

void Time::dec(const string& field) {
    // ���������� ������ ���������� ������� ��� ��������� ����
    if (field == "second") {
        --third;
        if (third < 0) {
            third = 59;
            dec("minute");
        }
    }
    else if (field == "minute") {
        --second;
        if (second < 0) {
            second = 59;
            dec("hour");
        }
    }
    else if (field == "hour") {
        --first;
        if (first < 0) {
            first = 23;
        }
    }
}

void Time::inc(const string& field, Date& date) {
    // ���������� ������ ���������� ������� � ���������� ����
    if (field == "second") {
        ++third;
        if (third >= 60) {
            third = 0;
            inc("minute", date);
        }
    }
    else if (field == "minute") {
        ++second;
        if (second >= 60) {
            second = 0;
            inc("hour", date);
        }
    }
    else if (field == "hour") {
        ++first;
        if (first >= 24) {
            first = 0;
            date.inc("day"); // ����������� ����, ���� ���� ��������� �� �������
        }
    }
}

void Time::dec(const string& field, Date& date) {
    // ���������� ������ ���������� ������� � ���������� ����
    if (field == "second") {
        --third;
        if (third < 0) {
            third = 59;
            dec("minute", date);
        }
    }
    else if (field == "minute") {
        --second;
        if (second < 0) {
            second = 59;
            dec("hour", date);
        }
    }
    else if (field == "hour") {
        --first;
        if (first < 0) {
            first = 23;
            date.dec("day"); // ��������� ����, ���� ���� ��������� �� ���������� �����
        }
    }
}

void Time::print() const {
    cout << setfill('0') << setw(2) << first << ":"
        << setw(2) << second << ":" << setw(2) << third;
}

// ���������� ������� Memories
Memories::Memories(int count) : size(count), index(0) {
    memories = new DateTimePair[size]; // �������� ������ ��� ������ ���
}

Memories::~Memories() {
    delete[] memories; // ����������� ������ ��� ���������� �������
}

void Memories::addMemory(const Date& date, const Time& time) {
    if (index < size) {
        memories[index].date = date;   // ��������� ���� � ������
        memories[index].time = time;   // ��������� ����� � ������
        ++index;                       // ����������� ������
    }
    else {
        cerr << "������ ��������. ���������� �������� ������ ������.\n";
    }
}

void Memories::printMemories() const {
    for (int i = 0; i < index; ++i) {
        memories[i].date.print();
        cout << " - ";
        memories[i].time.print();
        cout << endl;
    }
    if (index == 0) {
        cout << "����������� ��� ���."<<endl;
    }
}
