#include "gtest/gtest.h"
#include "purchase/Invoice.h"
#include "finance/TaxRule.h"
#include "domain/book/Book.h"
#include "domain/book/Novel.h"
#include "purchase/PurchasedBook.h"
#include "InvoiceTestBuilder.h"

using namespace std;
using namespace domain::book;
using namespace domain::country;
using namespace domain::country::test_countries;
using namespace purchase;

TEST(InvoiceTest, total_amount_is_converted_to_currency_of_invoice_country_at_current_rate)
{
   //auto novel = aNovel()
   //   .costing(7.99)
   //   .build();

   auto invoice = anInvoice()
      .from(France)
      .build();

   //EXPECT_EQ(
   //   book.getPrice() * finance::getApplicableRate(invoiceCountry, book),
   //   invoice.computeTotalAmount());
}