#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "readingsFromRange.h"

TEST_CASE("test readings from ranges")
{
  int chargingSessionSamples[] = {4,5};
  REQUIRE(getReadingsFromRanges(chargingSessionSamples) == "4-5, 2");
}