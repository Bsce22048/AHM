//
// Created by Admin on 3/23/2023.
//

#ifndef OOP_SEMESTER2_DATE_H
#define OOP_SEMESTER2_DATE_H
/*#include <iostream>

class Date {
public:
    Date(int year, int month, int day) {
        this->year = year;
        this->month = month;
        this->day = day;
    }

    void print() const {
        std::cout << year << "/" << month << "/" << day << std::endl;
    }

    bool operator==(const Date& other) const {
        return year == other.year && month == other.month && day == other.day;
    }

    bool operator!=(const Date& other) const {
        return !(*this == other);
    }

    bool operator<(const Date& other) const {
        if (year < other.year) {
            return true;
        } else if (year > other.year) {
            return false;
        } else if (month < other.month) {
            return true;
        } else if (month > other.month) {
            return false;
        } else {
            return day < other.day;
        }
    }

    bool operator>(const Date& other) const {
        return !(*this == other || *this < other);
    }

private:
    int year;
    int month;
    int day;
};

int main() {
    // Create two Date objects and compare them
    Date date1(2023, 3, 23);
    Date date2(2023, 3, 22);

    if (date1 == date2) {
        std::cout << "The dates are equal" << std::endl;
    } else if (date1 < date2) {
        std::cout << "Date 1 is earlier than Date 2" << std::endl;
    } else {
        std::cout << "Date 1 is later than Date 2" << std::endl;
    }

    return 0;
}


*/
#endif //OOP_SEMESTER2_DATE_H
