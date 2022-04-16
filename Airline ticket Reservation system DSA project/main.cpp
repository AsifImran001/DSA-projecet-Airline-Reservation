/**************************AIRLINE TICKET RESERVATION SYSTEM *********************************************************
                           DEVELEPED BY:
                           ASIF IMRAN      asifimrofficial@gmail.com
                           whatsapp me :   0317-1797662*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <conio.h>
#include <stdio.h>
#include <typeinfo>
#include <windows.h>
#include <time.h>
#include <iomanip>
#include <algorithm>

using namespace std;
void Credit();
void print_header(string name)
{
    system("cls");
    cout << "\n\t\t\t********************************\n";
    cout << left << setw(10) << "\t\t\t" << name << "          \n";
    cout << "\t\t\t********************************\n\n";
}
bool check_number(long long int no)
{
    if (no <= 0)
        return false;
    return true;
}
bool checkString(string s)
{ // checks if string consists only of letters

    if (!s.empty())
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (!((s.at(i) >= 'a' && s.at(i) <= 'z') || (s.at(i) >= 'A' && s.at(i) <= 'Z') || s.at(i) == ' '))
            {
                return false;
            }
        }
        return true;
    }
    else
    { //return false
        return false;
    }
}
bool checkFlightNo(string s)
{
    if (!s.empty())
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (!((s.at(i) >= 'A' && s.at(i) <= 'Z') || (s.at(i) >= '0' && s.at(i) <= '9' || s.at(i) == '-')))
            {
                return false;
            }
        }
        return true;
    }
    else
    { //return false
        return false;
    }
}
bool Is_empty(std::ifstream &fin)
{
    return fin.peek() == std::ifstream::traits_type::eof();
}
long long int Input_checkNO(string type)
{
    long long int No;
    cout << "\t\t\t Please Enter " << type << " : ";
    cin >> No;
    while (!cin)
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\t\t\t Please Enter Valid " << type << " : ";
        cin >> No;
    }
    while (!check_number(No))
    {
        cout << "\t\t\t Please Enter Valid " << type << " : ";
        cin >> No;
    }
    return No;
}

bool compareTime(int T1[], int T2[])
{
    if (T1[0] < T2[0])
    {
        return true;
    }
    else if (T1[0] == T2[0])
    {
        if (T1[1] < T2[1])
            return true;
    }
    else
        return false;
}

class Date_time
{

    short Hours;
    short Minutes;
    string Opening_day;
    string Closing_day;
    time_t t = time(NULL);
    tm *timeptr = localtime(&t);

public:
    Date_time()
    {
        this->Hours = 8;
        this->Minutes = 45;
        this->Opening_day = "Monday";
        this->Closing_day = "Satureday";
    }
    void Setday()
    {
        cout << "Enter Opening day: ";
        cin >> Opening_day;
        cout << "Enter Closing day: ";
        cin >> Closing_day;
    }
    void SetTime()
    {
        cout << "Enter Hours: ";
        cin >> Hours;
        cout << "Enter Minutes: ";
        cin >> Minutes;
    }
    void Print_day()
    {
        cout << "Opens 24/7\n"
             << Opening_day << " to " << Closing_day << endl;
    }
    void Print_Agency_Time()
    {
        cout << Hours << ":" << Minutes << " am" << endl;
    }
    void Print_Date()
    {
        cout << (timeptr->tm_mday) << "/" << (timeptr->tm_mon) + 1 << "/" << (timeptr->tm_year) + 1900;
    }
    void Print_time()
    {
        cout << (timeptr->tm_hour) << ":" << (timeptr->tm_min) << ":" << (timeptr->tm_sec);
    }
    int Get_Hourse() { return (timeptr->tm_hour); }
    int Get_minutes() { return (timeptr->tm_min); }
    int Get_Seconds() { return (timeptr->tm_sec); }

    int Get_year() { return (timeptr->tm_year); }
    int Get_Month() { return (timeptr->tm_mon); }
    int Get_Day() { return (timeptr->tm_mday); }
};

class login
{
    long long int Username;
    int password;
    int DOB[3];

public:
    bool flag = false;
    login()
    {

        this->Username = 0;
        this->password = 0;
    }
    void SetLogin(long long usename, int dob[])
    {
        print_header("ADDING LOGIN");
        this->Username = usename;
        this->DOB[0] = dob[0];
        this->DOB[1] = dob[1];
        this->DOB[2] = dob[2];
        cout << "\t\t\t UserName :" << Username << endl;
        password = Input_checkNO("Password");
    }
    void Print_Login()
    {
        cout << "\n\t\t\t<><><><><><><><><><><><><><><><>\n"
             << endl;
        cout << "\t\t\t User Name :" << this->Username << endl;
        cout << "\t\t\t Password  :" << this->password << endl;
        cout << "\n\t\t\t<><><><><><><><><><><><><><><><>" << endl;
    }
    void reset_password()
    {
        password = Input_checkNO("New Password");
    }
    long long int GetUsername() { return Username; }
    int Get_Password() { return this->password; }
    int *get_DOB() { return DOB; }
    void Set_UserName(long long int pass) { this->password = pass; }
};

class Person
{
protected:
    char Name[20];
    char Father_Name[20];
    int DOB[3];
    char Gender[7];
    long long int CNIC;
    long long int Phone_No;

public:
    Person()
    {
        strcpy(Name, "None");
        strcpy(Father_Name, "None");
        DOB[0] = 0;
        DOB[1] = 0;
        DOB[2] = 0;
        CNIC = 0;
        Phone_No = 0;
        strcpy(Gender, "None");
    }
    void Set_Person()
    {
        char choice;
        choice = 'y';
        cout << "\t\t\t Please Enter  Name ";
        gets(Name);
        while (!checkString(Name))
        {
            cout << "\t\t\t Please Enter Valid  Name ";
            gets(Name);
        }
        cout << "\t\t\t Please Enter Father Name ";
        gets(Father_Name);
        while (!checkString(Father_Name))
        {
            cout << "\t\t\t Please Enter Valid Father Name ";
            gets(Father_Name);
        }
        cout << "\t\t\t Please Enter Gender ";
        gets(Gender);
        while (!checkString(Gender))
        {
            cout << "\t\t\t Please Enter Valid Gender ";
            gets(Father_Name);
        }
        do
        {
        LOOP:
        {
            cout << "\t\t\t Please enter Date of Birth : (DD\\MM\\YY) ";
            for (int i = 0; i < 3; i++)
            {
                cin >> DOB[i];
                while (!cin)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Please Enter valid Date of Birth :";
                    cin >> DOB[i];
                }
            }
        }
            if (DOB[0] <= 0 || DOB[0] > 31 || DOB[1] <= 0 || DOB[1] > 12 || DOB[2] <= 1915 || DOB[2] == 0 || DOB[2] >= 2020)
            {
                goto LOOP;
            }

            choice = 'n';
        } while (choice != 'n');

        CNIC = Input_checkNO("CNIC #");
        Phone_No = Input_checkNO("Phone #");
        while (Phone_No == CNIC)
        {
            cout << "\t\t\t Please enter a valid Phone #:";
            cin >> Phone_No;
        }
        cin.clear();
        cin.ignore(256, '\n');
        choice = 'n';
    }

    void print_person()
    {
        cout << "\t\t\t Name:            " << Name << endl;
        cout << "\t\t\t Father Name:     " << Father_Name << endl;
        cout << "\t\t\t Date Of Birth :  " << DOB[0] << "/" << DOB[1] << "/" << DOB[2] << endl;
        cout << "\t\t\t Gender:          " << Gender << endl;
        cout << "\t\t\t CNIC:            " << CNIC << endl;
        cout << "\t\t\t Phone No:        " << Phone_No << endl;
    }
};

class Passenger : protected Person
{
    long long int passport;
    char nationality[30];

public:
    Passenger() : Person()
    {
        passport = 0;
        strcpy(nationality, "None");
    }
    void Set_passenger()
    {

        Set_Person();
        cout << "\t\t\t Please Enter Nationality ";
        gets(nationality);
        while (!checkString(nationality))
        {
            cout << "\t\t\t Please Enter Valid Nationallity ";
            gets(nationality);
        }
        passport = Input_checkNO("Passport #");
        while (passport == Phone_No)
        {
            cout << "\t\t\t Please enter a valid Passport #:";
            cin >> passport;
        }
        cin.clear();
        cin.ignore(256, '\n');
    }
    void printPassenger(int count)
    {

        print_person();
        cout << "\t\t\t Nationality:     " << nationality << endl;
        cout << "\t\t\t Passport #:      " << passport << endl;
    }
    string Get_passengerName() { return this->Name; }
    long long int Get_passengerCNIC() { return this->CNIC; }
    long long int Get_passengerPassport() { return this->passport; }
    string Get_gender() { return Gender; }
    int *getDOB() { return this->DOB; }
    void set_name(char name[30]) { strcpy(this->Name, name); }
    void set_Fname(char Fname[30]) { strcpy(this->Father_Name, Fname); }
    void set_CNIC(long long int CNIC) { this->CNIC = CNIC; }
    void set_DOB(int a, int b, int c)
    {
        this->DOB[0] = a;
        this->DOB[1] = b;
        this->DOB[2] = c;
    }
    void set_PassportNo(long long int passport) { this->passport = passport; }
    void Set_Gender(string Gender) { strcpy(this->Gender, Gender.c_str()); }
   
   
    void readFile(ifstream &fin)
    {
        fin.read((char *)this, sizeof(*this));
    }
  
  
    void writeFile(ofstream &fout)
    {
        fout.write((char *)this, sizeof(*this));
    }
};

class Seat
{
    int seat_NO = 0;
    char seat_type[15];
    int tax = 0;

public:
    Seat()
    {
        this->seat_NO = 0;

        this->tax = 0;
        strcpy(seat_type, "None");
    }
    void Set_seat()
    {
        char choice;
        cout << "\n\t\t\t Note : If you choose Bussines Class RS 20000 tax will apply.\n ";
        cout << "\n\t\t\t choose \n";
        cout << "\t\t\t1. Bussiness Class.\n\t\t\t2. Economy Class" << endl;
        cout << "\t\t\t Enter Here : ";
        choice = _getche();
        switch (choice)
        {
        case '1':
            strcpy(seat_type, "Bussiness");
            tax = tax + 20000;
            seat_NO = seat_NO + (rand() % 40 + 1);
            break;
        case '2':
            strcpy(seat_type, "Economy");
            tax = 0;
            seat_NO = (rand() % 70 + 40);
            break;
        default:
            cout << "\n\t\t\tInvalid input ..try again" << endl;
            break;
            getch();
            system("cls");
        }
    }
    string Get_seat_type() { return seat_type; }
    int Get_seat_no() { return seat_NO; }
    int Get_tax() { return tax; }
};

class flight
{
private:
    char Plane_Name[20];
    char flight_no[20];
    char Flight_type[20];
    int Arrival_time[2];
    int Departure_time[2];
    char Departure[20];
    char Destination[20];
    int travle_time;
    int Rent;
    int Booked;
    int total;

public:
    flight()
    {
        strcpy(Plane_Name, "none");
        strcpy(flight_no, "none");
        Arrival_time[0] = 0;
        Arrival_time[1] = 0;
        Departure_time[0] = 0;
        Departure_time[1] = 0;
        strcpy(Departure, "none");
        strcpy(Destination, "none");
        strcpy(Flight_type, "None");
        travle_time = 0;
        Rent = 0;
        this->total = 0;
        this->Booked = 0;
    }
    void print(int Sr)

    {
        cout << left << setw(9) << Sr << left << setw(11) << Plane_Name << left << setw(13) << flight_no << left << setw(11) << Departure << left << setw(15) << Destination << left << setw(1) << Departure_time[0] << " : " << left << setw(8) << Departure_time[1] << left << setw(1) << Arrival_time[0] << " : " << left << setw(10) << Arrival_time[1] << left << setw(9) << Rent << left << setw(7) << Flight_type << endl;
    }
    void SetFlight(string Type)
    {
        cin.clear();
        cin.ignore(256, '\n');
        print_header("GETTING DATA");
        cout << "\t\t\t Please Enter Plane Name ";
        gets(Plane_Name);
        while (!checkString(Plane_Name))
        {
            cout << "\t\t\t Please Enter Valid plane Name ";
            gets(Plane_Name);
        }
        cout << "\t\t\t Enter flight No :";
        gets(flight_no);
        while (!checkFlightNo(flight_no))
        {
            cout << "\t\t\t Enter Valid flight No :";
            gets(flight_no);
        }
        cout << "\t\t\t Please Enter Departure City : ";
        gets(Departure);
        while (!checkString(Departure))
        {
            cout << "\t\t\t Please Enter Valid Departure city : ";
            gets(Departure);
        }
        cout << "\t\t\t Please Enter Destination City : ";
        gets(Destination);
        while (!checkString(Destination))
        {
            cout << "\t\t\t Please Enter Valid Destination city : ";
            gets(Destination);
        }
        cout << "\t\t\t Please Enter Departure Time (HH:MM):";
        for (int i = 0; i < 2; i++)
        {
            cin >> Departure_time[i];
            while (!cin)
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "\t\t\t Please Enter Valid Departure Time (HH:MM):";
                cin >> Departure_time[i];
            }
        }
        cout << "\t\t\t Please Enter Arrival Time (HH:MM):";
        for (int i = 0; i < 2; i++)
        {
            cin >> Arrival_time[i];
            while (!cin)
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "\t\t\t Please Enter Valid Arrival Time (HH:MM):";
                cin >> Arrival_time[i];
            }
        }
        while (!compareTime(Departure_time, Arrival_time))
        {
            cout << "\t\t\t Enter Valid Arrival Time HH:MM : ";
            for (int i = 0; i < 2; i++)
            {
                cin >> Arrival_time[i];
            }
        }

        travle_time = Departure_time[0] - Arrival_time[0];
        strcpy(this->Flight_type, Type.c_str());
        Rent = Input_checkNO("Rent");

        total = Input_checkNO("No of Seats");

        while (!check_number(Rent))
        {
            cout << "\t\t\t Enter valid  No of Seats :";
            cin >> total;
        }
        cin.ignore(256, '\n');
    }
    string Get_Departure() { return this->Departure; }
    string Get_Destination() { return this->Destination; }
    string Get_PlaneName() { return this->Plane_Name; }
    string Get_FlightNo() { return this->flight_no; }
    string Get_FlightType() { return Flight_type; }
    int Get_rent() { return Rent; }
    int Get_Departure_time() { return this->Departure_time[0]; }
    int Get_Arrival_time() { return this->Arrival_time[0]; }
    string Get_travel_type() { return Flight_type; }
    void Set_flightNo(string flightNo) { strcpy(this->flight_no, flightNo.c_str()); }
    void Set_PlaneName(string Plane_Name) { strcpy(this->Plane_Name, Plane_Name.c_str()); }
    void Set_Destination(string Destination) { strcpy(this->Destination, Destination.c_str()); }
    void Set_Departure(string Departure) { strcpy(this->Departure, Departure.c_str()); }
    void Set_Rent(int rent) { this->Rent = rent; }
    void Set_Total_seats(int total) { this->total = total; }
    void Set_travle_time(int travle_time) { this->travle_time = travle_time; }
    void Set_Departure_time(int departur[])
    {
        this->Departure_time[0] = departur[0];
        this->Departure_time[1] = departur[1];
    }
    void Set_Arrival_time(int Arrival[])
    {
        this->Arrival_time[0] = Arrival[0];
        this->Arrival_time[1] = Arrival[1];
    }
};

class Schedule
{

public:
    flight F;
    void setSchedule(string flightType)
    {
        F.SetFlight(flightType);
    }
    void DisplayScedule(int sr)
    {
        F.print(sr);
    }
};

class Agency
{
    char agency_name[30];
    long int Reg_No;
    int Helpline;
    char Address[50];
    char Email[30];
    long long int PhoneNo;

public:
    Agency()
    {
        strcpy(agency_name, "Alflah Tour And Travelars");
        strcpy(Email, "Info@alflah.com");
        PhoneNo = 3426065866;
        strcpy(Address, " Mandi bhauddin");
        Helpline = 1111;
        Reg_No = 444567;
    }
    void set_agency()
    {
        cin.clear();
        cin.ignore(256, '\n');
        print_header("AGENCY DATA");
        cout << "\t\t\t Enter New Agency Name: ";
        gets(agency_name);
        cout << "\t\t\t Enter New Email :";
        gets(Email);
        cout << "\t\t\t Enter New Phone NO: ";
        cin >> PhoneNo;
        cin.ignore(256, '\n');
        cout << "\t\t\t Enter New Address :";
        gets(Address);
        cin.ignore();
        cout << "\t\t\t Enter Agency Registration No : ";
        cin >> Reg_No;
        cin.ignore(256, '\n');
        cout << "\t\t\t Enter New Helpline: ";
        cin >> Helpline;
        ofstream fout("Files/Agency/Agency.bin", ios::out | ios::binary);
        if (fout.is_open())
        {
            fout.clear();
            fout.write((char *)this, sizeof(*this));
        }
        else
        {
            cout << "\t\t\t ERROR !! File Not Found" << endl;
        }
        fout.close();
    }
    void Print_Agency()
    {
        ifstream fin("Files/Agency/Agency.bin", ios::in | ios::binary);
        if (fin.is_open())
        {
            fin.read((char *)this, sizeof(*this));
        }
        else
        {
            cout << "\t\t\t ERROR !! File Not Found" << endl;
        }
        fin.close();
        cout << "\t\t\t     " << agency_name << endl
             << endl;
        cout << "\t\t\tEmail:         " << Email << endl;
        cout << "\t\t\tHelpline #     " << Helpline << endl;
        cout << "\t\t\tPhone #        " << PhoneNo << endl;
        cout << "\t\t\tRegistration # " << Reg_No << endl;
        cout << "\t\t\tAddress :      " << Address << endl;
    }
    void Agency_Menue()
    {
        char choice;
        do
        {
            cout << "\n\t\t\t********************************\n";
            cout << "\t\t\t    WELCOME TO AGENCY MENU \n";
            cout << "\t\t\t********************************\n\n";
            cout << "\t\t\tChoose Your Desired Option " << endl;
            cout << "\t\t\t 1. Set Agency " << endl;
            cout << "\t\t\t 2. Check Agency Info. " << endl;
            cout << "\t\t\t 0. Go to Main Menu. " << endl;
            cout << "\t\t\t Enter Here :";
            choice = getche();
            switch (choice)
            {
            case '1':
                set_agency();
                break;
            case '2':
                Print_Agency();
                break;
            case '3':
                break;
            default:
                break;
            }
            system("pause");
        } while (choice != '0');
    }
    string GetAgencyName() { return this->agency_name; }
    int Get_helpline() { return this->Helpline; }
    string Get_email() { return this->Email; }
    string Get_adrres() { return this->Address; }
};

class Employee : protected Person
{
    long long int ID;
    char Designation[30];

public:
    login L;
    Employee() : Person()
    {
        ID = 0;
        strcpy(Designation, "none");
    }
    void Set_Employee()
    {

        Set_Person();
        cin.ignore(256, '\n');
        cin.clear();
        cout << "\t\t\t Please Enter Designation ";
        gets(Designation);
        while (!checkString(Designation))
        {
            cout << "\t\t\t Please Enter Valid Designation ";
            gets(Designation);
        }
        ID = Input_checkNO("ID #");
        while (ID == Phone_No)
        {
            cout << "\t\t\t Please Enter a valid ID #:";
            cin >> ID;
        }
        cin.ignore(256, '\n');
        cin.clear();
    }
    void printEmployeer(string Type)
    {
        print_header(Type);
        print_person();
        cout << "\t\t\t Desigantion:     " << Designation << endl;
        cout << "\t\t\t ID #:            " << ID << endl;
    }
    string Get_EmployeeName() { return this->Name; }
    long long int Get_EmployeeCNIC() { return this->CNIC; }
    long long int Get_EmployeeID() { return this->ID; }
    string Get_gender() { return Gender; }
    int *getDOB() { return DOB; }
    void set_name(char name[30]) { strcpy(this->Name, name); }
    void set_Fname(char Fname[30]) { strcpy(this->Father_Name, Fname); }
    void set_CNIC(long long int CNIC) { this->CNIC = CNIC; }
    void set_DOB(int a, int b, int c)
    {
        this->DOB[0] = a;
        this->DOB[1] = b;
        this->DOB[2] = c;
    }
    void set_IDNo(long long int ID) { this->ID = ID; }
    void set_PhoneNo(long long int phoneno) { this->Phone_No = phoneno; }
    void Set_Gender(string Gender) { strcpy(this->Gender, Gender.c_str()); }
    void Set_Designation(string Designation) { strcpy(this->Designation, Designation.c_str()); }
};

//Using CLASS NODE for Passenger

class Passenger_node
{
public:
    Passenger P;
    Passenger_node *link;
    Passenger_node *head = NULL, *cur = NULL, *next;
    void InsertPassenger()
    {
        if (head == NULL)
        {
            head = new Passenger_node;
            head->P.Set_passenger();
            head->link = NULL;
            cur = head;
        }

        else
        {

            InsertAtEnd();
        }
    }

    void InsertAtEnd()
    {
        char choice;
        cur = head;
        while (cur->link != NULL)
        {

            cur = cur->link;
        }

        next = new Passenger_node;
        next->P.Set_passenger();
        while (!Validate_Passport(next->P.Get_passengerPassport()))
        {

            cout << "\t\t\t Another Passenger is registered with same passport No." << endl;
            cout << "\t\t\t Enter again another passport # ";
            long long int pasport;
            pasport = Input_checkNO("Passport #");
            next->P.set_PassportNo(pasport);
        }
        cur->link = next;
        cur = next;
        next->link = NULL;
    }

    void PassengerTraversing()
    {
        int count = 0;
        if (head == NULL)
        {
            cout << "\n\t\t\t No recode found" << endl;
            return;
        }
        cur = head;
        while (cur != NULL)
        {

            count++;
            cur->P.printPassenger(count);

            cur = cur->link;
        }
    }

    Passenger_node *searchPassengerByPassport(long long int passportNo)
    {
        int count = 0;
        cur = head;
        while (cur != NULL)
        {
            if (cur->P.Get_passengerPassport() == passportNo)
            {
                count++;
                return cur;
            }
            cur = cur->link;
        }
        if (count == 0)
        {
            cout << "\t\t\t No record found." << endl;
        }
    }

    void SearchPassenger()
    {
        int count = 0;
        char choice;
        long long int passportNo;
        char temp[30];
        bool flag = false;

        if (head == NULL)
        {
            cout << "\t\t\t There is no any record" << endl;
            return;
        }
        do
        {
            cur = head;
            cout << "\t\t\t Please choose menue to search " << endl;
            cout << "\t\t\t 1 Name " << endl;
            cout << "\t\t\t 2 Passport " << endl;
            cout << "\t\t\t 0 Go back " << endl;
            cout << "\t\t\t Enter here :  " << endl;
            choice = getch();
            cout << endl;
            switch (choice)
            {
            case '1':
            {
                count = 0;
                cout << "\t\t\t Please Enter Name to search: ";
                gets(temp);
                while (!checkString(temp))
                {
                    cout << "\t\t\t Please Enter Valid Name to search: ";
                    gets(temp);
                }
                while (cur != NULL)
                {
                    if (cur->P.Get_passengerName() == temp)
                    {
                        count++;
                        cur->P.printPassenger(count);
                    }
                    cur = cur->link;
                }
                if (count == 0)
                {
                    cout << "\t\t\t No record found." << endl;
                }
                break;
            }
            case '2':
            {
                count = 0;
                passportNo = Input_checkNO("Passport No to Search");
                while (cur != NULL)
                {
                    if (cur->P.Get_passengerPassport() == passportNo)
                    {
                        count++;
                        cur->P.printPassenger(count);
                        break;
                    }
                    cur = cur->link;
                }
                if (count == 0)
                {
                    cout << "\t\t\t No record found." << endl;
                }
                break;
            }
            case '0':
                break;

            default:
                cout << "\t\t\t Invalid input try again " << endl;
                break;
            }

        } while (choice != '0');
    }

    void DeleteFirstNode()
    {
        Passenger_node *temp;
        temp = head->link;
        free(head);
        head = NULL;
        head = temp;
        cout << "\t\t\tDeleted successfully" << endl;
    }

    void DeleteEndNode()
    {
        if (head->link == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            cur = head;
            while (cur->link->link != NULL)
            {
                cur = cur->link;
            }
            free(cur->link);
            cur->link = NULL;
            cout << "\t\t\tDeleted Successfully" << endl;
        }
    }

    void DeletebyPassport(long long int passport)
    {
        cur = head;
        bool flag = false;
        Passenger_node *prev = head;
        if (head == NULL)
        {
            cout << "\t\t\t There is no data " << endl;
            return;
        }
        head->P.printPassenger(1);
        if (head->P.Get_passengerPassport() == passport)
        {
            DeleteFirstNode();
            cout << "\t\t\t Deleted succesfully" << endl;
            return;
        }
        while (cur->link != NULL)
        {
            cur = cur->link;
        }
        if (cur->P.Get_passengerPassport() == passport)
        {
            DeleteEndNode();
            cout << "\nDeleted succesfully" << endl;
            return;
        }
        cur = head;
        while (cur != NULL)
        {
            if (cur->P.Get_passengerPassport() == passport)
            {
                flag = true;
                prev->link = cur->link;
                free(cur);
                cur = NULL;
                cout << "\nDeleted succesfully" << endl;
                break;
            }
            prev = cur;
            cur = cur->link;
        }
        if (!flag)
        {
            cout << "No record matched" << endl;
            return;
        }
    }

    bool Validate_Passport(long long int passport)
    {
        if (head == NULL)
        {
            return true;
        }
        Passenger_node *cur1 = head;
        while (cur1 != NULL)
        {
            if (cur1->P.Get_passengerPassport() == passport)
            {
                return false;
            }
            cur1 = cur1->link;
        }
        return true;
    }
    void updatePassenger(long long int passportno)
    {

        char choice;
        bool flag = false;
        char Name[20];
        char Father_Name[20];
        int DOB[3];
        char Gender[7];
        long long int CNIC;
        long long int PhoneNo;
        cur = head;
        while (cur != NULL)
        {
            if (cur->P.Get_passengerPassport() == passportno)
            {
                flag = true;
                print_header("PASSENGER");
                cur->P.printPassenger(1);
                do
                {
                    print_header("INSERT NEW RECORD");
                    cout << "\t\t\tChoose menue to update" << endl;
                    cout << "\t\t\t 1.Name" << endl;
                    cout << "\t\t\t 2.Father's name" << endl;
                    cout << "\t\t\t 3.CNIC NO" << endl;
                    cout << "\t\t\t 4.DOB" << endl;
                    cout << "\t\t\t 5.Gender" << endl;
                    cout << "\t\t\t 6.Phone NO" << endl;
                    cout << "\t\t\t 7.Passport NO" << endl;
                    cout << "\t\t\t 8.Complete Record" << endl;
                    cout << "\t\t\t 0.exit menue" << endl;
                    cin.ignore();
                    cout << "\t\t\t Enter here";
                    choice = getche();
                    switch (choice)
                    {
                    case '1':
                    {
                        cout << "\t\t\t Please Enter New Name ";
                        gets(Name);
                        while (!checkString(Name))
                        {
                            cout << "\t\t\t Please Enter Valid New Name ";
                            gets(Name);
                        }
                        cur->P.set_name(Name);
                        break;
                    }
                    case '2':
                    {
                        cout << "\t\t\t Please Enter New Father Name ";
                        gets(Father_Name);
                        while (!checkString(Father_Name))
                        {
                            cout << "\t\t\t Please Enter Valid New Father Name ";
                            gets(Father_Name);
                        }
                        cur->P.set_Fname(Father_Name);
                        break;
                    }
                    case '3':
                    {
                        CNIC = Input_checkNO("CNIC #");
                        cur->P.set_CNIC(CNIC);
                        break;
                    }
                    case '4':
                    {
                        cout << "\t\t\t Please Enter new Date of Birth" << endl;
                    LOOP:
                        do
                        {
                            for (int i = 0; i < 3; i++)
                            {
                                DOB[i] = Input_checkNO("DOB (DD//MM//YY)");
                            }
                            if (DOB[0] <= 0 || DOB[0] > 31 || DOB[1] <= 0 || DOB[1] > 12 || DOB[2] <= 1915 || DOB[2] == 0 || DOB[2] >= 2020)
                            {
                                goto LOOP;
                            }
                            choice = 'n';
                        } while (choice != 'n');
                        cur->P.set_DOB(DOB[0], DOB[1], DOB[2]);
                        break;
                    }
                    case '5':
                    {
                        cout << "\t\t\t Please Enter New Gender ";
                        gets(Gender);
                        while (!checkString(Gender))
                        {
                            cout << "\t\t\t Please Enter Valid New Gender ";
                            gets(Gender);
                        }
                        cur->P.Set_Gender(Gender);
                        break;
                    }
                    case '6':
                    {
                        PhoneNo = Input_checkNO("Phone #");
                        cur->P.Set_passenger();
                        break;
                    }
                    case '7':
                    {
                        passportno = Input_checkNO("Passport #");
                        while (!Validate_Passport(passportno))
                        {
                            cout << "\t\t\t Another Passenger is registered with same passport No." << endl;
                            passportno = Input_checkNO("another Passport #");
                        }

                        cur->P.set_PassportNo(passportno);
                        break;
                    }
                    case '8':
                    {
                        cout << "\t\t\t Please Enter new Record" << endl;
                        cur->P.Set_passenger();
                        break;
                    }
                    case '0':
                    {
                        break;
                    }
                    default:
                    {
                        cout << "\t\t\t Invalid input please try again" << endl;
                        break;
                    }
                        cout << "\t\t\t Record updated" << endl;
                        print_header("NEW RECORD");
                        cur->P.printPassenger(1);
                        cout << endl;
                        cout << "\t\t\t ";
                        system("PAUSE");
                        system("CLS");
                    }

                } while (choice != '0');
                return;
            }

            cur = cur->link;
        }
        if (flag == false)
        {
            cout << "\t\t\t Record not found try again..";
            updatePassenger(passportno);
        }
    }
    void swapNodes(Passenger_node **head_ref, Passenger_node *cur1, Passenger_node *cur2, Passenger_node *prev)
    {
        *head_ref = cur2;
        prev->link = cur1;
        Passenger_node *temp = cur2->link;
        cur2->link = cur1->link;
        cur1->link = temp;
    }
    void sortbyname(Passenger_node **head_ref, char ch)
    {
        if ((*head_ref) == NULL)
            return;
        *head_ref = SelectionSortByName(*head_ref, ch);
    }
    void sortbyPassport(Passenger_node **head_ref, char ch)
    {
        if ((*head_ref) == NULL)
            return;
        *head_ref = SelectionSortByPassport(*head_ref, ch);
    }
    Passenger_node *SelectionSortByName(Passenger_node *head, char ch)
    {
        if (head->link == NULL)
            return head;
        Passenger_node *min = head;
        Passenger_node *beforeMin = NULL;
        Passenger_node *ptr;

        for (ptr = head; ptr->link != NULL; ptr = ptr->link)
        {
            if (ch == 'A')
            {
                if (ptr->link->P.Get_passengerName() < min->P.Get_passengerName())
                {
                    min = ptr->link;
                    beforeMin = ptr;
                }
            }
            if (ch == 'D')
            {
                if (ptr->link->P.Get_passengerName() > min->P.Get_passengerName())
                {
                    min = ptr->link;
                    beforeMin = ptr;
                }
            }
        }
        if (min != head)
            swapNodes(&head, head, min, beforeMin);
        head->link = SelectionSortByName(head->link, ch);

        return head;
    }
    Passenger_node *SelectionSortByPassport(Passenger_node *head, char ch)
    {
        if (head->link == NULL)
            return head;
        Passenger_node *min = head;
        Passenger_node *beforeMin = NULL;
        Passenger_node *ptr;

        for (ptr = head; ptr->link != NULL; ptr = ptr->link)
        {
            if (ch == 'A')
            {
                if (ptr->link->P.Get_passengerPassport() < min->P.Get_passengerPassport())
                {
                    min = ptr->link;
                    beforeMin = ptr;
                }
            }
            if (ch == 'D')
            {
                if (ptr->link->P.Get_passengerPassport() > min->P.Get_passengerPassport())
                {
                    min = ptr->link;
                    beforeMin = ptr;
                }
            }
        }
        if (min != head)
            swapNodes(&head, head, min, beforeMin);
        head->link = SelectionSortByPassport(head->link, ch);

        return head;
    }

    void writePassengerDatadata()
    {
        cur = head;
        ofstream fout("Files/Passengers/Passenger.bin", ios::binary);
        if (fout.is_open())
        {
            fout.clear();
            while (cur != NULL)
            {
                fout.write((char *)&(cur->P), sizeof(cur->P));
                cur = cur->link;
            }
            fout.close();
        }
        else
        {
            cout << "\t\t\t File Error!" << endl;
            cout << "\t\t\t File No found" << endl;
            return;
        }
    }

    void sortbyName(char ch)
    {
        sortbyname(&head, ch);
    }

    void sortByPassport(char ch)
    {
        sortbyPassport(&head, ch);
    }

    void ReadPassengerdata()
    {
        head = NULL;
        ifstream fin("Files/Passengers/Passenger.bin", ios::binary);

        if (fin.is_open())
        {
            if (!Is_empty(fin))
            {

                head = new Passenger_node;
                fin.read((char *)&(head->P), sizeof((head->P)));
                head->link = NULL;
                cur = head;
            }
            while (!fin.eof())
            {
                if (head != NULL)
                {
                    if (!fin.eof())
                    {
                        next = new Passenger_node;
                        if (fin.read((char *)&(next->P), sizeof((next->P))))
                        {
                            cur->link = next;
                            next->link = NULL;
                            cur = next;
                            break;
                        }
                        else
                        {
                            free(next);
                        }
                    }
                }
            }
            fin.close();
        }
        else
        {
            cout << "\t\t\t File Error!" << endl;
            cout << "\t\t\t File No found" << endl;
        }
    }
};

//Creating linked list for Schedule
class Schedule_node
{
public:
    Schedule S;
    Schedule_node *link;
    Schedule_node *head = NULL, *cur = NULL, *next = NULL;

    void InsertAtEnd(string flightype)
    {

        cur = head;
        while (cur->link != NULL)
        {

            cur = cur->link;
        }
        next = new Schedule_node;
        next->S.setSchedule(flightype);
        while (!validateFlightNo(next->S.F.Get_FlightNo()))
        {
            cout << "\t\t\t The same Flight already exists" << endl;
            cout << "\t\t\t Please Enter New Flight." << endl;
            next->S.F.SetFlight(flightype);
        }
        cur->link = next;
        cur = next;
        next->link = NULL;
    }

    void InsertScheduleNode(string flightType)
    {
        if (head == NULL)
        {
            head = new Schedule_node;
            head->S.setSchedule(flightType);

            head->link = NULL;
            cur = head;
        }
        else
        {
            InsertAtEnd(flightType);
        }
    }
    void DisplayScedule()
    {
        int count = 0;
        if (head == NULL)
        {
            cout << "\n\t\t\t No recode found" << endl;
            return;
        }
        Schedule_node *cur = head;
        cout << endl;
        cout << left << setw(7) << "**************************************************************************************************************\n";
        cout << left << setw(7) << "| Sr#" << left << setw(11) << "| Airplane" << left << setw(13) << "| Flight No" << left << setw(10) << "| Departure" << left << setw(10) << "| Destination" << left << setw(14) << "| Departure" << left << setw(13) << "| Arrival" << left << setw(10) << "| Price" << left << setw(15) << "| Type" << right << setw(3) << "|" << endl;
        cout << left << setw(7) << "**************************************************************************************************************\n";
        while (cur != NULL)
        {
            count++;
            cur->S.DisplayScedule(count);
            cur = cur->link;
        }
        cout << left << setw(7) << "**************************************************************************************************************\n";
    }
    bool SearchScedule()
    {
        cur = head;
        int count = 0;
        bool flag = false;
        char Temp_source[30];
        char Temp_Destination[30];
        if (cur == NULL)
        {
            cout << "\t\t\t There is no any record" << endl;
            return false;
        }
        cout << "\n\t\t\t Choose flight " << endl;
        cout << "\t\t\t Please Enter Departure City :";
        gets(Temp_source);
        while (!checkString(Temp_source))
        {
            cout << "\t\t\t Please Enter Valid  Departure City ";
            gets(Temp_source);
        }
        cout << "\t\t\t Please Enter Destination City :";
        gets(Temp_Destination);
        while (!checkString(Temp_Destination))
        {
            cout << "\t\t\t Please Enter Valid  Destination City ";
            gets(Temp_Destination);
        }

        cout << endl;
        cout << left << setw(7) << "*******************************************************************************************************\n";
        cout << left << setw(7) << "| Sr#" << left << setw(11) << "| Airplane" << left << setw(13) << "| Flight No" << left << setw(10) << "| Departure" << left << setw(10) << "| Destination" << left << setw(14) << "| Departure" << left << setw(13) << "| Arrival" << left << setw(10) << "| Price" << left << setw(10) << "| Type" << right << setw(3) << "|" << endl;
        cout << left << setw(7) << "*****************************************************************************************************\n";
        while (cur != NULL)
        {
            if (!strcmp(Temp_source, cur->S.F.Get_Departure().c_str()) && !strcmp(Temp_Destination, cur->S.F.Get_Destination().c_str()))
            {
                cur->S.DisplayScedule(1);
                flag = true;
                return flag;
                break;
            }
            cur = cur->link;
        }
        if (flag == false)
        {
            cout << "\t\t\t Flight not found" << endl;
            return flag;
        }
    }
    void DeleteFirstNode()
    {
        Schedule_node *temp;
        temp = head->link;
        free(head);
        head = NULL;
        head = temp;
        cout << "\t\t\tDeleted successfully" << endl;
    }
    void DeleteEndNode()
    {

        if (head->link == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            cur = head;
            while (cur->link->link != NULL)
            {
                cur = cur->link;
            }
            free(cur->link);
            cur->link = NULL;
            cout << "\t\t\tDeleted Successfully" << endl;
        }
    }
    void Deletebyflightno(string flightNO)
    {
        bool flag = false;
        if (flightNO != "none")
        {

            if (head->S.F.Get_FlightNo() == flightNO)
            {
                DeleteFirstNode();
                return;
            }
            cur = head;
            while (cur->link != NULL)
            {
                cur = cur->link;
            }
            if (cur->S.F.Get_FlightNo() == flightNO)
            {
                DeleteEndNode();
                return;
            }
            else
            {
                cur = head;
                Schedule_node *prev;
                prev = head;

                while (cur != NULL)
                {
                    if (cur->S.F.Get_FlightNo() == flightNO)
                    {
                        flag = true;

                        prev->link = cur->link;
                        free(cur);
                        cur = NULL;
                        cout << "\t\t\tDeleted Successfully" << endl;
                    }
                    prev = cur;
                    cur = cur->link;
                }
            }
        }
        if (!flag)
        {
            cout << "\t\t\t Record not found" << endl;
            return;
        }
    }
    void writeScheduleDatadata(string FileName)
    {
        cur = head;
        ofstream fout(FileName, ios::binary);
        if (fout.is_open())
        {
            fout.clear();
            while (cur != NULL)
            {
                fout.write((char *)&(cur->S.F), sizeof(cur->S.F));
                cur = cur->link;
            }
            fout.close();
        }
        else
        {
            cout << "\t\t\t File Error!" << endl;
            cout << "\t\t\t File No found" << endl;
            return;
        }
    }
    void ReadPScheduledata(string fileName)
    {
        Passenger_node *temp = NULL;
        head = NULL;
        ifstream fin(fileName, ios::binary);

        if (fin.is_open())
        {
            if (!Is_empty(fin))
            {

                head = new Schedule_node;
                fin.read((char *)&(head->S.F), sizeof((head->S.F)));
                head->link = NULL;
                cur = head;
            }
            while (!fin.eof())
            {
                if (head != NULL)
                {
                    if (!fin.eof())
                    {
                        next = new Schedule_node;
                        if (fin.read((char *)&(next->S.F), sizeof((next->S.F))))
                        {
                            cur->link = next;
                            next->link = NULL;
                            cur = next;
                            break;
                        }
                        else
                            (free(next));
                    }
                }
            }
            fin.close();
        }
        else
        {
            cout << "File Error!" << endl;
            cout << "File No found" << endl;
        }
    }
    void Update_Schedule(string type)
    {
        char choice;
        bool flag = false;
        char Plane_Name[20];
        char flight_no[20];
        char Flight_type[20];
        int Arrival_time[2];
        int Departure_time[2];
        char Departure[20];
        char Destination[20];
        int Rent;
        int total;
        cout << "\t\t\t Please Enter Flight No: ";
        gets(flight_no);
        while (!checkFlightNo(flight_no))
        {
            cout << "\t\t\t Please Enter Valid Flight No: ";
            gets(flight_no);
        }
        cur = head;
        cur->S.F.print(1);
        while (cur != NULL)
        {
            if (cur->S.F.Get_FlightNo() == flight_no)
            {
                flag = true;
                do
                {
                    cout << "\t\t\tChoose menue to update" << endl;
                    cout << "\t\t\t 1.Plane Name" << endl;
                    cout << "\t\t\t 2.Flight No" << endl;
                    cout << "\t\t\t 3.Departure City" << endl;
                    cout << "\t\t\t 4.Arrival City" << endl;
                    cout << "\t\t\t 5.Departure Time" << endl;
                    cout << "\t\t\t 6.Arrival Time" << endl;
                    cout << "\t\t\t 7.Rent" << endl;
                    cout << "\t\t\t 8.No of Seats" << endl;
                    cout << "\t\t\t 9.Full Record" << endl;
                    cout << "\t\t\t 0.exit menue" << endl;
                    cin.ignore();
                    cout << "\t\t\t Enter here : ";
                    choice = getche();
                    switch (choice)
                    {
                    case '1':
                    {

                        cout << "\t\t\t Please Enter New Plane Name ";
                        gets(Plane_Name);
                        while (!checkString(Plane_Name))
                        {
                            cout << "\t\t\t Please Enter Valid New Plane Name ";
                            gets(Plane_Name);
                        }
                        cur->S.F.Set_PlaneName(Plane_Name);
                        cout << "\n\t\t\t Plane Name updated Successfully" << endl;
                        break;
                    }
                    case '2':
                    {
                    LOOP1:
                    {
                        cout << "\t\t\t Enter new Flight No ";
                        gets(flight_no);
                        while (!checkFlightNo(flight_no))
                        {
                            cout << "\t\t\t Enter Valid new Flight NO ";
                            gets(flight_no);
                        }
                        while (!validateFlightNo(flight_no))
                        {
                            cout << "\t\t\t The same Flight already exists" << endl;
                            cout << "\t\t\t Please Enter another Flight." << endl;
                            goto LOOP1;
                        }
                    }
                        cur->S.F.Set_flightNo(flight_no);
                        cout << "\n\t\t\t Flight No updated Successfully" << endl;
                        break;
                    }
                    case '3':
                    {
                        cout << "\t\t\t Please Enter New Departure City ";
                        gets(Departure);
                        while (!checkString(Departure))
                        {
                            cout << "\t\t\t Please Enter Valid New Departure City ";
                            gets(Departure);
                        }
                        cur->S.F.Set_Departure(Departure);
                        cout << "\n\t\t\t Departure city updated Successfully" << endl;
                        break;
                    }
                    case '4':
                    {
                        cout << "\t\t\t Please Enter New Destination City ";
                        gets(Destination);
                        while (!checkString(Destination))
                        {
                            cout << "\t\t\t Please Enter Valid New Destination City ";
                            gets(Destination);
                        }
                        cur->S.F.Set_Destination(Destination);
                        cout << "\n\t\t\t Destination city updated Successfully" << endl;
                        break;
                    }
                    case '5':
                    {
                        for (int i = 0; i < 2; i++)
                        {
                            Departure_time[i] = Input_checkNO("New Departure Time.");
                        }
                        cur->S.F.Set_Departure_time(Departure_time);
                        break;
                    }
                    case '6':
                    {
                        for (int i = 0; i < 2; i++)
                        {
                            Arrival_time[i] = Input_checkNO("New Arrival Time.");
                        }
                        while (!compareTime(Departure_time, Arrival_time))
                        {
                            cout << "\t\t\t Enter Valid New Arrival Time HH:MM : ";
                            for (int i = 0; i < 2; i++)
                            {
                                cin >> Departure_time[i];
                            }
                        }
                        cur->S.F.Set_Arrival_time(Arrival_time);
                        cur->S.F.Set_travle_time((cur->S.F.Get_Departure_time()) - (cur->S.F.Get_Arrival_time()));
                        break;
                    }
                    case '7':
                    {
                        Rent = Input_checkNO("New Rent");
                        cur->S.F.Set_Rent(Rent);
                        break;
                    }
                    case '8':
                    {
                        total = Input_checkNO("New Total Seats");
                        cur->S.F.Set_Total_seats(total);
                        break;
                    }
                    case '9':
                    {
                        cur->S.F.SetFlight(type);
                        break;
                    }
                    case '0':
                        break;

                    default:
                        cout << "\t\t\t invalid input try again" << endl;
                        break;
                    }
                } while (choice != '0');
            }
            cur = cur->link;
        }
        if (!flag)
        {
            cout << "No record Found";
        }
    }
    void swapNodes(Schedule_node **head_ref, Schedule_node *cur1, Schedule_node *cur2, Schedule_node *prev)
    {
        *head_ref = cur2;
        prev->link = cur1;
        Schedule_node *temp = cur2->link;
        cur2->link = cur1->link;
        cur1->link = temp;
    }
    Schedule_node *SelectionSortByDeparture(Schedule_node *head, char ch)
    {
        if (head->link == NULL)
            return head;
        Schedule_node *min = head;
        Schedule_node *beforeMin = NULL;
        Schedule_node *ptr;

        for (ptr = head; ptr->link != NULL; ptr = ptr->link)
        {
            if (ch == 'A')
            {
                if (ptr->link->S.F.Get_Departure() < min->S.F.Get_Departure())
                {
                    min = ptr->link;
                    beforeMin = ptr;
                }
            }
            if (ch == 'D')
            {
                if (ptr->link->S.F.Get_Departure() > min->S.F.Get_Departure())
                {
                    min = ptr->link;
                    beforeMin = ptr;
                }
            }
        }
        if (min != head)
            swapNodes(&head, head, min, beforeMin);
        head->link = SelectionSortByDeparture(head->link, ch);

        return head;
    }
    void sortbyDeparture(Schedule_node **head_ref, char ch)
    {
        if ((*head_ref) == NULL)
            return;
        *head_ref = SelectionSortByDeparture(*head_ref, ch);
    }
    void sortbyDepature_func(char ch)
    {
        sortbyDeparture(&head, ch);
    }
    bool validateFlightNo(string FlightNO)
    {
        if (head == NULL)
        {
            return true;
        }
        Schedule_node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->S.F.Get_FlightNo() == FlightNO)
            {
                return false;
            }
            ptr = ptr->link;
        }
        return true;
    }
};
//Scdeule_mangemen Mneue
void Schedule_menue(Schedule_node Dom, Schedule_node Int)
{
    char choice;
    Int.ReadPScheduledata("Files/Schedules/International.bin");
    Dom.ReadPScheduledata("Files/Schedules/Domestic.bin");
    string temp;
    do
    {
        system("cls");
        print_header("SCHEDULE MENU");
        cout << "\n\t\t\t Choose Menue." << endl;
        cout << "\t\t\t1. Add International Schedule." << endl;
        cout << "\t\t\t2. Add Domestic Scedule." << endl;
        cout << "\t\t\t3. List International Scedule." << endl;
        cout << "\t\t\t4. List Domestic Schedule." << endl;
        cout << "\t\t\t5. Delete Domestic Schedule." << endl;
        cout << "\t\t\t6. Delete International Scedule." << endl;
        cout << "\t\t\t7. Update Domestic Schedule." << endl;
        cout << "\t\t\t8. Update InterNational Schedule." << endl;
        cout << "\t\t\t0. Go to Back." << endl;
        cout << "\n\t\t\t Enter Here : ";
        choice = getche();
        cout << endl;
        switch (choice)
        {
        case '1':
        {
            Int.InsertScheduleNode("International");

            break;
        }
        case '2':
        {
            Dom.InsertScheduleNode("Domestic");
            break;
        }
        case '3':
        {
            Int.DisplayScedule();
            break;
        }
        case '4':
        {
            Dom.DisplayScedule();
            break;
        }
        case '5':
        {

            Dom.DisplayScedule();
            cout << "\n\t\t\t Enter Flight No to delete" << endl;
            getline(cin, temp);
            while (!checkFlightNo(temp))
            {
                cout << "\n\t\t\t Enter Valid Flight No to delete" << endl;
                getline(cin, temp);
            }
            Dom.Deletebyflightno(temp);
            break;
        }
        case '6':
        {
            Int.DisplayScedule();
            cout << "\n\t\t\t Enter Flight No to delete" << endl;
            getline(cin, temp);
            while (!checkFlightNo(temp))
            {
                cout << "\n\t\t\t Enter Valid Flight No to delete" << endl;
                getline(cin, temp);
            }
            Int.Deletebyflightno(temp);
            break;
        }
        case '7':
        {
            Dom.DisplayScedule();
            Dom.Update_Schedule("Domestic");
            break;
        }
        case '8':
        {
            Int.DisplayScedule();
            Int.Update_Schedule("International");
            break;
        }
        case '0':
        {
            break;
        }
        default:
            cout << "\n\t\t\tInavalid Input" << endl;
            break;
        }
        cout << "\n\t\t\t Press Enter to Continue.";
        getch();

    } while (choice != '0');

    Dom.writeScheduleDatadata("Files/Schedules/Domestic.bin");
    Int.writeScheduleDatadata("Files/Schedules/International.bin");
}
//Login class Node
class Login_node
{
public:
    login Log;
    Login_node *link;
    Login_node *cur = NULL, *head = NULL, *next = NULL;

    void InsertLogin(long long pass, int DOB[])
    {
        cur = head;
        if (head == NULL)
        {
            head = new Login_node;
            head->Log.SetLogin(pass, DOB);
            head->link = NULL;
            cur = head;
        }
        else
        {
            InsertAtEnd(pass, DOB);
        }
    }

    void InsertAtEnd(long long pass, int DOB[])
    {
        cur = head;
        while (cur->link != NULL)
        {

            cur = cur->link;
        }
        next = new Login_node;
        cur->link = next;
        next->Log.SetLogin(pass, DOB);
        cur = next;
        next->link = NULL;
    }

    void DeleteFirstNode()
    {
        Login_node *temp;
        temp = head->link;
        free(head);
        head = NULL;
        head = temp;
        cout << "\t\t\tDeleted successfully" << endl;
    }

    void Reset_login()
    {
        long long int username;
        int DOB[3];
        char choice;
        bool flag = false;
        username = Input_checkNO("User Name");
        cur = head;
        while (cur != NULL)
        {
            if (cur->Log.GetUsername() == username)
            {
                flag = true;
            LOOP:
            {
                cout << " \t\t\t To reset provide following information" << endl;
                cout << " \t\t\t Enter Date Of Birth (DD // MM // YY) : " << endl;
                ;
                for (int i = 0; i < 3; i++)
                {
                    DOB[i] = Input_checkNO("DOB");
                }
                for (int i = 0; i < 3; i++)
                {
                    if (!(cur->Log.get_DOB()[i] == DOB[i]))
                    {
                        cout << "\t\t\t DOB didn't match  " << endl;
                        cout << "\t\t\t Do you want to retry (Press \"y\") or Go to back (Press \"n\").";
                        choice = getche();
                        if (choice != 'y' || choice != 'Y')
                        {
                            return;
                        }
                        else
                        {
                            goto LOOP;
                        }
                    }
                }
            }
                cur->Log.reset_password();
                cout << "\n\t\t Your Password has been Updated" << endl;
                cout << "\n\t\t Your New Login is " << endl;
                cur->Log.Print_Login();
            }
            cur = cur->link;
        }
        if (flag == false)
        {
            cout << "\t\t\t Wrong Username. Try again" << endl;
        }
    }

    void DeleteLogin(long long int No)
    {
        cur = head;
        bool flag = false;
        Login_node *prev = head;
        if (head == NULL)
        {
            cout << "There is no data " << endl;
            return;
        }
        if (head->Log.GetUsername() == No)
        {
            DeleteFirstNode();
            cout << "Deleted succesfully" << endl;
            return;
        }
        cur = head;
        while (cur != NULL)
        {

            if (cur->Log.GetUsername() == No)
            {
                flag = true;
                prev->link = cur->link;
                free(cur);
                cur = NULL;
                cout << "\nDeleted succesfully" << endl;
                break;
            }
            prev = cur;
            cur = cur->link;
        }
        if (!flag)
        {
            cout << "No record matched" << endl;
            return;
        }
    }

    void list_Logins()
    {
        cur = head;
        if (head == NULL)
        {
            cout << "No record Found" << endl;
            return;
        }
        while (cur != NULL)
        {
            cur->Log.Print_Login();
            cur = cur->link;
        }
    }

    void writeLoginDatadata(string filename)
    {
        cur = head;
        ofstream fout(filename, ios::binary);
        if (fout.is_open())
        {
            fout.clear();
            while (cur != NULL)
            {
                fout.write((char *)&(cur->Log), sizeof(cur->Log));
                cur = cur->link;
            }
            fout.close();
        }
        else
        {
            cout << "File Error!" << endl;
            cout << "File No found" << endl;
            return;
        }
    }

    void ReadLogingerdata(string Filename)
    {
        Schedule_node *temp = NULL;
        head = NULL;
        ifstream fin(Filename, ios::binary);

        if (fin.is_open())
        {
            if (!Is_empty(fin))
            {
                head = new Login_node;
                fin.read((char *)&(head->Log), sizeof((head->Log)));
                head->link = NULL;
                cur = head;
            }
            while (!fin.eof())
            {
                if (head != NULL)
                {
                    if (!fin.eof())
                    {
                        next = new Login_node;
                        if (fin.read((char *)&(next->Log), sizeof((next->Log))))
                        {
                            cur->link = next;
                            next->link = NULL;
                            cur = next;
                            break;
                        }
                        else
                            (free(next));
                    }
                }
            }
            fin.close();
        }
        else
        {
            system("Pause");
            cout << "File Error!" << endl;
            cout << "File No found" << endl;
        }
    }

    bool Check_Login(long long int temp, long long int Temp_password)
    {

        cur = head;
        while (cur != NULL)
        {
            if (cur->Log.GetUsername() == temp && cur->Log.Get_Password() == Temp_password)
            {
                return true;
            }
            cur = cur->link;
        }
        return false;
    }
};

class Employee_node
{
public:
    Employee E;
    Employee_node *link;

    Employee_node *head = NULL, *cur = NULL, *next;
    void InsertEmployee()
    {

        if (head == NULL)
        {
            head = new Employee_node;
            head->E.Set_Employee();
            head->link = NULL;
            cur = head;
        }
        else
        {
            InsertAtEnd();
        }
    }

    void InsertAtEnd()
    {
        cur = head;
        while (cur->link != NULL)
        {

            cur = cur->link;
        }
        next = new Employee_node;
        cur->link = next;
        next->E.Set_Employee();
        cur = next;
        next->link = NULL;
    }

    void EmployeeTraversing()
    {
        int count = 0;
        if (head == NULL)
        {
            cout << "\n\t\t\t No recode found" << endl;
            return;
        }
        cur = head;
        while (cur != NULL)
        {

            count++;
            cur->E.printEmployeer("Employee");

            cur = cur->link;
        }
    }

    void SearchEmployee()
    {
        int count = 0;
        char choice;
        long long int IDNo;
        char temp[30];
        bool flag = false;

        if (head == NULL)
        {
            cout << "\t\t\t There is no any record" << endl;
            return;
        }
        do
        {
            cin.ignore(256, '\n');
            cin.clear();
            cur = head;
            cout << "\t\t\t Please choose menue to search " << endl;
            cout << "\t\t\t 1 Name " << endl;
            cout << "\t\t\t 2 ID\t " << endl;
            cout << "\t\t\t 0 Go back " << endl;
            cout << "\t\t\t Enter here :  " << endl;
            choice = getch();
            switch (choice)
            {
            case '1':
            {
                count = 0;
                cout << "\t\t\t Please Enter  Name ";
                gets(temp);
                while (!checkString(temp))
                {
                    cout << "\t\t\t Please Enter Valid Name ";
                    gets(temp);
                }
                while (cur != NULL)
                {
                    if (!strcmp(cur->E.Get_EmployeeName().c_str(), temp))
                    {
                        count++;
                        cur->E.printEmployeer("Employee");
                    }
                    cur = cur->link;
                }
                if (count == 0)
                {
                    cout << "\t\t\t No record found." << endl;
                }
                break;
            }
            case '2':
            {
                count = 0;
                IDNo = Input_checkNO("ID #");
                cur = head;
                while (cur != NULL)
                {
                    if (cur->E.Get_EmployeeID() == IDNo)
                    {
                        count++;
                        cur->E.printEmployeer("Employee");
                        break;
                    }
                    cur = cur->link;
                }
                if (count == 0)
                {
                    cout << "\t\t\t No record found." << endl;
                }
                break;
            }
            case '0':
                break;

            default:
                cout << "\t\t\t Invalid input try again " << endl;
                break;
            }

        } while (choice != '0');
    }

    void DeleteFirstNode()
    {
        Employee_node *temp;
        temp = head->link;
        free(head);
        head = NULL;
        head = temp;
        cout << "\t\t\tDeleted successfully" << endl;
    }

    void DeleteEndNode()
    {
        if (head->link == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            cur = head;
            while (cur->link->link != NULL)
            {
                cur = cur->link;
            }
            free(cur->link);
            cur->link = NULL;
            cout << "\t\t\tDeleted Successfully" << endl;
        }
    }

    void DeletebyID(int ID)
    {
        cur = head;
        bool flag = false;
        Employee_node *prev = head;
        if (head == NULL)
        {
            cout << "\t\t\t There is no data " << endl;
            return;
        }
        if (head->E.Get_EmployeeID() == ID)
        {
            DeleteFirstNode();
            cout << "\t\t\t Deleted succesfully" << endl;
            return;
        }
        while (cur->link != NULL)
        {
            cur = cur->link;
        }
        if (cur->E.Get_EmployeeID() == ID)
        {
            DeleteEndNode();
            cout << "\n\t\t\t Deleted succesfully" << endl;
            return;
        }
        cur = head;
        while (cur != NULL)
        {

            if (cur->E.Get_EmployeeID() == ID)
            {
                flag = true;
                prev->link = cur->link;
                free(cur);
                cur = NULL;
                cout << "\n\t\t\t Deleted succesfully" << endl;
                break;
            }
            prev = cur;
            cur = cur->link;
        }
        if (!flag)
        {
            cout << "\t\t\t No record matched" << endl;
            return;
        }
    }

    void updateEmployee()
    {
        long long int ID;
        char choice;
        bool flag = false;
        char Name[20];
        char Father_Name[20];
        int DOB[3];
        char Gender[7];
        long long int CNIC;
        long long int PhoneNo;
        ID = Input_checkNO("ID #");
        cur = head;
        while (cur != NULL)
        {
            if (cur->E.Get_EmployeeID() == ID)
            {
                flag = true;
                cur->E.printEmployeer("Employee");
                do
                {
                    cout << "\t\t\tChoose menue to update" << endl;
                    cout << "\t\t\t1.Name" << endl;
                    cout << "\t\t\t2.Father's name" << endl;
                    cout << "\t\t\t3.CNIC NO" << endl;
                    cout << "\t\t\t4.DOB" << endl;
                    cout << "\t\t\t5.Gender" << endl;
                    cout << "\t\t\t6.Phone NO" << endl;
                    cout << "\t\t\t7.ID NO" << endl;
                    cout << "\t\t\t8.Complete Record" << endl;
                    cout << "\t\t\t0.exit menue" << endl;
                    cin.ignore();
                    cout << "\t\t\t Enter here";
                    choice = getche();
                    switch (choice)
                    {
                    case '1':
                    {
                        cout << "\t\t\t Please Enter New Name ";
                        gets(Name);
                        while (!checkString(Name))
                        {
                            cout << "\t\t\t Please Enter Valid New Name ";
                            gets(Name);
                        }
                        cur->E.set_name(Name);
                        break;
                    }
                    case '2':
                    {
                        cout << "\t\t\t Please Enter New Father Name ";
                        gets(Father_Name);
                        while (!checkString(Father_Name))
                        {
                            cout << "\t\t\t Please Enter Valid New Father Name ";
                            gets(Father_Name);
                        }

                        cur->E.set_Fname(Father_Name);
                        break;
                    }
                    case '3':
                    {
                        CNIC = Input_checkNO("New CNIC #");
                        cur->E.set_CNIC(CNIC);
                        break;
                    }
                    case '4':
                    {

                    LOOP:
                        do
                        {
                            for (int i = 0; i < 3; i++)
                            {
                                DOB[i] = Input_checkNO("Date of Birth #");
                                ;
                            }
                            if (DOB[0] <= 0 || DOB[0] > 31 || DOB[1] <= 0 || DOB[1] > 12 || DOB[2] <= 1915 || DOB[2] == 0 || DOB[2] >= 2020)
                            {
                                goto LOOP;
                            }
                            choice = 'n';
                        } while (choice != 'n');
                        cur->E.set_DOB(DOB[0], DOB[1], DOB[2]);
                        break;
                    }
                    case '5':
                    {
                        cout << "\t\t\t Please Enter New Gender ";
                        gets(Gender);
                        while (!checkString(Gender))
                        {
                            cout << "\t\t\t Please Enter Valid New Gender ";
                            gets(Gender);
                        }

                        cur->E.Set_Gender(Gender);
                        break;
                    }
                    case '6':
                    {
                        PhoneNo = Input_checkNO("New Phone #");
                        cur->E.Set_Employee();
                        break;
                    }
                    case '7':
                    {
                        ID == Input_checkNO("New ID #");
                        cur->E.set_IDNo(ID);
                        break;
                    }
                    case '8':
                    {
                        cout << "\t\t\t Please Enter new Record\n"
                             << endl;
                        cur->E.Set_Employee();
                        break;
                    }
                    case '0':
                    {
                        break;
                    }
                    default:
                    {
                        cout << "\t\t\t Invalid input please try again" << endl;
                        break;
                    }
                        cout << "\t\t\t Record updated" << endl;
                        ;
                        cout << "\t\t\t New record is :" << endl;
                        cur->E.printEmployeer("Employee");
                        cout << endl;
                        system("PAUSE");
                        system("CLS");
                    }

                } while (choice != '0');
                cur = cur->link;
            }
            if (flag == false)
            {
                cout << "\t\t\t Record not found try again..";
                updateEmployee();
            }
        }
        while (choice != '0')
            ;
    }

    void writeEmployeeDatadata(string Filename)
    {
        cur = head;
        ofstream fout(Filename, ios::binary);
        if (fout.is_open())
        {
            fout.clear();
            while (cur != NULL)
            {
                fout.write((char *)&(cur->E), sizeof(cur->E));
                cur = cur->link;
            }
            fout.close();
        }
        else
        {
            cout << "\t\t\t File No found" << endl;
            return;
        }
    }

    void ReadEmployeedata(string FileName)
    {
        Employee_node *temp = NULL;
        head = NULL;
        ifstream fin(FileName, ios::binary);

        if (fin.is_open())
        {
            if (!Is_empty(fin))
            {
                head = new Employee_node;
                fin.read((char *)&(head->E), sizeof((head->E)));
                head->link = NULL;
                cur = head;
                while (!fin.eof())
                {
                    if (head != NULL)
                    {
                        if (!fin.eof())
                        {
                            next = new Employee_node;
                            if (fin.read((char *)&(next->E), sizeof((next->E))))
                            {
                                cur->link = next;
                                next->link = NULL;
                                cur = next;
                                break;
                            }
                            else
                                (free(next));
                        }
                    }
                }
                fin.close();
            }
        }
        else
        {
            cout << "\t\t\t File Error!" << endl;
            cout << "\t\t\t File No found" << endl;
        }
    }
};

void Passenger_Menue(Passenger_node P)
{
    char choice;
    do
    {
        system("cls");
        print_header("PASSENGER MENUE");
        cout << "\n\t\t\t Choose Menu\n\t\t\t 1.List Passenger.\n\t\t\t 2.Search Passenger.\n\t\t\t 3. Sort Passengers\n\t\t\t 0. Go to back." << endl;
        cout << "\n\t\t\t Enter Here: ";
        choice = getche();
        cout << endl;
        switch (choice)
        {
        case '1':
            P.PassengerTraversing();
            break;
        case '2':
            P.SearchPassenger();
            break;
        case '3':
            do
            {
                print_header("SORT MENUE");
                cout << "\n\t\t\t Choose Menu\n\t\t\t 1.Sort by Name .\n\t\t\t 2.Sort By passport No.\n\t\t\t 0. Go to back." << endl;
                choice = getche();
                cout << endl;
                switch (choice)
                {
                case '1':
                    do
                    {
                        print_header("SORT TYPE");
                        cout << "\n\t\t\t Choose Menu\n\t\t\t 1.Asscending Order .\n\t\t\t 2.Desscending Order.\n\t\t\t 0. Go to back." << endl;
                        choice = getche();
                        cout << endl;
                        switch (choice)
                        {
                        case '1':
                            print_header("BEFORE SORTING");
                            P.PassengerTraversing();
                            print_header("AFTER SORTING");
                            P.sortbyName('A');
                            P.PassengerTraversing();
                            break;
                        case '2':
                            print_header("BEFORE SORTING");
                            P.PassengerTraversing();
                            print_header("AFTER SORTING");
                            P.sortbyName('D');
                            P.PassengerTraversing();
                            break;
                        case '3':
                            break;

                        default:
                            cout << "\t\t\t Invalide input try aagin" << endl;
                            break;
                        }
                        cout << "\t\t\t ";
                        getch();
                        system("cls");
                    } while (choice != '0');
                    break;
                case '2':
                    do
                    {
                        print_header("SORT TYPE");
                        cout << "\n\t\t\t Choose Menu\n\t\t\t 1.Asscending Order .\n\t\t\t 2.Desscending Order.\n\t\t\t 0. Go to back." << endl;
                        choice = getche();
                        cout << endl;
                        switch (choice)
                        {
                        case '1':
                            print_header("BEFORE SORTING");
                            P.PassengerTraversing();
                            print_header("AFTER SORTING");
                            P.sortByPassport('A');
                            P.PassengerTraversing();
                            break;
                        case '2':
                            print_header("BEFORE SORTING");
                            P.PassengerTraversing();
                            print_header("AFTER SORTING");
                            P.sortByPassport('D');
                            P.PassengerTraversing();
                            break;
                        case '3':
                            break;

                        default:
                            cout << "\t\t\t Invalide input try aagin" << endl;
                            break;
                        }
                        cout << "\t\t\t ";
                        getch();
                        system("cls");
                    } while (choice != '0');
                    break;
                case '0':

                    break;

                default:
                    cout << "\t\t\t Invalide input try aagin" << endl;
                    break;
                }
                cout << "\t\t\t ";
                getch();
                system("cls");
            } while (choice != '0');
            break;
        case '0':
            break;
        default:
            cout << "\n\t\t\t Invalid input" << endl;
            break;
        }
        cout << "\n\t\t\t";
        getch();
        system("cls");
    } while (choice != '0');
}

class Ticket
{
    int Tiket_no;
    char PassengerName[20];
    long long int PassengerCNIC;
    long long Passport;
    char Plane_Name[20];
    char flight_no[20];
    char source[20];
    char Destination[20];
    char Gender[7];
    char Travel_Type[20];
    char date_time[20];
    int Rent;
    int hr, min, sec, y, m, d;
    int seatNO;
    char seat_type[15];

public:
    Ticket()
    {
        strcpy(PassengerName, "None");
        Passport = 0;
        strcpy(Plane_Name, "None");
        strcpy(flight_no, "None");
        strcpy(Gender, "None");
        strcpy(source, "None");
        strcpy(Destination, "None");
        PassengerCNIC = 0;
        strcpy(Travel_Type, "None");
        strcpy(date_time, "None");
        strcpy(seat_type, "None");
        Tiket_no = 0;
        seatNO = 0;
        Rent = 0;
        hr = min = sec = 0;
        y = m = d = 0;
    }
    void CopySceduleData(Schedule S, Seat seat)
    {
        strcpy(Plane_Name, S.F.Get_PlaneName().c_str());
        strcpy(flight_no, S.F.Get_FlightNo().c_str());
        strcpy(source, S.F.Get_Departure().c_str());
        strcpy(Destination, S.F.Get_Destination().c_str());
        strcpy(Travel_Type, S.F.Get_travel_type().c_str());
        Rent = S.F.Get_rent() + seat.Get_tax();
        seatNO = seat.Get_seat_no();
    }
    void CopyPassengerdata(Passenger P, Seat seat)
    {
        strcpy(PassengerName, P.Get_passengerName().c_str());
        Passport = P.Get_passengerPassport();
        PassengerCNIC = P.Get_passengerCNIC();
        strcpy(seat_type, seat.Get_seat_type().c_str());
        strcpy(Gender, P.Get_gender().c_str());
    }
    void print_bill(Schedule_node S, Agency A, Date_time Dt, Seat seat)
    {
        cout << "\n\n\t\t\t************************************\n";
        cout << "\t\t\t*             BILL                 *\n";
        cout << "\t\t\t************************************\n";
        cout << "\t\t\t*     " << A.GetAgencyName() << "    *\n"
             << endl;
        cout << "\t\t\t*  ";
        Dt.Print_Date();
        cout << "              ";
        Dt.Print_time();
        cout << "  *" << endl;
        cout << "\n\t\t\t*     Name :            " << left << setw(11) << PassengerName << "*" << endl;
        cout << "\t\t\t*     Passport#:        " << left << setw(11) << Passport << "*" << endl;
        cout << "\t\t\t*     Class :           " << left << setw(11) << seat_type << "*" << endl;
        cout << "\t\t\t*     Seat # :          " << left << setw(11) << seatNO << "*" << endl;
        cout << "\t\t\t*     class tax :       " << left << setw(11) << seat.Get_tax() << "*" << endl;
        cout << "\t\t\t*     ticket price :    " << left << setw(11) << S.cur->S.F.Get_rent() << "*" << endl;
        cout << "\n\t\t\t************************************\n";
        cout << "\t\t\t*  Total                  " << seat.Get_tax() + S.cur->S.F.Get_rent() << " Rs *" << endl;
        cout << "\t\t\t************************************\n";
        cout << "\t\t\t*\tFor any Query              *" << endl;
        cout << "\t\t\t* Contact us at:                   *" << endl;
        cout << "\n\t\t\t* Helpline #            " << left << setw(11) << A.Get_helpline() << "*";
        cout << "\n\t\t\t* Email :        " << left << setw(18) << A.Get_email() << "*";
        cout << "\n\t\t\t* Address :     " << A.Get_adrres() << "    *";
        cout << "\n\t\t\t************************************\n";
    }
    void Print_ticket()
    {
        cout << "\n\t\t\t****************************" << endl;
        cout << "\t\t\t       Ticket# " << Tiket_no << endl;
        cout << "\t\t\t****************************\n"
             << endl;
        cout << "\t\t\t Name :          " << PassengerName << endl;
        cout << "\t\t\t CNIC #          " << PassengerCNIC << endl;
        cout << "\t\t\t Gender :        " << Gender << endl;
        cout << "\t\t\t Passport#       " << Passport << endl;
        cout << "\t\t\t Plane :         " << Plane_Name << endl;
        cout << "\t\t\t Flight #        " << flight_no << endl;
        cout << "\t\t\t Seat #          " << seatNO << endl;
        cout << "\t\t\t Class :         " << seat_type << endl;
        cout << "\t\t\t Source :        " << source << endl;
        cout << "\t\t\t Destination :   " << Destination << endl;
        cout << "\t\t\t Travel :        " << Travel_Type << endl;
        cout << "\t\t\t Time :          " << hr << ":" << min << ":" << sec << endl;
        cout << "\t\t\t Date :          " << d << "/" << m + 1 << "/" << y + 1900 << endl;
        cout << "\n\t\t\t****************************" << endl;
    }
    void copy_date_time(Date_time Dt)
    {
        hr = Dt.Get_Hourse();
        min = Dt.Get_minutes();
        sec = Dt.Get_Seconds();
        y = Dt.Get_year();
        m = Dt.Get_Month();
        d = Dt.Get_Day();
    }
    void pay_bill()
    {
        cout << "\n\t\t\t Its Time to pay Bill " << endl;
        cout << "\n\t\t\t " << getch();
        char choice;
        long int creditNumber;
        char password[20];
        print_header("PAY BILL");
        cout << "\n\t\t\tChoose Your Payment Method" << endl;
        cout << "\n\t\t\t1. Cash\n\t\t\t2. Credit Card." << endl;
        cout << "\n\t\t\t Enter Here : ";
        choice = getch();
        cout << "\n";
        switch (choice)
        {
        case '1':
            cout << "\t\t\t Payment Successfull" << endl;
            break;
        case '2':
            cout << "\t\t\t Enter Card number: ";
            cin >> creditNumber;
            cin.ignore();
            cout << "\t\t\t Enter Password :   ";
            gets(password);
            cout << "\t\t\t Payment Successfull" << endl;
            break;
        default:
            cout << "\n\t\t\t Invlaid input" << endl;
            break;
        }
        cout << "\n\t\t\t ";
        getch();
    }
    void Book_ticket(Passenger_node Pas, Passenger passeng, Agency A, Date_time Dt, Seat seat, Schedule_node Dom, Schedule_node Int)
    {
        char choice1;
        Schedule_node temp;

        do
        {
            print_header("TICKET BOOKING MENUE");
            cout << "\t\t\t Please Choose Menue :" << endl;
            cout << "\t\t\t 1. Domestic Traveling.\n\t\t\t 2. International Traveling.\n\t\t\t 0. Go to Back." << endl;
            cout << "\t\t\t Enter Here :";
            choice1 = getche();
            cout << "\n\n";
            switch (choice1)
            {
            case '1':
            {
                temp = Dom;
                char choice2;
                Dom.DisplayScedule();
                cout << "\t\t\t ";
                getch();
                cout << "Do you want to Sort Schedule?(y/n) : ";
                choice1 = getche();
                cout << endl;
                if (choice1 == 'y' || choice1 == 'Y')
                {
                    do
                    {

                        print_header("SORT TYPE");
                        cout << "\n\t\t\t Choose Menu\n\t\t\t 1.Asscending Order .\n\t\t\t 2.Desscending Order.\n\t\t\t 0. Go to back." << endl;
                        choice2 = getche();
                        cout << endl;
                        switch (choice2)
                        {
                        case '1':
                            print_header("BEFORE SORTING");
                            temp.DisplayScedule();
                            cout << "\t\t\t ";
                            getch();
                            print_header("AFTER SORTING");
                            temp.sortbyDepature_func('A');
                            temp.DisplayScedule();
                            break;
                        case '2':
                            print_header("BEFORE SORTING");
                            temp.DisplayScedule();
                            cout << "\t\t\t ";
                            getch();
                            print_header("AFTER SORTING");
                            temp.sortbyDepature_func('D');
                            temp.DisplayScedule();
                            break;
                        case '0':
                            break;

                        default:
                            cout << "\t\t\t Invalide input try aagin" << endl;
                            break;
                        }
                        cout << "\t\t\t ";
                        getch();
                        system("cls");
                    } while (choice2 != '0');
                }
            LOOP1:
            {
                system("cls");
                Dom.DisplayScedule();
                if (Dom.SearchScedule())
                {
                    cout << "\t\t\t ";
                    getch();
                    CopySceduleData(Dom.cur->S, seat);

                    Tiket_no = (rand() % 300 + 1);
                    seat.Set_seat();
                    CopyPassengerdata(Pas.cur->P, seat);
                    copy_date_time(Dt);
                    cout << "\n\t\t\t Your Ticket Information :\n"
                         << endl;
                    Print_ticket();
                    print_bill(Dom, A, Dt, seat);
                    pay_bill();
                }
                else
                {
                    cout << "\n\t\t\t Enter Correct Departure and Destiantion City" << endl;
                    cout << "\t\t\t " << getch();
                    system("CLS");
                    goto LOOP1;
                }
            }
            break;
            }
            case '2':
            {
                temp = Int;
                char choice3;
                Int.DisplayScedule();
                cout << "\t\t\t ";
                getch();
                cout << "Do you want to Sort Schedule?(y/n) : ";
                choice1 = getche();
                cout << endl;
                if (choice3 == 'y' || choice3 == 'Y')
                {
                    do
                    {
                        print_header("SORT TYPE");
                        cout << "\n\t\t\t Choose Menu\n\t\t\t 1.Asscending Order .\n\t\t\t 2.Desscending Order.\n\t\t\t 0. Go to back." << endl;
                        choice3 = getche();
                        cout << endl;
                        switch (choice3)
                        {
                        case '1':
                            print_header("BEFORE SORTING");
                            temp.DisplayScedule();
                            cout << "\t\t\t ";
                            getch();
                            print_header("AFTER SORTING");
                            temp.sortbyDepature_func('A');
                            temp.DisplayScedule();
                            break;
                        case '2':
                            print_header("BEFORE SORTING");
                            temp.DisplayScedule();
                            cout << "\t\t\t ";
                            getch();
                            print_header("AFTER SORTING");
                            temp.sortbyDepature_func('A');
                            temp.DisplayScedule();
                            break;
                        case '0':
                            break;

                        default:
                            cout << "\t\t\t Invalide input try aagin" << endl;
                            break;
                        }
                        cout << "\t\t\t ";
                        getch();
                        system("cls");
                    } while (choice3 != '0');
                }
            LOOP2:
            {
                Int.DisplayScedule();
                if (Int.SearchScedule())
                {
                    CopySceduleData(Int.cur->S, seat);
                    Tiket_no = Tiket_no + (rand() % 300 + 1);
                    seat.Set_seat();
                    CopyPassengerdata(Pas.cur->P, seat);
                    copy_date_time(Dt);
                    cout << "\n\t\t\t Your Ticket Information :\n"
                         << endl;
                    Print_ticket();
                    getch();
                    print_bill(Int, A, Dt, seat);
                    pay_bill();
                }
                else
                {
                    cout << "\n\t\t\t Enter Correct Departure and Destiantion City" << endl;
                    system("CLS");
                    goto LOOP2;
                }
            }
            break;
            }
            case '0':
                break;
            default:
                cout << "\t\t\t Invalid Input" << endl;
                break;
            }
            cout << "\t\t\t" << system("PAUSE");
        } while (choice1 != '0');
        Pas.writePassengerDatadata();
        cin.ignore(256, '\n');
        cin.clear();
    }
    long long int get_PassportNo() { return this->Passport; }
    long long int get_TicketNo() { return this->Tiket_no; }
};

class Ticket_node
{
private:
    Ticket Tk;
    Ticket_node *link;

public:
    Ticket_node *head, *cur, *next;
    Ticket_node()
    {
        head = cur = next = NULL;
    }
    void InsertAtEnd(Passenger_node P, Passenger passeng, Agency A, Date_time Dt, Seat seat, Schedule_node Dom, Schedule_node Int)
    {
        cur = head;
        while (cur->link != NULL)
        {

            cur = cur->link;
        }
        next = new Ticket_node;
        cur->link = next;
        next->Tk.Book_ticket(P, passeng, A, Dt, seat, Dom, Int);
        cur = next;
        next->link = NULL;
    }

    void Book_ticket(Passenger_node P, Passenger passeng, Agency A, Date_time Dt, Seat seat, Schedule_node Dom, Schedule_node Int)
    {

        if (head == NULL)
        {
            head = new Ticket_node;
            head->Tk.Book_ticket(P, passeng, A, Dt, seat, Dom, Int);
            head->link = NULL;
        }
        else
        {
            InsertAtEnd(P, passeng, A, Dt, seat, Dom, Int);
        }
        writeTicketDatadata();
    }

    void Search_by_passport(long long int temp)
    {
        bool flag = false;
        cur = head;
        while (cur != NULL)
        {
            if (cur->Tk.get_PassportNo() == temp)
            {
                cur->Tk.Print_ticket();
                flag = true;
            }
            cur = cur->link;
        }
        if (!flag)
        {
            cout << "\t\t\t No record Found " << endl;
        }
    }

    void Search_Ticket()
    {
        long long int temp;
        char choice;
        bool flag = false;
        do
        {
            print_header("TICKET SEARCH ");
            cout << "\t\t\tPlease choose menue " << endl;
            cout << "\t\t\t 1. Passport No " << endl;
            cout << "\t\t\t 2. Ticket No" << endl;
            cout << "\t\t\t 0. Go back " << endl;
            cout << "Please Enter Here : " << endl;
            choice = getch();
            cout << endl;
            switch (choice)
            {
            case '1':
            {
                cout << "\t\t\t Please Enter Passport No :";
                cin >> temp;
                while (!cin)
                {
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "\t\t\t Please Enter Valid Passport No :";
                    cin >> temp;
                }
                while (!check_number(temp))
                {
                    cout << "\t\t\t Please Enter Valid Passport No :";
                    cin >> temp;
                }
                Search_by_passport(temp);
                break;
            }
            case '2':
            {
                cout << "\t\t\t Please Enter Ticket No :";
                cin >> temp;
                while (!cin)
                {
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "\t\t\t Please Enter Valid Ticket No :";
                    cin >> temp;
                }
                while (!check_number(temp))
                {
                    cout << "\t\t\t Please Enter Valid Ticket No :";
                    cin >> temp;
                }
                cur = head;
                while (cur != NULL)
                {
                    if (cur->Tk.get_TicketNo() == temp)
                    {
                        cur->Tk.Print_ticket();
                        flag = true;
                    }
                    cur = cur->link;
                }
                if (!flag)
                {
                    cout << "\t\t\t No record Found " << endl;
                }
                break;
            }
            case '0':
            {
                break;
            }

            default:
                cout << "\t\t\t Invalid choice Try again" << endl;
                break;
            }
            cout << "\t\t\t ";
            getch();
            system("cls");
        } while (choice != '0');
    }

    void DeleteFirstNode()
    {
        Ticket_node *temp;
        temp = head->link;
        free(head);
        head = NULL;
        head = temp;
        cout << "\t\t\tDeleted successfully" << endl;
    }

    void DeleteEndNode()
    {

        if (head->link == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            cur = head;
            while (cur->link->link != NULL)
            {
                cur = cur->link;
            }
            free(cur->link);
            cur->link = NULL;
            cout << "\t\t\tDeleted Successfully" << endl;
        }
    }

    void Delete_Ticket(long long int passport)
    {
        cur = head;
        bool flag = false;
        Ticket_node *prev = head;
        if (head == NULL)
        {
            cout << "\t\t\tThere is no data " << endl;
            return;
        }
        if (head->Tk.get_PassportNo() == passport)
        {
            DeleteFirstNode();
            cout << "\t\t\tDeleted succesfully" << endl;
            return;
        }
        while (cur->link != NULL)
        {
            cur = cur->link;
        }
        if (head->Tk.get_PassportNo() == passport)
        {
            DeleteEndNode();
            cout << "\n\t\t\tDeleted succesfully" << endl;
            return;
        }
        cur = head;
        while (cur != NULL)
        {

            if (cur->Tk.get_PassportNo() == passport)
            {
                flag = true;
                prev->link = cur->link;
                free(cur);
                cur = NULL;
                cout << "\n\t\t\tDeleted succesfully" << endl;
                break;
            }
            prev = cur;
            cur = cur->link;
        }
        if (!flag)
        {
            cout << "\t\t\tNo record matched" << endl;
            return;
        }
    }

    void Cancel_Ticket(long long int temp)
    {
        Delete_Ticket(temp);
    }

    bool Validate_ticket(long long int passport)
    {
        if (head == NULL)
        {
            return true;
        }
        Ticket_node *cur1 = head;
        while (cur1 != NULL)
        {
            if (cur1->Tk.get_PassportNo() == passport)
            {
                return false;
            }
            cur1 = cur1->link;
        }
        return true;
    }
    void Update_Ticket(long long int pasport, Passenger P, Seat S)
    {
        cur = head;
        if (cur == NULL)
        {
            cout << "\t\t\tNo record To update" << endl;
        }
        while (cur != NULL)
        {
            if (cur->Tk.get_PassportNo() == pasport)
            {
                cur->Tk.CopyPassengerdata(P, S);
                return;
            }
            cur = cur->link;
        }
    }
    void List_tickets()
    {
        if (head == NULL)
        {
            cout << "\n\t\t\t No recode found" << endl;
            return;
        }
        cur = head;
        while (cur != NULL)
        {
            cur->Tk.Print_ticket();
            cur = cur->link;
        }
    }

    void writeTicketDatadata()
    {
        cur = head;
        ofstream fout("Files/Tickets/Ticket.bin", ios::binary);
        if (fout.is_open())
        {
            fout.clear();
            while (cur != NULL)
            {
                fout.write((char *)&(cur->Tk), sizeof(cur->Tk));
                cur = cur->link;
            }
            fout.close();
        }
        else
        {
            cout << "\t\t\t File Error!" << endl;
            cout << "\t\t\t File No found" << endl;
            return;
        }
    }

    void ReadTicketdata()
    {
        Ticket_node *temp = NULL;
        head = NULL;
        ifstream fin("Files/Tickets/Ticket.bin", ios::binary);
        if (fin.is_open())
        {
            if (!Is_empty(fin))
            {
                head = new Ticket_node;
                fin.read((char *)&(head->Tk), sizeof((head->Tk)));
                head->link = NULL;
                cur = head;
            }
            while (!fin.eof())
            {
                if (head != NULL)
                {
                    if (!fin.eof())
                    {

                        next = new Ticket_node;
                        if (fin.read((char *)&(next->Tk), sizeof((next->Tk))))
                        {
                            cur->link = next;
                            next->link = NULL;
                            cur = next;
                            break;
                        }
                        else
                            (free(next));
                    }
                }
            }
            fin.close();
        }
        else
        {
            cout << "\t\t\t File Error!" << endl;
            cout << "\t\t\t File No found" << endl;
        }
    }
};

class BookingAgent : public Employee_node
{
public:
    void InsertAgent()
    {
        InsertEmployee();
    }
    void List_Agent()
    {
        EmployeeTraversing();
    }
    void Delete_Agent()
    {
        long long int ID = Input_checkNO("ID #");
        DeletebyID(ID);
    }
    void Search_Agent()
    {
        SearchEmployee();
    }
    void Update_Agent()
    {
        updateEmployee();
    }
    void Read_Agent_Data()
    {
        ReadEmployeedata("Files/Employees/Agent.bin");
    }
    void Write_Agent_Data()
    {
        writeEmployeeDatadata("Files/Employees/Agent.bin");
    }
};

void Booking_Agent_Menue_For_manager(BookingAgent agent, Login_node E_log)
{
    agent.Read_Agent_Data();
    char choice;
    do
    {
        print_header("BOOKING AGENT");
        cout << "\t\t\t Please Choose Menue" << endl;
        cout << "\t\t\t 1.Add Booking Agent" << endl;
        cout << "\t\t\t 2.Delete Booking Agent" << endl;
        cout << "\t\t\t 3.Search Booking Agent" << endl;
        cout << "\t\t\t 4.Update Booking Agent" << endl;
        cout << "\t\t\t 5.List Booking Agent" << endl;
        cout << "\t\t\t 0. go Back" << endl;
        cout << "\t\t\t Enter Here :";
        choice = getche();
        cout << endl;
        switch (choice)
        {
        case '1':
        {
            cin.clear();
            cin.ignore(256, '\n');
            agent.InsertAgent();
            E_log.InsertLogin(agent.cur->E.Get_EmployeeID(), agent.cur->E.getDOB());
            break;
        }
        case '2':
        {
            agent.Delete_Agent();
            break;
        }
        case '3':
        {
            agent.Search_Agent();
            break;
        }
        case '4':
        {
            agent.Update_Agent();
            break;
        }
        case '5':
        {
            agent.List_Agent();
            break;
        }
        case '0':
        {
            break;
        }
        default:
            cout << "\t\t\t Invalid Input" << endl;
            break;
        }
        cout << "\t\t\t ";
        getch();
        system("CLS");
    } while (choice != '0');
    agent.Write_Agent_Data();
    E_log.writeLoginDatadata("Files/Logins/EmployeeLogin.bin");
}

void Booking_agent_Menue(Ticket_node Tk, Passenger_node Pass, Passenger passeng, Agency A, Date_time Dt, Seat seat, Schedule_node Dom, Schedule_node Int, Login_node Log)
{
    char choice;
    do
    {
        print_header("BOOKING AGENT MENUE");
        cout << "\t\t\t Chose your Desired Option," << endl;
        cout << "\t\t\t 1 Ticket Menu" << endl;
        cout << "\t\t\t 2 Scedule Menu." << endl;
        cout << "\t\t\t 3 Passenger Menu." << endl;
        cout << "\t\t\t 0 Go to Main Menu" << endl;
        cout << "\n\t\t\t Enter Here : ";
        choice = getche();
        cout << endl;
        switch (choice)
        {
        case '1':
            Tk.Book_ticket(Pass, passeng, A, Dt, seat, Dom, Int);
            Log.InsertLogin(Pass.cur->P.Get_passengerPassport(), Pass.cur->P.getDOB());
            break;
        case '2':
            Schedule_menue(Dom, Int);
            break;
        case '3':
            Passenger_Menue(Pass);
            break;
        case '0':
            break;
        default:
            cout << "\n\t\t\tInvalid Input " << endl;
            break;
        }
        system("cls");
    } while (choice != '0');
}

class Manager : public Employee
{
public:
    void store_Manager()
    {
        if (Get_EmployeeName() != "None" && Get_EmployeeCNIC() != 0)
        { //avoiding to write constructor data
            ofstream fout("Files/Managers/Manager.bin", ios::out | ios::app | ios::binary);
            fout.clear();
            fout.write((char *)this, sizeof(*this));
            fout.close();
            cout << "\n\t\t\t SUCCESS";
        }
        else
            cout << "\t\t\t Data Not Intialized" << endl;
    }
    void Read_Manager()
    {
        int counter = 1;
        ifstream Fin("Files/Managers/Manager.bin", ios::in | ios::binary);
        if (Fin.is_open())
        {
            Fin.read((char *)this, sizeof(*this));
            while (!Fin.eof())
            {
                printEmployeer("Manager");
                counter++;
                Fin.read((char *)this, sizeof(*this));
            }
            Fin.close();
        }
        else
            cout << "\t\t\t File not Opened" << endl;
    }
    void Set_maneger(Login_node M_log)
    {
        Set_Employee();
        store_Manager();
        cout << "\t\t\t User Name :" << Get_EmployeeID() << endl;
        M_log.InsertLogin(Get_EmployeeID(), getDOB());
        M_log.writeLoginDatadata("Files/Logins/ManagerLogin.bin");
    }
    void About_Maneger()
    {
        Read_Manager();
    }
};

void Manager_menue(Ticket_node tk, Manager MG, Passenger_node P, Agency A, Schedule_node Dom, Schedule_node Int, BookingAgent agent, Login_node M_log, Login_node E_log)
{
    char choice;
    do
    {
        print_header("MANAGER MENU");
        cout << "\t\t\tChoose Your desired option." << endl;
        cout << "\t\t\t 1. Agency Menue" << endl;
        cout << "\t\t\t 2. Booking Agent Menue" << endl;
        cout << "\t\t\t 3. Schedule Menu ." << endl;
        cout << "\t\t\t 4. Add Manager." << endl;
        cout << "\t\t\t 5. About Manager." << endl;
        cout << "\t\t\t 6. List Logins." << endl;
        cout << "\t\t\t 7. List Tickets." << endl;
        cout << "\t\t\t 0. Go to main Menu." << endl;
        cout << "\t\t\t  Enter Here :";
        choice = getche();
        cout << endl;
        switch (choice)
        {
        case '1':
            A.Agency_Menue();
            break;
        case '2':
            system("cls");
            Booking_Agent_Menue_For_manager(agent, E_log);
            break;
        case '3':
            Schedule_menue(Dom, Int);
            break;
        case '4':
            MG.Set_maneger(M_log);
            break;
        case '5':
            MG.Read_Manager();
            break;
        case '6':
            M_log.list_Logins();
            break;
        case '7':
            tk.List_tickets();
            break;
        case '0':

            break;

        default:
            break;
        }
        system("PAUSE");
        system("CLS");
    } while (choice != '0');
    M_log.writeLoginDatadata("Files/Logins/ManagerLogin.bin");
}

void Manger_Agent_Menue(Ticket_node Tk, Passenger_node Pass, Passenger passeng, Agency A, Date_time Dt, Seat seat, Schedule_node Dom, Schedule_node Int, Login_node M_Log, Login_node E_Log, Manager MG, BookingAgent agent)
{
    long long temp, Temp_password;

    int count = 3;
LOOP3:
{
    print_header("ADMIN LOGIN");
    while (count >= 1)
    {
        cout << "\t\t\t Remainig tries are " << count << endl;
        cout << "\n\t\t\tEnter User Name : ";
        cin >> temp;
        while (!cin)
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Enter Valid User Name : ";
            cin >> temp;
        }
        while (!check_number(temp))
        {
            cout << "\t\t\tEnter Valid User Name : ";
            cin >> temp;
        }
        cout << "\t\t\t Please enter  Password : ";
        cin >> Temp_password;
        while (!cin)
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "\t\t\t Please enter Valid Password : ";
            cin >> Temp_password;
        }
        while (!check_number(Temp_password))
        {
            cout << "\t\t\t Please enter Valid Password : ";
            cin >> Temp_password;
        }

        if (M_Log.Check_Login(temp, Temp_password) == true && M_Log.cur->Log.GetUsername())
        {
            print_header("MANAGER MENUE");
            cout << "\n";
            Manager_menue(Tk, MG, Pass, A, Dom, Int, agent, M_Log, E_Log);
            return;
        }
        else if (E_Log.Check_Login(temp, Temp_password) == true && E_Log.cur->Log.GetUsername())
        {
            print_header("AGENT MENUE");
            Booking_agent_Menue(Tk, Pass, passeng, A, Dt, seat, Dom, Int, E_Log);
            cout << "\n";
            return;
        }
        count--;
        system("cls");
        print_header("LOGIN AGAIN");
    }
    if (count == 0)
    {
        char choice3;
        do
        {
            system("cls");
            print_header("M E N U E");
            cout << "\t\t\t Too many tries" << endl;
            cout << "\t\t\t Choose Menue" << endl;
            cout << "\t\t\t 1. Reset Manager Login " << endl;
            cout << "\t\t\t 2. Reset Agent Login " << endl;
            cout << "\t\t\t 0.Go back" << endl;
            cout << "\t\t\t Enter Here : ";
            choice3 = getche();
            cout << endl;
            switch (choice3)
            {

            case '1':
                M_Log.Reset_login();
                cout << "\t\t\t Your Login has been Updated " << endl;
                cout << "\t\t\t Now Go Back and Login" << endl;
                cout << "\t\t\t";
                getch();
                goto LOOP3;
                break;

            case '2':
                E_Log.Reset_login();
                cout << "\t\t\t Your Login has been Updated " << endl;
                cout << "\t\t\t Now Go Back and Login" << endl;
                cout << "\t\t\t";
                getch();
                goto LOOP3;
            case '0':
                return;
                break;

            default:
                cout << "\t\t\t Invalid choice" << endl;
                break;
            }
            cout << "\t\t\t";
            getch();
            system("CLS");
        } while (choice3 != '0');
        E_Log.writeLoginDatadata("Files/Logins/EmployeeLogin.bin");
        M_Log.writeLoginDatadata("Files/Logins/ManagerLogin.bin");
    }
}
}

void Passenger_Profile(Ticket_node Tk, Passenger_node Pass, Passenger passeng, Agency A, Date_time Dt, Seat seat, Schedule_node Dom, Schedule_node Int, Login_node P_Log)
{
    int count = 3;
    char choice;
    do
    {
        Pass.ReadPassengerdata();
        print_header("PASSENGER MENUE");
        cout << "\t\t\t Choose Menue" << endl;
        cout << "\t\t\t 1.Create New Account" << endl;
        cout << "\t\t\t 2.Existing user" << endl;
        cout << "\t\t\t 0.Go back" << endl;
        cout << "\t\t\t Enter Here : ";
        choice = getche();
        cout << endl;
        switch (choice)
        {
        case '1':
            cout << "Please create new Account" << endl;
            print_header("PASSENGER DATA");
            cin.clear();
            cin.ignore(256, '\n');
            Pass.InsertPassenger();
            P_Log.InsertLogin(Pass.cur->P.Get_passengerPassport(), Pass.cur->P.getDOB());
            break;
        case '2':
        {
        LOOP3:
        {
            print_header("LOGIN");
            count=3;
            while (count >= 1)
            {
                long long temp, Temp_password;
                cout << "\t\t\t Remainig tries are " << count << endl;

                temp = Input_checkNO("User Name ");

                Temp_password = Input_checkNO("Enter  Password");

                if (P_Log.Check_Login(temp, Temp_password))
                {
                    cout << "\t\t\t\t" << P_Log.cur->Log.GetUsername();
                    Pass.searchPassengerByPassport(P_Log.cur->Log.GetUsername());
                    cout << "\t\t\t Login Successfull" << endl;
                    do
                    {
                        print_header("PASSENGER PROFILE");
                        cout << "\t\t\t " << Pass.cur->P.Get_passengerName() << "\t\t   " << Pass.cur->P.Get_passengerPassport() << endl;
                        cout << "\n\t\t\t Chose your Desired Option," << endl;
                        cout << "\t\t\t 1 Book Ticket" << endl;
                        cout << "\t\t\t 2 Cancel Ticket." << endl;
                        cout << "\t\t\t 3 Search Ticket." << endl;
                        cout << "\t\t\t 4 Update Record ." << endl;
                        cout << "\t\t\t 0 Exit." << endl;
                        cout << "\n\t\t\t Enter Here : ";
                        choice = getche();
                        cout << endl;
                        switch (choice)
                        {
                        case '1':
                            Tk.Book_ticket(Pass, passeng, A, Dt, seat, Dom, Int);
                            break;
                        case '2':
                            Tk.Cancel_Ticket(P_Log.cur->Log.GetUsername());
                            break;
                        case '3':
                            Tk.Search_by_passport(P_Log.cur->Log.GetUsername());
                            break;
                        case '4':
                            Pass.updatePassenger(P_Log.cur->Log.GetUsername());
                            Tk.Update_Ticket(Pass.cur->P.Get_passengerPassport(), passeng, seat);
                            break;
                        case '0':

                            break;
                        default:
                            cout << "\t\t\t Invalid choice" << endl;
                            break;
                        }
                        cout << "\t\t\t ";
                        getch();
                        system("cls");
                    } while (choice != '0');
                    break;
                }
                count--;
                system("cls");
                print_header("LOGIN AGAIN");
            }
            if (count == 0)
            {
                char choice3;
                do
                {
                    system("cls");
                    print_header("M E N U E");
                    cout << "\t\t\t Too many tries" << endl;
                    cout << "\t\t\t Choose Menue" << endl;
                    cout << "\t\t\t 1. Reset Login " << endl;
                    cout << "\t\t\t 0.Go back" << endl;
                    cout << "\t\t\t Enter Here : ";
                    choice3 = getche();
                    cout << endl;
                    switch (choice3)
                    {

                    case '1':
                        P_Log.Reset_login();
                        cout << "\t\t\t Your Login has been Updated " << endl;
                        cout << "\t\t\t Now Go Back and Login" << endl;
                        goto LOOP3;
                        break;
                    case '0':
                        break;

                    default:
                        cout << "\t\t\t Invalid choice" << endl;
                        break;
                    
                    cout << "\t\t\t";
                    getch();
                    system("CLS");
                }

                count--;
                cout << "\t\t\t Remaining tries are :" << count << endl;
            } while (choice3 != '0');     
            }
            
        }
        break;
        }
        case '0':
            break;
        default:
        {
            cout<<"\t\t\t Invalid input"<<endl;
        }
        Pass.writePassengerDatadata();
        }
        cout<<"\t\t\t ";getch();
        
    }while (choice != '0');
        
        Tk.writeTicketDatadata();
        P_Log.writeLoginDatadata("Files/Logins/PassengerLogin.bin");
    
}

      void Main_Menue(Ticket_node Tk, Passenger_node Pass, Passenger passeng, Agency A, Date_time Dt, Seat seat, Schedule_node Dom, Schedule_node Int, Login_node P_Log, Login_node M_Log, Login_node E_Log, Manager MG, BookingAgent agent)
{
    char choice;
    do
    {
        print_header("Main Menue");
        cout << "\t\t\t Chose your Desired Option," << endl;
        cout << "\n\t\t\t 1 Passenger Menue" << endl;
        cout << "\t\t\t 2 Login as Admin." << endl;
        cout << "\t\t\t 0 Exit" << endl;
        cout << "\n\t\t\t Enter Here : ";
        choice = getche();
        cout << endl;
        switch (choice)
        {
        case '1':
            Passenger_Profile(Tk, Pass, passeng, A, Dt, seat, Dom, Int, P_Log);
            break;
        case '2':
            Manger_Agent_Menue(Tk, Pass, passeng, A, Dt, seat, Dom, Int, M_Log, E_Log, MG, agent);
            break;
        case '0':
            Credit();
            exit(0);
            break;

        default:
            cout << "\t\t\t Inavalid input" << endl;
            break;
        }
        cout << "\t\t\t " << getch;
        system("CLS");
    } while (choice != '0');
}

void Credit()
{
    cout << "\n\n\n                     __________________________________________________________________  " << endl;
    cout << "                   |__________________________________________________________________| " << endl;
    cout << "                   ||                          AIRPLANE                              || " << endl;
    cout << "                   ||                  TICKET RESERVATION SYSTEM                     || " << endl;
    cout << "                   ||****************************************************************|| " << endl;
    cout << "                   ||_______________________________________________________________ || " << endl;
    cout << "                   ||                       PROJECT MADE BY :-                       || " << endl;
    cout << "                   ||                                                                || " << endl;
    cout << "                   ||              ASIF IMRAN            19011519-134                || " << endl;
    cout << "                   ||              SARAM MUGHIRA         19011519-074                || " << endl;
    cout << "                   ||              Shoaib Shahid         19011519-063                || " << endl;
    cout << "                   ||                                                                || " << endl;
    cout << "                   ||____________________   ENTER ENTER TO QUIT    __________________|| " << endl;
    cout << "                   |_________________________________________________________________ | " << endl;
    cout << "                                                    ";
    getch();
    cout << endl;
}

int main()
{
    Ticket T;
    Ticket_node Tk;
    Passenger_node Pass;
    Passenger passeng;
    Agency A;
    Date_time Dt;
    Seat seat;
    Schedule_node Dom, Int;
    Schedule Sch;
    Login_node P_Log, M_Log, E_Log;
    Manager MG;
    BookingAgent agent;

    //Reading Data from Files
    Pass.ReadPassengerdata();
    Tk.ReadTicketdata();
    Dom.ReadPScheduledata("Files/Schedules/Domestic.bin");
    Int.ReadPScheduledata("Files/Schedules/International.bin");
    P_Log.ReadLogingerdata("Files/Logins/PassengerLogin.bin");
    M_Log.ReadLogingerdata("Files/Logins/ManagerLogin.bin");
    E_Log.ReadLogingerdata("Files/Logins/EmployeeLogin.bin");
    agent.Read_Agent_Data();
    //Calling main function
    Main_Menue(Tk, Pass, passeng, A, Dt, seat, Dom, Int, P_Log, M_Log, E_Log, MG, agent);

    // MG.Set_maneger(M_Log);
}
