#include <iostream>
#include <iomanip>
#include <cmath> 
#include <CTYPE.H>
#include <conio.h> 
#include <cstdlib>
#include <ctime>
#include <io.h>
#include <fcntl.h>
#include <cstring> 
#include <string>
#include <Windows.h>
using namespace std;
struct YEAR
{
    int month;
    int year;
};
class Deposit                 //вклад в сбере
{
private:
    YEAR countperiod;
public:
    double startcap = 2188890; //то что мы изначально имеем
    int years = 20;
    float percent = 15.5f;
    double sum = startcap;
    void incrofmon()     //увеличение денег
    {
        countperiod.month = 0;
        countperiod.year = 0;
        while (countperiod.year <= years)
        {
            YEAR period;
            period.month = 3;
            if (countperiod.month % 3 == 0 && countperiod.month != 0)
            {
                double quartalpercent = percent / 4.0 / 100.0;
                double afterpercent = sum * quartalpercent;
                sum += afterpercent;
                percent -= 0.1f;
            }
            countperiod.month ++;
            if (countperiod.month >= 12)
                {
                countperiod.month = 0;
                countperiod.year++;
                }
        }
    }
    void get_inf()
    {
        cout << "общий доход со вклада за " << years << " лет составил " << setw(10) << fixed << setprecision(2) << sum << " рублей" << endl;
    }
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    Deposit Maria;
    Maria.incrofmon();
    Maria.get_inf();
}