/*
@ Author: Ryan Dawson & Long Pham

@ Description: A program that uses c-style strings and arrays with three stages of increasing complexity 
to find DNA string segments and report their positions, including reverse fragments and overlaps.

@ Date: 2023 - 3 - 03
@ Upated date: 2023 - 3 - 06

Ryan: Wrote paper plan,comments and tier 3
Long: Wrote main function and tier 1 and 2
*/
#include<iostream>                                                                  // For input/output 
#include<cstring>                                                                   // For c-style string manipulator
#include<vector>                                                                    // For vector containing indexes
#include<algorithm>                                                                 // For checking if index already in vector (count function)
using namespace std;                                                                // Used for the standard namespaces

void dnaSearch(const char [], const char[]);                                        // Function that searches for fragments
vector <int> indexes{};                                                             

int main (){                                                                        // The start point of the program
    char inputDonor [100] {};                                                       // Declare and initialize array for donor string 
    char inputFrag [100] {};                                                        // Declare and initialize array for fragment string 
    int numFrag {};                                                                 // Declare integer for fragment search


    cout << "Input: \n";                                                            // Ask for user input 
    cin >> inputDonor;                                                              // For donor string input 
    cout << "Number of fragments to search: " << endl;                              // Ask for user input
    cin >> numFrag;                                                                 // Reading in the fragments

    for(size_t i{}; i < numFrag; i++){                                              // Loop for each fragment
        cin >> inputFrag;                                                           // Read the fragment 
        dnaSearch(inputDonor, inputFrag);                                           // Call for search for current fragment
        }
    return 0;
}

void dnaSearch(const char donorString [], const char fragment []){                  // Searching for fragments
    /*
    Search for dna fragment, including reverse and overlap
    Parameters: two array of characters
    Return nothing
    */
    char piece [strlen(fragment)];                                                  // Declare character array to take out strlen(fragment) number of characters at a time

    for (size_t i{}; i <= strlen(donorString) - strlen(fragment); i++){             // Looping through the donor string
        for (size_t j {}; j < strlen(fragment); j++){                               // Looping through strlen(fragment) number of chars
            piece[j] = donorString[i + j];                                          // Take out pieces of donor string and compare with fragment
            }
        
        
        char fragReverse[strlen(fragment) + 1];                                    // Reverse the fragment
        int r{};
        for (int i{strlen(fragment) - 1}; i >= 0; i--){
            fragReverse[r] = fragment[i];
            r++;
        }

        //Forward
        if (strncmp(piece, fragment, strlen(fragment)) == 0){                       // If fragment equals taken-out string
            cout << fragment << " is found at index " << i << endl;                 // Print for user


            for(size_t j{i};j < i + strlen(fragment); j++){
                if(count(indexes.begin(), indexes.end(), j) != 0){                  // If indexes of fragment is already in vector
                cout << "overlap\n";                                                // Reports overlap
                break;
                }
            }
            
            for (size_t k{i}; k < i + strlen(fragment); k++){
                if(count(indexes.begin(), indexes.end(), k) == 0)                  // Add indexes of fragment into vector
                    {indexes.push_back(k);}
            }

                
            return;
        }

        //Backward
        if (strncmp(piece, fragReverse, strlen(fragment)) == 0){                    // If fragment equals taken-out string
            cout << fragment << " is found at index " << i << endl;                 // Print for user

            for(size_t j{i};j < i + strlen(fragment); j++){
                if(count(indexes.begin(), indexes.end(), j) != 0){                 // If indexes of fragment is already in vector
                cout << "overlap\n";                                               // Reports overlap
                break;
                }
            }

            for (size_t j{i}; j < i + strlen(fragment); j++){
                if(count(indexes.begin(), indexes.end(), j) == 0)                  // Add indexes of fragment into vector
                    {indexes.push_back(j);}
            }

            return;
        } 
        
    }
    cout << fragment << " is not found \n";

}



