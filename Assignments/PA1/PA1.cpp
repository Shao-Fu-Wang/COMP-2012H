#include <iostream>

using namespace std;

void printmonth(int year, int month, string day, string direction, int mem);
string montharr[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
int monthdays[12] = {31, 28, 31, 30, 31, 30 ,31, 31, 30, 31, 30, 31};    // leap year 29 in feb
string dayarr[7] = {"Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"};
string on9shit[12] = {"", "January               February              March\n", "", "", "April                 May                   June\n", "", "", "July                  August                September\n", "", "", "October               November              December\n"};
string cyka = "Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa\n";
int memorizer[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int done[12] = {0};

int calstartday(int year){
    int leapbefore = 0;
    for(int i = 1800; i < year; i++){
        if(i%4==0 && (i%100!=0 || i%400==0)){
            leapbefore++;
        }
    }   
    return leapbefore; 
} 

bool leapdetect(int year){
    if(year%4==0 && (year%100!=0 || year%400==0)){
        return 1;
    }
    else{
        return 0;
    }
}

void printthree(int year, int month){
    if(month == 1){
        cout<<"December "<<year-1<<"         January "<<year<<"          February "<<year<<"\n"<<cyka;
        while(!done[11] || !done[0] || !done[1]){
            printmonth(year-1, 12, "s", "h", 1);
            printmonth(year, 1, "s", "h", 1);
            printmonth(year,2, "s", "h", 1);
            cout<<"\n";
        }
    }
    else if(month == 12){
        cout<<"November "<<year<<"         December "<<year<<"         January "<<year+1<<"\n"<<cyka;
        while(!done[10] || !done[11] || !done[0]){
            printmonth(year, 11, "s", "h", 1);
            printmonth(year, 12, "s", "h", 1);
            printmonth(year+1, 1, "s", "h", 1);
            cout<<"\n";
        }
    }
    else{       // a little left
        cout<<montharr[month-2]<<" "<<year;
        for(int i = 0; i < 17-montharr[month-2].length(); i++){
            cout<<" ";
        }
        cout<<montharr[month-1]<<" "<<year;
        for(int i = 0; i < 17-montharr[month-1].length(); i++){
            cout<<" ";
        }
        cout<<montharr[month]<<" "<<year<<"\n"<<cyka;
        while(!done[month-2] || !done[month-1] || !done[month]){
            printmonth(year, month-1, "s", "h", 1);
            printmonth(year, month, "s", "h", 1);
            printmonth(year, month+1, "s", "h", 1);
            cout<<"\n";
        }
    }
}
void printyear(int year){
    cout<<"Year "<<year<<"\n";
    int checkall = 0;
    int firsttarget = 1;
    while(checkall == 0){
        cout<<on9shit[firsttarget]<<cyka;
        while(!done[firsttarget-1] || !done[firsttarget] || !done[firsttarget+1]){
            for(int i = firsttarget; i < firsttarget+3; i++){
                printmonth(year, i, "s", "h", 1);
            }
            cout<<"\n";
        }
        cout<<"\n";
        firsttarget+=3;
        for(int i = 0; i < 12; i++){
            if(done[i] == 1){
                checkall = 1;
            }
            else{
                checkall = 0;
                break;
            }
        }
    }
}

void printmonth(int year, int month, string day, string direction, int mem){
    int leapbefore = calstartday(year);
    int normalbefore = year-1800-leapbefore;
    bool isleap = leapdetect(year);
    int daysfromyearstart = 0;
    for(int i = 0; i < month-1; i++){
        if(isleap){
            if(i == 1){daysfromyearstart+=29;}
            else{daysfromyearstart+=monthdays[i];}
        }
        else{
            daysfromyearstart+=monthdays[i];
        }
    }
    int daysbefore = leapbefore*366 + normalbefore*365 + daysfromyearstart;
    // cout<<"DAYSBE4 = "<<daysbefore<<endl;
    int weekday = (daysbefore+3)%7;
    if(!mem){cout<<montharr[month-1]<<" "<<year<<"\n";}
    if(direction == "h"){
        if(day == "s"){ //horizontal, start from sunday
            int spacecnt = 0;  
            int dater = memorizer[month-1];   
            if(!mem){cout<<"Su Mo Tu We Th Fr Sa\n";}
            if(dater == 1){
                for(int i = 0; i < weekday*3; i++){
                    cout<<" ";
                    spacecnt++;
                }
            }
            for(int i = dater;(isleap&&month==2?i<=monthdays[month-1]+1:i<=monthdays[month-1]) && done[month-1] == 0; i++){
                if(spacecnt%21 == 0 && i != 1){
                    if(mem && spacecnt!=0){memorizer[month-1] = i; cout<<" "; return;}
                    if(!mem){cout<<"\n";}
                }
                if(i < 10){
                    cout<<" "<<i<<" ";
                }
                else{
                    cout<<i<<" ";
                }
                spacecnt+=3;
            }
            done[month-1] = 1;
            for(int i = 0; i < 22 - spacecnt; i++){
                cout<<" ";
            }
        }
        if(day == "m"){ //horizontal, start from monday
            int spacecnt = 0;     
            if(weekday == 0){weekday = 7;}
            cout<<"Mo Tu We Th Fr Sa Su\n";
            for(int i = 0; i < (weekday-1)*3 ; i++){
                cout<<" ";
                spacecnt++;
            }
            for(int i = 1; (isleap&&month==2?i<=monthdays[month-1]+1:i<=monthdays[month-1]); i++){
                if(spacecnt%21 == 0  && i != 1){
                    cout<<"\n";
                }
                if(i < 10){
                    cout<<" "<<i<<" ";
                }
                else{
                    cout<<i<<" ";
                }
                spacecnt+=3;
            }
        }
    }
    if(direction == "v"){
        if(day == "s"){ //horizontal, start from sunday     
            for(int i = 0; i < 7; i++){
                cout<<dayarr[i%7]<<" ";
                if(i < weekday){
                    cout<<"   ";
                    for(int j = i+1+7-weekday ; (isleap&&month==2?j<=monthdays[month-1]+1:j<=monthdays[month-1]); j+=7){
                        if(j < 10){
                            cout<<" "<<j<<" ";
                        }
                        else{
                            cout<<j<<" ";
                        }
                    }
                    cout<<"\n";
                }
                else{
                    for(int j = i+1-weekday ; (isleap&&month==2?j<=monthdays[month-1]+1:j<=monthdays[month-1]); j+=7){
                        if(j < 10){
                            cout<<" "<<j<<" ";
                        }
                        else{
                            cout<<j<<" ";
                        }
                    }
                    cout<<"\n";
                }
            }
        }
        if(day == "m"){ //horizontal, start from monday 
            if(weekday==0){weekday = 7;}
            for(int i = 0; i < 7; i++){
                cout<<dayarr[(i+1)%7]<<" ";
                if(i+1 < weekday){
                    cout<<"   ";
                    for(int j = i+2+7-weekday ; (isleap&&month==2?j<=monthdays[month-1]+1:j<=monthdays[month-1]); j+=7){
                        if(j < 10){
                            cout<<" "<<j<<" ";
                        }
                        else{
                            cout<<j<<" ";
                        }
                    }
                    cout<<"\n";
                }
                else{
                    for(int j = i+2-weekday ; (isleap&&month==2?j<=monthdays[month-1]+1:j<=monthdays[month-1]); j+=7){
                        if(j < 10){
                            cout<<" "<<j<<" ";
                        }
                        else{
                            cout<<j<<" ";
                        }
                    }
                    cout<<"\n";
                }
            }
        }
    }
}

int main(){
    int year=0, yearlegal=0, month=0, monthlegal=0, daylegal=0, directionlegal=0;
    string day, direction;
    while(!yearlegal){
        cout<<"Enter year (in range 1800-9999): ";
        cin>>year;
        yearlegal = year>=1800 && year<=9999; 
    }
    while(!monthlegal){
        cout<<"Enter month (in range 1-12): ";
        cin>>month;
        monthlegal = (month>=1 && month<=12) || (month==-1||month==-3);
    }
    if(month!=-1&&month!=-3){
        while(!daylegal){
            cout<<"Enter the first day of week ('s' for Sunday, 'm' for Monday): ";
            cin>>day;
            daylegal = day=="m" || day=="s";
        }
        while(!directionlegal){
            cout<<"Print horizontally (h) or vertically (v): "; 
            cin>>direction;
            directionlegal = direction=="h" || direction=="v";
        }
        printmonth(year, month, day, direction, 0);
    }
    else{
        if(month==-1){
            printyear(year);
        }
        if(month==-3){
            cout<<"Enter the month in the center (in range 1-12): ";
            cin>>month;
            printthree(year, month);
        }
    }
}