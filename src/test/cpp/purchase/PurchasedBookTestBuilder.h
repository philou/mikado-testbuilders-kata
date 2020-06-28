#ifndef TESTBUILDERS_WORKSHOP_TESTS_PURCHASE_PURCHASED_BOOK_TEST_BUILDER_H_INCLUDED
#define TESTBUILDERS_WORKSHOP_TESTS_PURCHASE_PURCHASED_BOOK_TEST_BUILDER_H_INCLUDED

#include "purchase/PurchasedBook.h"
#include "domain/book/NovelTestBuilder.h"

namespace purchase
{
   class PurchasedBookTestBuilder
   {
   public:

      PurchasedBook build()
      {
         return PurchasedBook(std::make_shared<domain::book::Novel>(domain::book::aNovel().build()), 1);
      }
   };

   PurchasedBookTestBuilder aPurchasedBook()
   {
      return {};
   }
}

#endif //TESTBUILDERS_WORKSHOP_TESTS_PURCHASE_INVOICE_TEST_BUILDER_H_INCLUDED
