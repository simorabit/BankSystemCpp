#pragma once
#include<iostream>
#include "clsDate.h"
#include <limits>
using namespace std;

class clsInputValidate
{
    public:
    static bool IsNumberBetween(int nbr, int first, int last)
    {
       return ( first <= nbr &&  nbr <= last);
    }
    static bool IsNumberBetween(double nbr, double first, double last)
    {
        return ( first <= nbr &&  nbr <= last);
    }
    static bool IsDateBetween(clsDate date, clsDate firstDate, clsDate lastDate)
    {
        if(date.IsDateAfterDate2(firstDate) && 
            date.IsDateBeforeDate2(lastDate))
            return true;
        else if(date.IsDateEqualDate2(firstDate) || date.IsDateEqualDate2(lastDate))
            return true;
        
        return false;
    }
    static float ReadFloatNumber(string msg = "Invalid Number, Enter again:\n")
    {
        float input;
        while(!(cin >> input))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << msg;
        }
        return input;
    }
    static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		short Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
    static int ReadIntNumber(string msg = "Invalid Number, Enter again:\n")
    {
        int input;
        while(!(cin >> input))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << msg;
        }
        return input;
    }
    static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}

    static int ReadIntNumberBetween(int first, int last, string errorMsg)
    {
        int input;
        while(true)
        {
            input = ReadIntNumber();
            if(IsNumberBetween(input,first,last))
                break;
            cout << errorMsg;
        }
        return input;
    }

    static double ReadDblNumber(string errorMsg = "Invalid Number, Enter again:\n")
    {
        double input;
        while(!(cin >> input))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << errorMsg;
        }
        return input;
    }

    static double ReadDblNumberBetween(double first, double last, string errorMsg)
    {
        double input;
        while(true)
        {
            input = ReadDblNumber();
            if(IsNumberBetween(input,first,last))
                break;
            cout << errorMsg;
        }
        return input;
    }

    static bool IsValideDate(clsDate date)
    {
        return clsDate::IsValidDate(date);
    }

    static string ReadString()
	{
		string  S1="";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}
};