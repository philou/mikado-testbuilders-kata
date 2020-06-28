#include "gtest/gtest.h"
#include "report/ReportGenerator.h"
#include "finance/CurrencyConverter.h"
#include "purchase/Invoice.h"
#include "domain/book/Book.h"
#include "domain/book/Novel.h"
#include "purchase/PurchasedBook.h"
#include "storage/InMemoryRepository.h"
#include "purchase/InvoiceTestBuilder.h"

using namespace std;
using namespace domain::book;
using namespace domain::country;
using namespace purchase;
using namespace report;

TEST(ReportGeneratorTest, converts_invoice_amounts_to_USD_before_summing_them)
{
   auto invoice = anInvoice().build();
   ReportGenerator reportGenerator;

   EXPECT_EQ(
      finance::toUSD(invoice.computeTotalAmount(), invoice.getCountry().getCurrency()),
      reportGenerator.getTotalAmount()
   );
}