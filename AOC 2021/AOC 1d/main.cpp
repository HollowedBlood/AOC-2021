#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;




int main()
{
    fstream newfile;
    int increases = 0;

    newfile.open("Input.txt", ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) {   //checking whether the file is open
        string currentText;
        int currentNum, lastNum, firstNum, currentSum, lastSum;
        int index = 0;
        
        while (getline(newfile, currentText)) {  //read data from file object and put it into string.
            currentNum = stoi(currentText);

            if (index < 2)
            {
                cout << "No sums" << endl;
            }
            else if (index == 2)
            {
                currentSum = currentNum + lastNum + firstNum;
                cout << "currentSum: " << currentSum << ", No previous sum" << endl;
                lastSum = currentSum;
            }
            else
            {
                currentSum = currentNum + lastNum + firstNum;
                if (currentSum > lastSum)
                {
                    cout << "currentSum: " << currentSum << ", Is greater than previous sum" << endl;
                    lastSum = currentSum;
                    increases++;
                }
                else if (currentSum < lastSum)
                {
                    cout << "currentSum: " << currentSum << ", Is less than previous sum" << endl;
                    lastSum = currentSum;
                }
                else
                {
                    cout << "currentSum: " << currentSum << ", No change" << endl;
                    lastSum = currentSum;
                }
            }


            if (index > 0) {
                firstNum = lastNum;
            }            
            lastNum = stoi(currentText);
            index++;
        }
        
        newfile.close();   //close the file object.
    }

    cout << "the total number of increases was: " << increases << endl;
    
}
