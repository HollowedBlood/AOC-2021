#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main()
{
    int distance = 0, depth = 0, aim = 0;
    fstream newfile;
    newfile.open("Input.txt", ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) {   //checking whether the file is 
        string currentText;

        while (getline(newfile, currentText)) {  //read data from file object and put it into string.
            
            enum directions {forward, up, down, invalid};
            directions currentDirection = invalid;
            if (currentText.substr(0, currentText.find(" ")) == "forward") {
                currentDirection = forward;
            }
            else if (currentText.substr(0, currentText.find(" ")) == "up")
            {
                currentDirection = up;
            }
            else if (currentText.substr(0, currentText.find(" ")) == "down")
            {
                currentDirection = down;
            }
            else
            {
                currentDirection = invalid;
            }

            int movement = stoi(currentText.substr(currentText.find(" ") + 1));

            switch (currentDirection)
            {
            default:
                cout << "how are you even here?!" << endl;
                break;
            case forward:
                cout << "forward " << movement << endl;
                distance += movement;
                depth += movement * aim;
                break;
            case up:
                cout << "up " << movement << endl;
                aim -= movement;
                break;
            case down: 
                cout << "down " << movement << endl;
                aim += movement;
                break;
            }

        }
    }
    newfile.close();   //close the file object.
    cout << "distance: " << distance << ", depth: " << depth << ", product: " << distance*depth << endl;
}
