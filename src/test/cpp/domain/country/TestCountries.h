#ifndef TESTBUILDERS_WORKSHOP_TESTS_DOMAIN_COUNTRY_TEST_COUNTRIES_H_INCLUDED
#define TESTBUILDERS_WORKSHOP_TESTS_DOMAIN_COUNTRY_TEST_COUNTRIES_H_INCLUDED

#include "domain/country/Country.h"

namespace domain
{
   namespace country
   {
      namespace test_countries
      {
         const Country USA("USA", US_DOLLAR, ENGLISH);
         const Country France("France", EURO, FRENCH);
      }
   }
}



#endif //TESTBUILDERS_WORKSHOP_TESTS_DOMAIN_COUNTRY_TEST_COUNTRIES_H_INCLUDED