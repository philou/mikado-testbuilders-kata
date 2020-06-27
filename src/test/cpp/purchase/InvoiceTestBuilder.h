#ifndef TESTBUILDERS_WORKSHOP_TESTS_PURCHASE_INVOICE_TEST_BUILDER_H_INCLUDED
#define TESTBUILDERS_WORKSHOP_TESTS_PURCHASE_INVOICE_TEST_BUILDER_H_INCLUDED
#include "domain/country/TestCountries.h"

namespace purchase
{
   class InvoiceTestBuilder
   {
   public:

      Invoice build()
      {
         return Invoice("John Doe", domain::country::test_countries::France);
      }
      
   };

   InvoiceTestBuilder anInvoice()
   {
      return {};
   }
}

#endif //TESTBUILDERS_WORKSHOP_TESTS_PURCHASE_INVOICE_TEST_BUILDER_H_INCLUDED
