#ifndef TESTBUILDERS_WORKSHOP_TESTS_PURCHASE_PURCHASED_BOOK_TEST_BUILDER_H_INCLUDED
#define TESTBUILDERS_WORKSHOP_TESTS_PURCHASE_PURCHASED_BOOK_TEST_BUILDER_H_INCLUDED

#include "purchase/PurchasedBook.h"
#include "domain/book/NovelTestBuilder.h"

namespace purchase
{
   class PurchasedBookTestBuilder
   {
   public:
      PurchasedBookTestBuilder& of(const domain::book::Novel& novel)
      {
         this->book_ = std::make_shared<domain::book::Novel>(novel);
         return *this;
      }

      PurchasedBook build() const
      {
         return PurchasedBook(book_, 1);
      }

   private:
      std::shared_ptr<domain::book::Novel> book_ = 
         std::make_shared<domain::book::Novel>(domain::book::aNovel().build());
   };

   inline PurchasedBookTestBuilder aPurchasedBook()
   {
      return {};
   }
}

#endif //TESTBUILDERS_WORKSHOP_TESTS_PURCHASE_INVOICE_TEST_BUILDER_H_INCLUDED
