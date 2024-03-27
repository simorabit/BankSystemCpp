#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>

using namespace std;

class clsManageUsersScreen :protected clsScreen
{

private:
    enum enManageUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };

    static short ReadManageUsersMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _GoBackToManageUsersMenue()
    {
        cout << setw(37) << left << ""
             << "\n\tPress any key to go back to Main Menue...\n";
        std::cin.ignore();
        std::cin.get();
        ShowManageUsersMenue();
    }

    static void _ShowListUsersScreen()
    {
        cout << "\nList Users Screen Will Be Here.\n";

    }

    static void _ShowAddNewUserScreen()
    {
        cout << "\nAdd New User Screen Will Be Here.\n";

    }

    static void _ShowDeleteUserScreen()
    {
        cout << "\nDelete User Screen Will Be Here.\n";

    }

    static void _ShowUpdateUserScreen()
    {
        cout << "\nUpdate User Screen Will Be Here.\n";
    }

    static void _ShowFindUserScreen()
    {
        cout << "\nFind User Screen Will Be Here.\n";
    }


    static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
    {

        switch (ManageUsersMenueOption)
        {
        case enManageUsersMenueOptions::eListUsers:
        {
            system("clear");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eAddNewUser:
        {
            system("clear");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eDeleteUser:
        {
            system("clear");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eUpdateUser:
        {
            system("clear");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eFindUser:
        {
            system("clear");
             _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eMainMenue:
        {
            
        }
        }

    }

public:
    static void ShowManageUsersMenue()
    {
        system("clear");
        _DrawScreenHeader("\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenueOption((enManageUsersMenueOptions)ReadManageUsersMenueOption());
    }

};
