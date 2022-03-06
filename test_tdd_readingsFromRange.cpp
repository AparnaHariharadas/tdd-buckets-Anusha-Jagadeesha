#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "readingsFromRange.h"
#include <map>
#include <bits/stdc++.h>

TEST_CASE("test readings from ranges")
{
    int chargingSessionSamples[] = {4, 5};
    int size = sizeof(chargingSessionSamples) / sizeof(chargingSessionSamples[0]);
    std::map<std::string, int> out = getReadingsFromRanges(chargingSessionSamples, size);

    std::map<std::string, int>::iterator iter;
    std::cout << "charging samples" << std::endl;
    for (iter = out.begin(); iter != out.end(); iter++)
    {
        REQUIRE(iter->first == "4-4");
        REQUIRE(iter->second == 2);
    }
}

TEST_CASE("test readings from different range")
{
    int chargingSamples[] = {3, 3, 4, 5, 10, 11, 12};
    int size = sizeof(chargingSamples) / sizeof(chargingSamples[0]);
    std::map<std::string, int> testOutMap = getReadingsFromRanges(chargingSamples, size);

    std::map<std::string, int>::iterator it;
    std::cout << "charging samples from diff range" << std::endl;
    for (it = testOutMap.begin(); it != testOutMap.end(); it++)
    {
        REQUIRE(it->first == "3-5");
        REQUIRE(it->second == 4);

        REQUIRE(it->first == "10-12");
        REQUIRE(it->second == 3);
    }
}