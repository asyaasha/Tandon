
#include <iostream>
using namespace std;

const int DAYS_IN_WEEK = 7;
int printMonthClendar(int numOfDays, int startingDay);
bool IsLeap (int year);
void printYearCalendar(int year, int startingDay);
int findStartingDay(int newDay, int last );

int main() {
    int inputYear, inputStartingDay;
    
    cout<<"Please enter the year for your calendar: ";cin>>inputYear;
    do
    {
    cout<<"Please enter the number of the day of the week it starts (1-7): ";cin>>inputStartingDay;
    }while(inputStartingDay<1 || inputStartingDay>7);
    printYearCalendar(inputYear, inputStartingDay);
    return 0;
}

int printMonthClendar(int numOfDays, int startingDay){
    
    char empty = ' ';
    int numberOfLastDay = 0;
    int shift = startingDay - 1;
    int day = 1;

    cout<<"Mon\t"<<"Tue\t"<<"Wed\t"<<"Thr\t"<<"Fri\t"<<"Sat\t"<<"Sun\t"<<endl;
    
    do{
        if ((startingDay >= 1) && (startingDay<=7)){ //print spaces depending of starting day.
            for (int i = 0; i < shift; i++ ){
                cout<<empty<<"\t";
                
            }
            startingDay-=1;
        }
        numberOfLastDay = 0;
        for (startingDay; startingDay< DAYS_IN_WEEK; startingDay++){
            if (day == (numOfDays +1) ){ //print spaces after all days printed.
                cout<<empty<<"\t";
            }
            else {
                cout<<day<<"\t";
                day++;
                numberOfLastDay+=1;
            }
        }
        cout<<endl; //starts new week
        startingDay = 0;
        
    }while(day < (numOfDays +1));
    
    return numberOfLastDay;
}

bool isLeap (int year){
    if ((year % 4 ==0 && year % 100 != 0) || year % 400 == 0)
        return true;
    else
        return false;
}

void printYearCalendar(int year, int startingDay){

    
    string month;
    int daysInMonth, newStartingDay, lastDay;


    for(int m = 1; m <= 12; m++)
    {
        switch (m){
                
            case 1:
                cout<<"January "<<year<<endl;
                daysInMonth = 31;
                lastDay = printMonthClendar(daysInMonth, startingDay);
                newStartingDay = findStartingDay(newStartingDay, lastDay);

                break;
            case 2:
                cout<<"February "<<year<<endl;
                if (isLeap(year)){
                    daysInMonth = 29;}
                else{
                     daysInMonth = 28;
                }
                
                lastDay = printMonthClendar(daysInMonth, newStartingDay);
                cout<<endl;
                newStartingDay = findStartingDay(newStartingDay, lastDay);
                break;
            case 3:
                cout<<"March "<<year<<endl;
                daysInMonth = 31;
                lastDay = printMonthClendar(daysInMonth, newStartingDay);
                newStartingDay = findStartingDay(newStartingDay, lastDay);
                break;
            case 4:
                cout<<"April "<<year<<endl;
                daysInMonth = 30;
                lastDay = printMonthClendar(daysInMonth, newStartingDay);
                newStartingDay = findStartingDay(newStartingDay, lastDay);
                break;
            case 5:
                cout<<"May "<<year<<endl;
                daysInMonth = 31;
                lastDay = printMonthClendar(daysInMonth, newStartingDay);
                cout<<endl;
                newStartingDay = findStartingDay(newStartingDay, lastDay);
                break;
            case 6:
                cout<<"June "<<year<<endl;
                daysInMonth = 30;
                lastDay = printMonthClendar(daysInMonth, newStartingDay);
                newStartingDay = findStartingDay(newStartingDay, lastDay);
                break;
            case 7:
                cout<<"July "<<year<<endl;
                daysInMonth = 31;
                lastDay = printMonthClendar(daysInMonth, newStartingDay);
                newStartingDay = findStartingDay(newStartingDay, lastDay);
                break;
            case 8:
                cout<<"August "<<year<<endl;
                daysInMonth = 31;
                lastDay = printMonthClendar(daysInMonth, newStartingDay);
                newStartingDay = findStartingDay(newStartingDay, lastDay);
                break;
            case 9:
                cout<<"September "<<year<<endl;
                daysInMonth = 30;
                lastDay = printMonthClendar(daysInMonth, newStartingDay);
                newStartingDay = findStartingDay(newStartingDay, lastDay);
                break;
            case 10:
                cout<<"October "<<year<<endl;
                daysInMonth = 31;
                lastDay = printMonthClendar(daysInMonth, newStartingDay);
                newStartingDay = findStartingDay(newStartingDay, lastDay);
                break;
            case 11:
                cout<<"November "<<year<<endl;
                daysInMonth = 30;
                lastDay = printMonthClendar(daysInMonth, newStartingDay);
                newStartingDay = findStartingDay(newStartingDay, lastDay);
                break;
            case 12:
                cout<<"December "<<year<<endl;
                daysInMonth = 31;
                lastDay = printMonthClendar(daysInMonth, newStartingDay);
                newStartingDay = findStartingDay(newStartingDay, lastDay);
                break;
            default:
                cout<<"something went wrong";
                break;
        
        }
    }
}
int findStartingDay(int newDay, int last ){
    newDay = last +=1;
    if (last == 8){
        newDay =1;
    }
    cout<<endl;
    return newDay;
};

