#include <iostream>
#include <fstream>
using namespace std;

void line(char ch)
{
    cout << endl; // print characters of line / less code
    for (int i = 0; i < 60; i++)
    {
        cout << ch;
    }
    cout << endl;
}

class Login
{
private:
    int attempts, tries;
    string input, pass;

public:
    Login() : attempts(0), tries(3), pass("1234") {}
    ~Login() {}

    inline void login()
    {
        system("cls");
        do
        {
            line('=');
            cout << "\t\tParking Management System\n\t\t\t Login Menu";
            line('=');
            cout << "\nEnter PIN: " << endl;
            cout << "PIN: ";
            cin >> input;
            if (input != pass)
            {
                attempts++;
                tries--;
                system("cls");

                cout << "Wrong Password!"
                     << "\t\t\tAttempts Remaining: " << tries << endl;
            }
        } while (attempts <= 3 && input != pass);

        system("cls");

        if (attempts > 3)
        {
            cout << "Login attempts exceeded\nSorry, you have been kicked from the program :/" << endl;
            exit(0);
        }

        line('*');
        getchar();

        system("cls");
    }
};

class Receipt
{
private:
    string name;
    int roll;
    string license;

public:
    Receipt() : name(" "), roll(0), license(" ") {}
    ~Receipt() {}
    friend class Parking;

    void getData()
    {
        system("cls");

        cout << "\nEnter Name: ";
        cin >> name;

        cout << "Enter Roll# ";
        cin >> roll;

        cout << "Enter Vehicle License: ";
        cin >> license;
    }

    virtual void print(){};
};

class Parking : public Login, public Receipt
{
private:
    const int totalCapacity;
    static int parked;
    int freeSpace, cars, bikes, vans;

public:
    Parking() : totalCapacity(200), freeSpace(200), cars(0), bikes(0), vans(0) {}
    ~Parking() {}

    void data();
    void park();
    void leaveLot();
    void print();
    void display();
};

int Parking::parked = 0; //static total parked

void Parking::data()
{
    cout << "Total Spaces: " << totalCapacity << "\t\t"
         << "Remaining Spaces: " << freeSpace << endl;
    cout << "Vehicles Parked: " << parked << "\tCars: " << cars << "\t   Bikes: " << bikes << "\tVans: " << vans;
}

void Parking::park()
{
    int ch;
    system("cls");
    line('=');
    cout << "Select Vehical to Park: " << endl;
    cout << "\n[1]Car" << endl;
    cout << "[2]Bike" << endl;
    cout << "[3]Van" << endl;
    line('-');

    cout << "Choice: ";
    cin >> ch;

    cout << endl;

    switch (ch)
    {
    case 1:
    {
        cout << "Car has been parked"
             << "\nPress Enter to continue... " << endl;
        cars++;
        parked++;
        freeSpace--;
        getchar();
        getchar();
    }
    break;

    case 2:
    {
        cout << "Bikes has been parked"
             << "\nPress Enter to continue... " << endl;
        bikes++;
        parked++;
        freeSpace--;
        getchar();
        getchar();
    }
    break;

    case 3:
    {
        cout << "Van has been parked"
             << "\nPress Enter to continue... " << endl;
        vans++;
        parked++;
        freeSpace--;
        getchar();
        getchar();
    }
    break;

    default:
    {
        cout << "Please enter a valid option..." << endl;
        getchar();
        getchar();
        break;
    }
    }
}

void Parking::leaveLot()
{
    int choice;

    if (freeSpace == 200)
    {
        cout << "No vehicle parked, Enter a vehicle first! " << endl;
        cout << "Press enter to continue..." << endl;
        getchar();
        getchar();
    }
    else
    {
        system("cls");
        line('-');
        cout << "Select Vehicle to vacate from Parking lot:" << endl;
        cout << "\n[1]Vacate Car" << endl;
        cout << "[2]Vacate Bike" << endl;
        cout << "[3]Vacate Van " << endl;

        line('-');

        cout << "Choice: ";
        cin >> choice;

        cout << endl;

        switch (choice)
        {
        case 1:
        {
            if (cars == 0)
            {
                cout << "No car is parked yet" << endl;
                cout << "\nPress enter to continue..." << endl;
                getchar();
                getchar();
            }
            else
            {
                cars--;
                parked--;

                if (freeSpace <= 200)
                    freeSpace++;
                cout << "Your car has been vacated" << endl;

                getchar();
                getchar();
            }
        }
        break;

        case 2:
        {
            if (bikes == 0)
            {
                cout << "No bike is parked yet" << endl;
                cout << "\nPress enter to continue..." << endl;
                getchar();
                getchar();
            }
            else
            {
                bikes--;
                parked--;

                if (freeSpace <= 200)
                    freeSpace++;
                cout << "Your bike has been vacated" << endl;
                getchar();
                getchar();
            }
        }
        break;

        case 3:
        {
            if (vans == 0)
            {
                cout << "No van is parked yet" << endl;
                cout << "\nPress enter to continue..." << endl;
                getchar();
                getchar();
            }
            else
            {
                vans--;
                parked--;

                if (freeSpace <= 100)
                    freeSpace++;
                cout << "Your van has been vacated" << endl;
                getchar();
                getchar();
            }
        }
        break;

        default:
            cout << "Invalid option";
            break;
        }
    }
}

void Parking::print()
{
    // cout << "Derived print";
    ofstream receipt("receipt.txt");
    receipt << "===============================" << endl;
    receipt << "\t  Ticket#" << parked << endl;
    receipt << "-------------------------------" << endl;
    receipt << "  Name: " << name << "  |  "
            << "Roll# " << roll << endl;
    receipt << "-------------------------------" << endl;

    receipt << "  Plate Number: " << license << endl;
    receipt << "===============================" << endl;
    receipt.close();
    cout << "\n\nYour Ticket has been printed!";
    getchar();
    getchar();
}

inline void Parking::display()
{

    int ch;
    bool menu;

    system("cls");

    do
    {
        menu = false;
        system("cls");

        cout << "\t\tParking Management System";
        line('=');

        data();

        line('-');
        cout << "\n\n[1] Park Vehicle" << endl;
        cout << "[2] Exit Parking lot" << endl;
        cout << "[3] Print Receipt" << endl;
        cout << "[4] Logout" << endl;
        cout << "[5] Quit" << endl;

        line('=');

        cout << "\nChoice: ";
        cin >> ch;

        cout << endl;

        switch (ch)
        {
            int choice;
            system("cls");

        case 1:
            park();
            menu = true;
            break;

        case 2:
            leaveLot();
            menu = true;
            break;

        case 3:
            if (parked == 0)
            {
                cout << "Park your vehicle to get your ticket" << endl;

                getchar();
                getchar();
                menu = true;
                break;
            }
            else
            {

                Receipt *rObj;
                Parking pObj;

                rObj = &pObj;

                rObj->getData();
                rObj->print();

                // Receipt::getData();
                // Parking::print();
                menu = true;
                break;
            }

        case 4:
            cout << "Are you sure you want to log out?"
                 << "\nPress enter to continue." << endl;

            getchar();
            getchar();

            Login::login();
            menu = true;
            break;

        case 5:
            exit(0);

        default:
            cout << "\nEnter a valid number!\nPress Enter to try again..." << endl;
            getchar();
            getchar();
            menu = true;
            break;
        }
    } while (menu);
}

int main()
{
    Parking Main;

    Main.login();
    Main.display();

    return 0;
}