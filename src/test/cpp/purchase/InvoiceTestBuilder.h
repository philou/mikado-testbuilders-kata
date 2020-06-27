#ifndef TESTBUILDERS_WORKSHOP_TESTS_PURCHASE_INVOICE_TEST_BUILDER_H_INCLUDED
#define TESTBUILDERS_WORKSHOP_TESTS_PURCHASE_INVOICE_TEST_BUILDER_H_INCLUDED

#include "domain/country/TestCountries.h"

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

      Invoice build()
      {
         return Invoice("John Doe", domain::country::Country(*country_));
      }

   private:
      std::shared_ptr<domain::country::Country> country_ = 
         std::make_shared<domain::country::Country>(domain::country::test_countries::USA);
   };

   InvoiceTestBuilder anInvoice()
   {
      return {};
   }
}

#endif //TESTBUILDERS_WORKSHOP_TESTS_PURCHASE_INVOICE_TEST_BUILDER_H_INCLUDED
