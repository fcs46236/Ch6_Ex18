/* Program File Name: Ch6_Ex18
Programmer: Frank Sonsini
Date : November 2026
Requirements : Write a program thatasks the user for initial population, annual births per thousand, annual deaths per thousand and number of years for which projections are wanted.
               Display the initial population and the projected population for each year requested.
               Create a function to perform the calculations.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int years, index;
double nbr_births, nbr_deaths, brth_rate, dth_rate;
double pop, oldpop, newpop;

//Function new_pop - calculates the next year of population projection

double new_pop(double p, double b, double d)
{
    brth_rate = b / 1000.0;
    dth_rate = d / 1000.0;
    return (p * (1 + brth_rate) * (1 - dth_rate));
}

int main()
{
    cout << fixed << setprecision(3);

    cout << "Please input the starting population" << endl;
    cin >> oldpop;

    while (oldpop <2)
    {
        cout << "The starting population must be greater than one.  Please enter such a value" << endl;
        cin >> oldpop;
    }

    cout << "Please enter the annual number of births per thousand and the annual number of deaths per thousand for the population" << endl;
    cin >> nbr_births >> nbr_deaths;

    while (nbr_births < 0 || nbr_deaths < 0)
    {
        cout << " Both number of births and number of deaths must be non-negatve.  Please enter these values again." << endl;
        cin >> nbr_births >> nbr_deaths;
    }

    cout << "Please enter the number of years for which you want population projections." << endl;
    cin >> years;
    cout << endl;

    while (years < 1)
    {
        cout << "The number of years must be at least one.  Please try again." << endl;
        cin >> years;
    }

    cout << "The starting population is " << fixed << setprecision(0) << oldpop << endl;

    for (index = 1;index < years + 1;index++)
    {
        pop = new_pop(oldpop, nbr_births, nbr_deaths);
        cout << "For year " << index << " the projectd population is " << fixed << setprecision(0) << pop << "." << endl;
        oldpop = pop;
    }

    return(0);
}