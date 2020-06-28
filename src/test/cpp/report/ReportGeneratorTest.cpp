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
   void SetUp() override
   {
      main_repository::override(in_memory_repository_);
   }

   void TearDown() override
   {
      main_repository::reset();
   }

   std::shared_ptr<storage::InMemoryRepository> in_memory_repository_
      = std::make_shared<storage::InMemoryRepository>();
};

TEST_F(ReportGeneratorTest, converts_invoice_amounts_to_USD_before_summing_them)
{
   auto invoice = std::make_shared<Invoice>(anInvoice()
      .from(test_countries::France)
      .with(aPurchasedBook())
      .build());

   in_memory_repository_->addInvoice(invoice);
   ReportGenerator reportGenerator;

   EXPECT_EQ(
      finance::toUSD(invoice->computeTotalAmount(), invoice->getCountry().getCurrency()),
      reportGenerator.getTotalAmount()
   );
}