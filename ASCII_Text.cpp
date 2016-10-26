#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int L;                      
    std::cin >> L; std::cin.ignore();       //read in length of characaters, ignores \n
    int H;
    std::cin >> H; std::cin.ignore();       //read in height of characters, ignores \n
    std::string T;                          //creates the string T
    std::getline(std::cin, T);                   //reads the strong in  and stores it in T
    
    //input of ASCII characters depending on program provided H and L
    //create a vector of strings
    
    std::string charString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?";  //creates character string
    std::vector<std::string> asciiChars;         //creates a vector of strings to take in the ASCII chars
                                                //each element of the vector is one line of the chars.
    for (int i = 0; i < H; i++) {           
        std::string ROW;  //create ROW string
        std::getline(std::cin, ROW);
        asciiChars.push_back(ROW);  //add the ASCII line to the char vector
                                                        //it will be at the end of the vector.
    }
    
    //begin output operation
    //***********************
    //algorithm is as follows:
    //*STORE THE OUTPUT IN AN OUTPUT VECTOR*
    //1.  get first character in the T string.
    //2.  determine if the character is A-Z or a-z, if it's not, convert to
    //uppercase or questionmark.
    //3.  search the charString for the poistion of the character just obtained.
    //4.  use the position number and multiply by the length of the letter L to obtain starting index
    //of ASCII string.  ending index is that + L.  Save both those numbers.
    //5.  continue this process until the end of the string is reached.  add that to end of output
    //string.
    //6.  repeat the entire process until the height of the characters H is reached.
    //keep adding to end of output vector until termination is achieved.
    //7.loop through the output.
    
    std::vector<std::string> outputVector(H,""); //the output vector of size H with each filled with a nullspace.
    //loop through the height of the outputs.
    for (int hMovement = 0; hMovement < H; ++hMovement) //will add results to output vector
    {
        //loop through input string.
        for (size_t i = 0; i < T.length(); ++i)
        {
            //grab element of T string, convert to uppercase.
            char tempChar = toupper(T[i]); //converts to uppercase.
            //checks the limiting condition
            if (tempChar < 'A' || tempChar > 'Z')
            {
                tempChar = '?';
            }
            
            size_t tempPosition = charString.find(tempChar); //returns the position of the char in the string.
            
            //Adds the ASCII text to the string that is part of the string vector.
            std::string tempSubStr = asciiChars[hMovement].substr(tempPosition*L, L);
            
            //adds the substring to the corresponding line of the output vector.
            outputVector[hMovement] += tempSubStr;  //adds to line.
        }
    } // end of output gathering.
            
    
    //Begin output.
    for (int i = 0; i < H; ++i)
    {
        std::cout << outputVector[i] << std::endl;
    }
}
