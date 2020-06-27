#ifndef TESTBUILDERS_WORKSHOP_TESTS_DOMAIN_BOOK_NOVEL_TEST_BUILDER_H_INCLUDED
#define TESTBUILDERS_WORKSHOP_TESTS_DOMAIN_BOOK_NOVEL_TEST_BUILDER_H_INCLUDED

#include "domain/book/Novel.h"
#include "AuthorTestBuilder.h"

namespace domain
{
   namespace book
   {
      class NovelTestBuilder
      {
      public:
         Novel build()
         {
            return Novel("A book about...", 3.99, anAuthor().build(), country::Language::ENGLISH, std::vector<Genre>());
         }
      };

      NovelTestBuilder aNovel()
      {
         return {};
      }
   }
}

#endif //TESTBUILDERS_WORKSHOP_TESTS_DOMAIN_BOOK_NOVEL_TEST_BUILDER_H_INCLUDED
