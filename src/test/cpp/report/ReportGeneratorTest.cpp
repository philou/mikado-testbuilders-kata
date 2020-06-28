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

class ReportGeneratorTest : public ::testing::Test
{
protected:
   void TearDown() override
   {
      main_repository::reset();
   }
};

TEST_F(ReportGeneratorTest, converts_invoice_amounts_to_USD_before_summing_them)
{
   main_repository::override(std::make_shared<storage::InMemoryRepository>());

   auto invoice = anInvoice().build();
   ReportGenerator reportGenerator;

   EXPECT_EQ(
      finance::toUSD(invoice.computeTotalAmount(), invoice.getCountry().getCurrency()),
      reportGenerator.getTotalAmount()
   );
}