#include "readingsFromRange.h"
#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;
std::map<std::string, int> storeRangeAndReadings;

std::map<std::string, int> getReadingsFromRanges(const int *chargingSessionSamples, int size)
{
    int readings = 0;
    int previousValue = chargingSessionSamples[0];
    int startRangeValue;

    for (int i = 0; i < size; i++)
    {
        if ((previousValue == chargingSessionSamples[i]) || ((previousValue + 1) == chargingSessionSamples[i]))
        {
            ++readings;
            previousValue = chargingSessionSamples[i];
            if (readings == 1)
            {
                startRangeValue = chargingSessionSamples[i];
            }
        }
        else
        {
            std::string storeInMap = to_string(startRangeValue) + "-" + to_string(previousValue);
            storeRangeAndReadings.insert(std::pair<std::string, int>(storeInMap, readings));
            std::cout << storeRangeAndReadings.find(storeInMap)->second << endl;
            std::cout << storeRangeAndReadings.size() << endl;
            readings = 1;
            previousValue = chargingSessionSamples[i];
            startRangeValue = chargingSessionSamples[i];
        }
    }
    return storeRangeAndReadings;
}