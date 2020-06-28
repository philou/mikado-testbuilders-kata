#ifndef TESTBUILDERS_WORKSHOP_TESTS_PURCHASE_INVOICE_TEST_BUILDER_H_INCLUDED
#define TESTBUILDERS_WORKSHOP_TESTS_PURCHASE_INVOICE_TEST_BUILDER_H_INCLUDED

#include "domain/country/TestCountries.h"
#include "PurchasedBookTestBuilder.h"

namespace purchase
{
   class InvoiceTestBuilder
   {
   public:

      InvoiceTestBuilder& from(domain::country::Country country)
      {
         this->country_ = std::make_shared<domain::country::Country>(country);
         return *this;
      }

      InvoiceTestBuilder& with(const PurchasedBookTestBuilder& purchasedBook)
      {
         this->purchasedBooks_.push_back(std::make_shared<PurchasedBook>(purchasedBook.build()));
         return *this;
      }

      Invoice build() const
      {
         Invoice result("John Doe", domain::country::Country(*country_));
         result.addPurchasedBooks(purchasedBooks_);
         return result;
      }

   private:
      std::shared_ptr<domain::country::Country> country_ = 
         std::make_shared<domain::country::Country>(domain::country::test_countries::USA);

      std::vector<std::shared_ptr<const PurchasedBook>> purchasedBooks_;
   };

   inline InvoiceTestBuilder anInvoice()
   {
      return {};
   }
}

#endif //TESTBUILDERS_WORKSHOP_TESTS_PURCHASE_INVOICE_TEST_BUILDER_H_INCLUDED
