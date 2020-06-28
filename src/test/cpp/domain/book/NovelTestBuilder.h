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
         NovelTestBuilder& costing(double price)
         {
            this->price_ = price;
            return *this;
         }

         Novel build() const
         {
            return Novel("A book about...", price_, anAuthor().build(), country::Language::ENGLISH, std::vector<Genre>());
         }

      private:
         double price_ = 3.99;
      };

      inline NovelTestBuilder aNovel()
      {
         return {};
      }
   }
}

#endif //TESTBUILDERS_WORKSHOP_TESTS_DOMAIN_BOOK_NOVEL_TEST_BUILDER_H_INCLUDED
