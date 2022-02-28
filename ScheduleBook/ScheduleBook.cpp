#include<iomanip>
#include<iostream>
#include<cstring>
#include<string>
#include<ctime>
#include<time.h>
#include<conio.h>
using namespace std;

//all function for checking
//Definite leap year
bool isleap(int year)
{
    bool ans = 0;
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return 1;
    else
        return 0;
}

//Checking leap year
int leapOrnot(int year) //leap year or not
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return 366;
    else
        return 365;
}

//Get the days
int nmonth(int m, int y)
{
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        return 31;
    else if (leapOrnot(y) == 366 && m == 2)
        return 29;
    else if (leapOrnot(y) == 365 && m == 2)
        return 28;
    else
        return 30;
}

//checking the format of event
int getDays(int year, int month)//from 1899.12.31 to the user input, total days 
{
    int i;
    int sum = 0;
    if (year > 1989)
        for (i = 1989; i < year; i++)
            sum += leapOrnot(i);
    if (month > 1)
        for (i = 1; i < month; i++)
            sum += nmonth(i, year);

    return sum;     //total days
}

//checking the format of event
bool eventcheck(string a) {

    if (a.length() < 46) {
        return 1;
    }

    else {
        return 0;
    }
}

//Check the format of date 
bool formatcheck(string d) {

    bool ans = false;


    if (d.length() == 10 && d[2] == '-' && d[5] == '-') {

        ans = true;
    }

    else {

        ans = false;
    }

    return ans;
}

//check the range of date
bool rangecheck(string d) {

    //declare variable
    int dd, mm, year;
    bool n = 0, correct = 0;
    //string to integer
    dd = 10 * (d[0] - 48) + (d[1] - 48);
    mm = 10 * (d[3] - 48) + (d[4] - 48);
    year = (1000 * (d[6] - 48)) + (100 * (d[7] - 48)) + (10 * (d[8] - 48)) + (d[9] - 48);

    if (((year % 4) == 0 && (year % 100) != 0) || (year % 400 == 0)) {

        n = 1;
    }
    else {

        n = 0;
    }

    if (mm >= 1 && mm <= 12) {
        if (n == 0) {

            correct = (dd >= 1 && dd <= 30 || (dd == 31 && mm % 2 == 0)); // not leap year judgement
        }
        else {
            if (mm == 2) {											      // leap year judgement
                correct = (dd <= 29);
            }
            else {
                correct = (dd >= 1 && dd <= 30 || (dd == 31 && mm % 2 == 0));
            }
        }
    }
    else
        correct = 0;

    //output
    return correct;

}

//check the format of time
bool hourformat(string T) {

    bool ans = false;

    if (T.length() == 5 && T[2] == ':') {

        ans = true;
    }

    else {

        ans = false;
    }

    return ans;
}

//check the range of time
bool hourcheck(string T) {

    int hh, mm;
    bool ans = 0;

    hh = 10 * (T[0] - 48) + (T[1] - 48);
    mm = 10 * (T[3] - 48) + (T[4] - 48);

    if (hh < 24 && hh > -1 && mm <60 && mm > -1) {
        ans = 1;
    }

    else {
        ans = 0;
    }

    return ans;
}

//check the eventtype
bool eventtype_checking(string t) {

    bool ans = 0;

    if (t.compare("1") == 0) {
        ans = true;
    }
    else if (t.compare("2") == 0) {
        ans = true;
    }
    else if (t.compare("3") == 0) {
        ans = true;
    }
    else if (t.compare("4") == 0) {
        ans = true;
    }

    else { ans = 0; }

    return ans;
}

//class for ScheduleBook
class ScheduleBook
{
private:

    string d[100], st[100], ed[100], et[100], tp[100];
    string starttime, endtime, date, event, type;
    int counter = 0;
    bool checking = false;
    int M[100] = { 0 }, Y[100] = { 0 }, D[100] = { 0 };
    int i = 0;
    int c = 0;

public:

    void store() {
        //int type for display
        D[i] = 10 * (date[0] - 48) + (date[1] - 48);
        M[i] = 10 * (date[3] - 48) + (date[4] - 48);
        Y[i] = (1000 * (date[6] - 48)) + (100 * (date[7] - 48)) + (10 * (date[8] - 48)) + (date[9] - 48);
        //string type
        d[i] = date;
        st[i] = starttime;
        ed[i] = endtime;
        et[i] = event;
        tp[i] = type;
        i++;
    } //store the data 
    void meun(); //main_meun
    int geteventdata(); //Add one event
    void sorting(); //Do sorting
    int deleteevent(); // delete event
    int getevents(); // Add events in batch
    int showallevent(); //show meun
    void show(); //show all events
    void show_calender(); // show calender view
    void showlist(); //show event in coming few days
    void credits(); // show personal data
    string typetostring(string tp); // Time type to string
    bool timeconflict(string, string, string); // check time conflict

};

//main function
int main()
{
    system("COLOR E");
    ScheduleBook book1;
    book1.meun();
    system("cls");
    cout << "thx for your using";

}

//class function
//main_meun
void ScheduleBook::meun()
{
    system("cls");
    int a = 0;
    int option;

    //User interface display
    cout << "Welcome Message designed by our group" << endl;
    cout << "**** Main Menu ****" << endl;
    cout << "[1] Add one Event  " << endl;
    cout << "[2] Delete one Event  " << endl;
    cout << "[3] Add events in batch  " << endl;
    cout << "[4] Show events  " << endl;
    cout << "[5] Credits  " << endl;
    cout << "[6] Exit  " << endl;
    cout << "*******************" << endl;
    cout << "Option (1-6) : ";

    cin >> option;

    //option switch
    if (option == 1)
    {
        cin.ignore();
        a = geteventdata();
        if (a == 1)
        {
            store();
            meun();
        }
        else
        {
            meun();
        }
    }
    else if (option == 2)
    {
        sorting();
        deleteevent();
        meun();
    }
    else if (option == 3)
    {
        a = 0;
        a = getevents();
        if (a == 1)
        {
            cout << "Input succeed!!Data save" << endl;
            cout << "Please press any key to go back Main_Meun!!!!" << endl;
            system("pause");
            meun();
        }
        else
        {
            meun();
        }
    }
    else if (option == 4)
    {
        sorting();
        a = 0;
        a = showallevent();
        while (a == 1) {
            meun();
        }
    }
    else if (option == 5)
    {
        credits();
        system("pause");
        meun();
    }
    else if (option == 6)
    {
        string ans;
        cout << "Are u sure to left?(Y/N)" << endl;
        cin >> ans;
        if (ans.compare("y") == 0 || ans.compare("Y") == 0)
        {
            exit(0);
        }
        else if (ans.compare("n") == 0 || ans.compare("N") == 0)
        {
            meun();
        }
    }
}

int ScheduleBook::geteventdata()
{
    system("cls");
    //intialize
    checking = 0;
    counter = 0;
    //checking event for the format
    while (checking != 1) {

        cout << "Event : ";
        getline(cin, event);
        checking = eventcheck(event);

        if (checking != 1) {

            counter++;
            cout << "Input Wrong" << endl;

            if (counter == 3) {
                cout << "Sorry, back to main_menu" << endl;
                return -1;
            }
        }
    }

    //intialize
    checking = 0;
    counter = 0;
    //check date for format && range    
    while (checking != 1)
    {
        cout << "Date(DD-MM-YYYY): ";
        cin >> date;
        checking = formatcheck(date);
        if (checking != 1) //if first time is wrong 
        {
            counter++;
            cout << "Invalid Format  of Input" << endl;
            if (counter == 3) //if input for 3 times, back to meun
            {
                cout << "Sorry, back to main_menu" << endl;
                system("pause");
                return -1;
            }
        }
        else
        {
            checking = rangecheck(date);
            if (checking != 1)
            {    //if first time is wrong 
                counter++;
                cout << "Invalid date of Input" << endl;
                if (counter == 3) //if input for 3 times, back to meun
                {
                    cout << "Sorry, back to main_menu" << endl;
                    return -1;
                }
            }
        }
    }

    //intialize
    checking = 0;
    counter = 0;
    //check starttime for format && range    
    while (checking != 1)
    {
        cout << "Start_Time(HH:MM): ";
        cin >> starttime;
        checking = hourformat(starttime);
        if (checking != 1) //if first time is wrong 
        {
            counter++;
            cout << "Invalid Format of Input" << endl;
            if (counter == 3) //if input for 3 times, back to meun
            {
                cout << "Sorry, back to main_menu" << endl;
                system("pause");
                return -1;
            }
        }
        else
        {
            checking = hourcheck(starttime);
            if (checking != 1) //if first time is wrong 
            {
                counter++;
                cout << "Invalid startime of Input" << endl;
                if (counter == 3) //if input for 3 times, back to meun
                {
                    cout << "Sorry, back to main_menu" << endl;
                    return -1;
                }
            }
        }
    }

    //intialize
    checking = 0;
    counter = 0;
    //check endtime for format && range    
    while (checking != 1)
    {
        cout << "End_time(HH:MM): ";
        cin >> endtime;
        if (endtime.compare(starttime) > 0)
        {
            checking = hourformat(endtime);
            if (checking != 1) //if first time is wrong 
            {
                counter++;
                cout << "Invalid Format of Input" << endl;
                if (counter == 3) //if input for 3 times, back to meun
                {
                    cout << "Sorry, back to main_menu" << endl;
                    system("pause");
                    return -1;
                }
            }

            else
            {
                checking = hourcheck(endtime);
                if (checking != 1) //if first time is wrong 
                {
                    counter++;
                    cout << "Invalid endtime of Input" << endl;
                }
                else if (counter == 3) //if input for 3 times, back to meun
                {
                    cout << "Sorry, back to main_menu" << endl;
                    system("pause");
                    return -1;
                }
            }
        }
        else
        {
            counter++;
        }
    }

    //intialize
    checking = 0;
    counter = 0;
    while (checking != 1)
    {
        cout << "Event_Type ((1)Home, (2)Work, (3)Study, (4)Play): ";
        cin >> type;
        checking = eventtype_checking(type);
        if (checking != 1) //if first time is wrong 
        {
            counter++;
            cout << "Invalid Format of Input" << endl;
            if (counter == 3) //if input for 3 times, back to meun
            {
                cout << "Sorry, back to main_menu" << endl;
                system("pause");
                return -1;
            }
        }
    }

    //skip checking for 1st input
    c++;

    //intialize
    checking = 0;
    if (c == 1)
    {
        cout << "Input succeed!!Data save" << endl;
        cout << "Please press any key to go back Main_Meun!!!!" << endl;
        system("pause");
        return 1;
    }
    else
    {
        checking = timeconflict(date, starttime, endtime);
        if (checking == 0)
        {

            cout << "Sorry, It has time conflict" << endl;
            system("pause");
            return -1;
        }
        else
        {
            cout << "Input succeed!!Data save" << endl;
            cout << "Please press any key to go back Main_Meun!!!!" << endl;
            system("pause");
            return -1;
        }
    }
}

void ScheduleBook::sorting()
{
    for (int n = 0; n < i; n++)
    {
        for (int j = n + 1; j < i; j++)
        {
            if (d[n].compare(d[j]) > 0)
            {
                swap(d[n], d[j]); //swap date
                swap(st[n], st[j]); //swap starttime
                swap(ed[n], ed[j]); //swap endtime
                swap(et[n], et[j]); //swap eventtime
                swap(tp[n], tp[j]); //swap type
            }

            else if (d[n].compare(d[j]) == 0)
            {
                if (st[n].compare(st[j]) > 0)
                {
                    if (ed[n].compare(ed[j]) > 0)
                    {
                        swap(d[n], d[j]); //swap date
                        swap(st[n], st[j]); //swap starttime
                        swap(ed[n], ed[j]); //swap endtime
                        swap(et[n], et[j]); //swap eventtime
                        swap(tp[n], tp[j]); //swap type
                    }
                }
            }
        }
    }
}

int ScheduleBook::deleteevent()
{
    system("cls");
    string idate;
    //input date
    cin >> idate;

    // filter array no.
    int f[100] = { 0 }, a = 0, z = 0;
    do
    {
        if (idate.compare(d[z]) == 0)
        {
            f[a] = z;
            a++;
        }
        z++;
    } while (z <= i);

    // output filtered event

    for (int z = 0; z < a; z++) {

        cout << z + 1 << ": " << d[f[z]] << "/" << st[f[z]] << "/" << ed[f[z]] << "/" << et[f[z]] << "/" << tp[f[z]] << endl;

    }

    // enter event no. going to erase / return main menu
    int k, j;
    cout << "Enter the event number you want to erase: ";
    cin >> k;


    // delete event
    for (j = 0; j < z - 1; j++)
    {
        if (j == f[k - 1])
        {
            for (j = f[k - 1]; j < z - 1; j++)
            {
                d[j] = d[j + 1];
                st[j] = st[j + 1];
                ed[j] = ed[j + 1];
                et[j] = et[j + 1];
                tp[j] = tp[j + 1];
            }
            d[z - 1] = "\0";
            st[z - 1] = "\0";
            ed[z - 1] = "\0";
            et[z - 1] = "\0";
            tp[z - 1] = "\0";
        }
    }

    i--;

    return -1;
}

int ScheduleBook::getevents()
{
    system("cls");
    // substr
    string all;
    bool input = 0;
    int Success = 0, Fail = 0, counter = 0;
    cin.ignore();
    do
    {
        input = 0;
        getline(cin, all);
        if (all != "0") {

            date = all.substr(0, 10);
            starttime = all.substr(11, 5);
            endtime = all.substr(17, 5);
            event = all.substr(23, all.length() - 25);
            type = all.substr(all.length() - 1);
            if (counter == 0)
            {
                Success++;
                store();
            }
            else
            {
                input = timeconflict(date, starttime, endtime);
                if (input != 0)
                {
                    Success++;
                    store();
                }
                else
                {
                    Fail++;
                }
            }
            counter++;
        }

    } while (all != "0");
    cout << "Total " << counter << " events in batch" << endl;
    cout << Success << " event(s) added" << endl;
    cout << Fail << " event(s) not added due to time conflict" << endl;
    return 1;
}

int ScheduleBook::showallevent()
{
    system("cls");
    int number;
    cout << "*** Show Event Menu ****" << "\n";
    cout << "[1] Show all events" << "\n";
    cout << "[2] Show events (list view)" << "\n";
    cout << "[3] Show events (calendar view)" << "\n";
    cout << "[4] Return to Main Menu" << "\n";
    cout << "************" << "\n";
    cout << "Option (1-4): ";
    cin >> number;

    switch (number) {
    case 1:
        sorting();
        show();
        break;
    case 2:
        showlist();
        break;
    case 3:
        show_calender();
        break;
    case 4:
        ScheduleBook::meun();
        break;
    }

    system("pause");
    return 1;

}

void ScheduleBook::show()
{
    system("cls");
    cout << left << setw(25) << "Date and Time" << setw(45) << "Title" << setw(5) << "Type" << endl;

    for (int z = 0; z < i; z++)
    {
        cout << left << setw(10) << d[z] << "," << left << setw(5) << st[z] << ":" << left << setw(8) << ed[z] << left << setw(45) << et[z] << left << setw(5) << typetostring(tp[z]) << endl;
    }
}

void ScheduleBook::showlist() {

    system("cls");
    //declare variable
    string types;
    int inputday, days, months, years;
    struct tm t;
    time_t now;
    time(&now);
    char dd[80];

    localtime_s(&t, &now); //gettime from current time

    //user input
    cout << "Please state you event type : ";
    cin >> types;
    cout << "Please state you coming n days : ";
    cin >> inputday;

    //transfer the time to string type 
    strftime(dd, sizeof(dd), "%d-%m-%Y", &t);

    //transfer the string type to int
    days = 10 * (dd[0] - 48) + (dd[1] - 48);
    months = 10 * (dd[3] - 48) + (dd[4] - 48);
    years = (1000 * (dd[6] - 48)) + (100 * (dd[7] - 48)) + (10 * (dd[8] - 48)) + (dd[9] - 48);

    //display
    cout << left << setw(25) << "Date and Time" << setw(45) << "Title" << setw(5) << "Type" << endl;
    for (int k = 0; k < inputday; k++) {
        for (int h = 0; h < i; h++)
        {
            if (days == D[h] && months == M[h] && years == Y[h])
            {
                if (types == tp[h])
                    cout << left << setw(10) << d[h] << "," << left << setw(5) << st[h] << ":" << left << setw(8) << ed[h] << left << setw(45) << et[h] << left << setw(5) << typetostring(tp[h]) << endl;
            }
        }

        days++;
        if (days > 28) {
            if (months == 2 && !isleap(years)) {
                days -= 28;
                months++;
            }
        }
        if (days > 29) {
            if (months == 2 && isleap(years)) {
                days -= 29;
                months++;
            }
        }
        if (days > 30) {
            switch (months) {
            case 4:
            case 6:
            case 9:
            case 11:
                days -= 30;
                months++;
            }
        }
        if (days > 31) {
            switch (months) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
                days -= 31;
                months++;
                break;
            case 12:
                days -= 31;
                months = 1;
                years++;
            }

        }

    }
}

void ScheduleBook::show_calender()
{

    system("cls");
    char DD[3];
    int MM = 0, YYYY, ootd, sum, countDay = 1, color;
    cout << "please type your date(MM-YYYY): ";
    cin.ignore();
    cin.getline(DD, 3, '-');
    MM = 10 * (DD[0] - 48) + (DD[1] - 48);
    cin >> YYYY;

    sum = getDays(YYYY, MM);
    ootd = sum % 7;
    countDay = nmonth(MM, YYYY);

    //special feature
    cout << "you can choose your calender color((1)Light Blue, (2)White, (3)Green) :";
    cin >> color;
    if (color == 1)
    {
        system("COLOR 9");
    }
    else if (color == 2)
    {
        system("COLOR 7");
    }
    else if (color == 2)
    {
        system("COLOR 2");
    }

    system("cls");
    cout << "============================" << endl;
    cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;
    cout << "----------------------------" << endl;
    for (int i = 0; i < ootd % 7; i++)
        cout << "    ";
    for (int i = 1, j = ootd + 1; i <= countDay; i++, j++)
    {
        cout << setw(4) << setiosflags(ios::left) << i;
        if (j % 7 == 0)
            cout << endl;
    }
    cout << endl;
    cout << "============================" << endl;
    //list all of the events in that month

    // count<< all the event title and Time
    cout << left << setw(40) << "Event Title" << left << setw(16) << "Date" << left << setw(5) << "Time" << endl;
    //arraysize = how many input stored

    for (int h = 0; h < i; h++) {

        if (M[h] == MM && Y[h] == YYYY) {
            cout << left << setw(40) << et[h] << left << setw(15) << d[h] << ' ' << left << setw(5) << st[h] << "-" << left << setw(5) << ed[h] << endl;
        }
    }
}

void ScheduleBook::credits()
{
    cout << "Group leader    :" << "Wong Man HO" << endl;
    cout << "Student name    :" << "Wong Man HO" << endl;
    cout << "Student ID      :" << "19135951A" << endl;
    cout << "Class           :" << "203" << endl;
    cout << "Tutorial group :" << "203B" << endl << endl;

    cout << "Group member    :" << endl;
    cout << "Student name    :" << "Au Tsz Ching" << endl;
    cout << "Student ID      :" << "19139685A" << endl;
    cout << "Class           :" << "203" << endl;
    cout << "Tutorial group :" << "203D" << endl << endl;

    cout << "Student name    :" << "Li Ka Man " << endl;
    cout << "Student ID      :" << "19136290A" << endl;
    cout << "Class           :" << "203" << endl;
    cout << "Tutorial group  :" << "203D" << endl << endl;

    cout << "Student name    :" << "Lam Sui Wo" << endl;
    cout << "Student ID      :" << "19136124A" << endl;
    cout << "Class           :" << "203" << endl;
    cout << "Tutorial group  :" << "203B" << endl << endl;

    cout << "Student name    :" << "Law Wun Tsz" << endl;
    cout << "Student ID      :" << "19109251A" << endl;
    cout << "Class           :" << "203" << endl;
    cout << "Tutorial group  :" << "203B" << endl;

    cout << "Student name    :" << "Chan Yik Tung" << endl;
    cout << "Student ID      :" << "19118235A" << endl;
    cout << "Class           :" << "203" << endl;
    cout << "Tutorial group :" << "203C" << endl << endl;
}

string ScheduleBook::typetostring(string tp)
{
    if (tp.compare("1") == 0)
    {
        return "Home";
    }

    else if (tp.compare("2") == 0)
    {
        return "Work";
    }

    else if (tp.compare("3") == 0)
    {
        return "Study";
    }

    else if (tp.compare("4") == 0)
    {
        return "Play";
    }
    else { return 0; }
}

bool ScheduleBook::timeconflict(string d1, string start, string end)
{
    bool a1 = 0;

    for (int n = 0; n < i; n++)
    {
        if (d1.compare(d[n]) == 0)
        {

            for (int z = 0; z < i; z++)
            {
                if ((start.compare(st[z]) >= 0 && end.compare(ed[z]) < 0) || ((start.compare(st[z]) <= 0) && end.compare(ed[z]) <= 0) || (start.compare(ed[z]) < 0 && end.compare(ed[z]) >= 0) || (start < st[z] && end > ed[z]))
                {
                    a1 = false;
                }
                else
                {
                    a1 = true;
                }
            }
        }
        else
        {
            a1 = true;
        }

    }

    return a1;
}