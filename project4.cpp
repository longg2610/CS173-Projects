/*
Author: Long Pham, Jianheng Guo
Description: Project 4 - convert numbers to Roman numerals
Date: 02-23-2023
Updated: 02-27-2023
Task distribution:
- Long Pham: write code for subtractive notation handling, write comments and thinking code ideas for user-input loop.
- Jianheng Guo: write code for subtracting and adding characters to output (if-else ladder), come up with test cases, and test code.
*/

#include<iostream>
#include<string>
using namespace std;
string convert(int year);             //function prototype

int main(){
    int inputYear{};
    do{                               //do-while loop for the input year
      cout << "Enter a year from 1 to 2023 (0 to quit): ";
      cin >> inputYear;                                            // input the year
      if (inputYear > 2023 || inputYear < 0){                           //invalid input handling
         cout << "Invalid year, try again" << endl;
      }
      else if (inputYear != 0){
        cout << inputYear << " = " << convert(inputYear) << endl;   //convert to roman numerals if input is in range
      }
    }
    while (inputYear != 0);               //if input year = 0, loop terminates
    return 0;
}


string convert(int year)
/*
Converting year numbers to Roman numerals 
Parameters: year in Arabic numerals, type is integers
Return translated Arabic numerals in Roman numerals
*/
{
    string romanNum{};
    while(year > 0){
        if ((year - 1000) >= 0){      //if year subtracted by 1000 is positive, add M to output and update the year
            romanNum += "M";
            year -= 1000;
        }
    
		else if ((year - 500) >= 0){  //if year subtracted by 500 is positive, add D to output and update the year
            romanNum += "D";
            year -= 500;
        }

       else if ((year - 100) >= 0){   //if year subtracted by 100 is positive, add C to output and update the year
            romanNum += "C";
            year -= 100;
        }

        else if ((year - 50) >= 0){   //if year subtracted by 50 is positive, add L to output and update the year
            romanNum += "L";
            year -= 50;
        }

        else if ((year - 10) >= 0){   //if year subtracted by 10 is positive, add X to output and update the year
            romanNum += "X";
            year -= 10;
        }

        else if ((year - 5) >= 0){    //if year subtracted by 5 is positive, add V to output and update the year
            romanNum += "V";
            year -= 5;
        }

        else if ((year - 1) >= 0){    //if year subtracted by 1 is positive, add I to output and update the year
            romanNum += "I";
            year -= 1;
        }
    }

    string fourHundred{"CCCC"}, nineHundred{"DCCCC"};
	if (romanNum.find(nineHundred) != string::npos){                           //if nine hundred in 4-Cs form is found
		romanNum.replace(romanNum.find(nineHundred), nineHundred.length(), "CM"); //replace with subtractive notation(CM)
	}
	else if (romanNum.find(fourHundred) != string::npos){                      //if four hundred in 4-Cs form is found
		romanNum.replace(romanNum.find(fourHundred), fourHundred.length(), "CD"); //replace with subtractive notation(CD)
	}
	
	string forty{"XXXX"}, ninety{"LXXXX"};
	if (romanNum.find(ninety) != string::npos){                       //if ninety in 4-Xs form is found
		romanNum.replace(romanNum.find(ninety), ninety.length(), "XC");  //replace with subtractive notation(XC)
	}
	else if (romanNum.find(forty) != string::npos){                   //if forty in 4-Xs form is found
		romanNum.replace(romanNum.find(forty), forty.length(), "XL");    //replace with subtractive notation(XL)
	}
	
	string four{"IIII"}, nine{"VIIII"};
	if (romanNum.find(nine) != string::npos){                         //if nine in 4-Is form is found
		romanNum.replace(romanNum.find(nine), nine.length(), "IX");      //replace with subtractive notation(IX)
	}
	else if (romanNum.find(four) != string::npos){                    //if four in 4-Is form is found
		romanNum.replace(romanNum.find(four), four.length(), "IV");      //replace with subtractive notation(IV)
	}
    return romanNum;
}

/*
Test cases:
- 1, 5, 10, 50, 100, 500, 1000: Number translated to a single character.
- 4, 9: Smallest number with subtractive notation.
- 49, 94: Two-digit numbers with subtractive notation in both digits.
- 494, 949: Three-digit numbers with subtractive notation in all three digits.
- 1444, 1494, 1949, 1999: Four-digit numbers with subtractive notation in the last three digits.
- 2023: Largest number possible.
- 1666: Number using every characters possible.
- -1, 2024: Invalid inputs.
- 0: Stops the program.
*/