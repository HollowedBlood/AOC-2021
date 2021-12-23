#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
void printVector(vector<float> printing) {
    cout << "[ ";;
    for (int i = 0; i < printing.size(); i++)
    {
        cout <<", " << printing[i];
    }
    cout << "]" << endl;
}

void printDoubleVector(vector<vector<float>> printing) {
    for (int i = 0; i < printing.size(); i++)
    {
        printVector(printing[i]);
    }
}

int getCommonBitOfRow(vector<vector<float>> reading, int column) {
    float tally = 0;
    
    for (int i = 0; i < reading.size(); i++) 
    {
        tally += reading[i][column];
    }
    
    if (reading.size()/tally <= 2 || reading.size() / tally == 1)
    {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{

    fstream newfile;
    newfile.open("Input.txt", ios::in);
    
    if (newfile.is_open())
    {
    
        string currentReading;
        
        int index = 0;
        
        vector<float> inputTally;
        vector<vector<float>> inputVector;

        while (getline(newfile, currentReading)) {
    
            vector<float> row;
                        
            if (index == 0)
            {

                for (int i = 0; i < currentReading.length(); i++)
                {
                    inputTally.push_back(0);
                }

            }

            for (int i = 0; i < currentReading.length(); i++) 
            {
                row.push_back(currentReading[i] - 48);
                inputTally[i] += currentReading[i] - 48;
            }

            inputVector.push_back(row);
            index++;
        }
        
        vector < vector<float>> oxygenGen = inputVector, scrubber = inputVector;

        for (int i = 0; i < inputVector.front().size(); i++)
        {
            int commonBitOxy = getCommonBitOfRow(oxygenGen, i);
            int uncommonBitScr;
            if (getCommonBitOfRow(scrubber, i) == 1) {
                uncommonBitScr = 0;
            }
            else
            {
                uncommonBitScr = 1;
            }

            //cout << "_" << i << "_" << endl << commonBitOxy << "|" << uncommonBitScr << endl;


            for (int j = 0; j < oxygenGen.size() && oxygenGen.size() != 1; j++)
            {
                if(oxygenGen[j][i] != commonBitOxy)
                {
                    oxygenGen.erase(oxygenGen.begin() + j);
                    j--;
                }
            }

            for (int j = 0; j < scrubber.size() && scrubber.size() != 1; j++)
            {
                if (scrubber[j][i] != uncommonBitScr)
                {
                    scrubber.erase(scrubber.begin() + j);
                    j--;
                }
            }
        }
        
        string gamma, epsilon, oxygenReading, scrubberReading;
        for (int i = 0; i < inputVector.front().size(); i++)
        {
            if (oxygenGen[0][i] == 1) 
            {
                oxygenReading.append("1");
            }
            else
            {
                oxygenReading.append("0");
            }
            if (scrubber[0][i] == 1)
            {
                scrubberReading.append("1");
            }
            else
            {
                scrubberReading.append("0");
            }
        }


        for (int i = 0; i < inputTally.size(); i++)
        {

            if (index / inputTally[i] <= 2)
            {

                gamma.append("1");
                epsilon.append("0");
            }
            else
            {

                gamma.append("0");
                epsilon.append("1");
            }
        }
        
        long parsedGamma = stol(gamma, nullptr, 2);
        long parsedEpsilon = stol(epsilon, nullptr, 2);
        long parsedOxygen = stol(oxygenReading, nullptr, 2);
        long parsedScrubber = stol(scrubberReading, nullptr, 2);
        
        cout << "gamma:   " << gamma << " - Parsed: " << parsedGamma << endl;
        cout << "epsilon: " << epsilon << " - Parsed: " << parsedEpsilon << endl;
        cout << "Product: " << parsedGamma * parsedEpsilon << endl;
        cout << "Oxygen:  " << oxygenReading << " - Parsed: " << parsedOxygen << endl;
        cout << "CO2:     " << scrubberReading << " - Parsed: " << parsedScrubber << endl;
        cout << "Product: " << parsedOxygen * parsedScrubber << endl;

        newfile.close();
    }   

}