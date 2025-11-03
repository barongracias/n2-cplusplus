#include "date.hpp"
#include <stdexcept>

// valid date checker
static bool isValidDate(int d, int m, int y) {
    static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m < 1 || m > 12) return false;

    int dim = daysInMonth[m - 1];
    if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))) {
        dim = 29;
    }
    return (d >= 1 && d <= dim);
}

// instanstiate object
Date::Date(int d, int m, int y) : m_day(d), m_month(m), m_year(y) {
    if (!isValidDate(m_day, m_month, m_year))
        throw std::runtime_error("Invalid date");
}

// get day function
int Date::getDay()const{
    return m_day;
}

// get month function
int Date::getMonth()const{
    return m_month;
}

// get year function
int Date::getYear()const{
    return m_year;
}

// set date function
void Date::set(int d, int m, int y){
    if (!isValidDate(d, m, y)) throw std::runtime_error("Invalid date");
    m_day = d;
    m_month = m;
    m_year = y;
}

// set day function
void Date::setDay(int d){
    if (!isValidDate(d, m_month, m_year)) throw std::runtime_error("Invalid day");
    m_day = d;
}

// set month function
void Date::setMonth(int m){
    if (!isValidDate(m_day, m, m_year)) throw std::runtime_error("Invalid month");
    m_month = m;
}

// add a day function
void Date::advance() {
    static const int daysInMonth[] = 
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dim = daysInMonth[m_month - 1];
    if (m_month == 2 && ((m_year % 4 == 0 && m_year % 100 != 0) || (m_year % 400 == 0))) dim = 29;
    
    if (m_day < dim) {
        m_day++;
    } else {
        m_day = 1;
        if (m_month == 12) {
            m_month = 1;
            m_year++;
        } else {
            m_month++;
        }
    }
}

// deduct a day function
void Date::back() {
    static const int daysInMonth[] = 
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m_day > 1) {
        m_day--;
    } else {
        if (m_month == 1) {
            m_month = 12;
            m_year--;
        } else {
            m_month--;
        }
        int dim = daysInMonth[m_month - 1];
        if (m_month == 2 && ((m_year % 4 == 0 && m_year % 100 != 0) || (m_year % 400 == 0))) dim = 29;
        m_day = dim;
    }
}