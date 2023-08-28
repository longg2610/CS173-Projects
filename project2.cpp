/*

Given the on and off periods of two lights, determine how many lights are on when ups driver arrives
Author: Long Pham
Date created: January 30, 2023
Date updated: February 3, 2023
*/
#include<iostream>            //include iostream header file
using namespace std;          //standard library namespace
int main(){
    
	int t1_on{}, t1_off{}, t2_on{}, t2_off{}, t_ups{};       //declaration for inputs
    cin >> t1_on >> t1_off >> t2_on >> t2_off >> t_ups;      //prompt user for input values
    
    bool light_1_on{}, light_2_on{};                         //declare lights on/off status
    int t1_cycle{t1_on + t1_off}, t2_cycle{t2_on + t2_off};  //declare and initialize on and off cycles
    int remainder1{t_ups % t1_cycle};      //use modular division to find t_ups in interval 0 to t1_cycle
    if (remainder1 >= t1_on)               //if result larger than or equal to t1_on
        {light_1_on = false;}                //light 1 is off
    else                                   //if smaller than t1_on
        {light_1_on = true;}                 //light 1 is on
    
    int remainder2{t_ups % t2_cycle};      //use modular division to find t_ups in interval 0 to t2_cycle
    if (remainder2 >= t2_on)               //if result larger than or equal to t2_on
        {light_2_on = false;}                //light 2 is off
    else                                   //if smaller than t2_on
        {light_2_on = true;}                 //light 2 is on

    if (light_1_on == true && light_2_on == true)  //if both lights are on
        {cout << "BOTH" << endl;}                    //print BOTH
    if (light_1_on == false && light_2_on == false)  //if no lights are on
        {cout << "NONE" << endl;}                      //print NONE
    if ((light_1_on == true && light_2_on == false) || (light_1_on == false && light_2_on == true))  //if one of two is on
        {cout << "ONE" << endl;}                                                                       //print ONE

	return 0;
}