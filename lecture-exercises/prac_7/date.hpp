class Date{
public:
    Date(int, int, int);
    int getDay()const;
    int getMonth()const;
    int getYear()const;
    void set(int, int, int);
    void setDay(int);
    void setMonth(int);
    void advance();
    void back();
private:
    int m_day;
    int m_month;
    int m_year;
};