#pragma once
#ifndef TRIAD_H
#define TRIAD_H

#include <iostream>
#include <string>
using namespace std;

class Triad {
protected:
    int first, second, third; // ���������� ��� �������� �������� ������
public:
    Triad(int f = 0, int s = 0, int t = 0); // �����������
    virtual ~Triad(); // ����������� ����������

    virtual void inc(const string& field) = 0; // ������ ����������� ����� ����������
    virtual void dec(const string& field) = 0; // ������ ����������� ����� ����������
    virtual void print() const; // ������ ������
};

class Date : public Triad {
public:
    Date(int day = 1, int month = 1, int year = 2000); // �����������
    void inc(const string& field) override;   // ����� ����������
    void dec(const string& field) override;   // ����� ����������
    void print() const override;                       // ������ ����
};

class Time : public Triad {
public:
    Time(int hour = 0, int minute = 0, int second = 0); // �����������
    void inc(const string& field) override;   // ����� ���������� ������� (��������������� ��������)
    void dec(const string& field) override;   // ����� ���������� ������� (��������������� ��������)
    void inc(const string& field, Date& date); // ����� ���������� ������� � ���������� ����
    void dec(const string& field, Date& date); // ����� ���������� ������� � ���������� ����
    void print() const override;                        // ������ �������
};

struct DateTimePair {
    Date date;
    Time time;
};

class Memories {
private:
    DateTimePair* memories; // ������ ��� ����-�����
    int size;               // ������ �������
    int index;              // ������� ������ ��� ���������� ����� ������
public:
    Memories(int count);    // �����������
    ~Memories();            // ����������
    void addMemory(const Date& date, const Time& time); // ���������� ����� ���� � ������
    void printMemories() const; // ������ ���� ���
};

#endif // TRIAD_H
