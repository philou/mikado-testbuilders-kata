#ifndef TESTBUILDERS_WORKSHOP_TESTS_DOMAIN_BOOK_AUTHOR_TEST_BUILDER_H_INCLUDED
#define TESTBUILDERS_WORKSHOP_TESTS_DOMAIN_BOOK_AUTHOR_TEST_BUILDER_H_INCLUDED

#include "domain/country/TestCountries.h"
#include "domain/book/Author.h"

namespace domain
{
   namespace book
   {
      class AuthorTestBuilder
      {
      public:
         Author build()
         {
            return Author("Pen writer", country::test_countries::USA);
         }
      };

      inline AuthorTestBuilder anAuthor()
      {
         return {};
      }
   }
}

#endif //TESTBUILDERS_WORKSHOP_TESTS_DOMAIN_BOOK_AUTHOR_TEST_BUILDER_H_INCLUDED
