#include "gtest/gtest.h"
#include "report/ReportGenerator.h"
#include "finance/CurrencyConverter.h"
#include "purchase/Invoice.h"
#include "domain/book/Book.h"
#include "domain/book/Novel.h"
#include "purchase/PurchasedBook.h"
#include "storage/InMemoryRepository.h"

using namespace std;
using namespace domain::book;
using namespace domain::country;
using namespace purchase;
using namespace report;
using namespace storage;

class ReportGeneratorTest : public ::testing::Test
{
   void TearDown() override
   {
      main_repository::reset();
   }
};

TEST_F(ReportGeneratorTest, converts_invoice_amounts_to_USD_before_summing_them)
{
   main_repository::override(make_shared<InMemoryRepository>());

   Country france("France", Currency::EURO, Language::FRENCH);
   Country usa("USA", Currency::US_DOLLAR, Language::ENGLISH);

   //Author steinbeck("John Steinbeck", )

   //auto grapesOfWrath = make_shared<Novel>("Grapes of Wrath", 3.99, , Language::ENGLISH, vector<Genre>());

   Invoice invoice("John Doe", france);
   //invoice.addPurchasedBook(make_shared<PurchasedBook>(), 1)

   ReportGenerator reportGenerator;
   EXPECT_EQ(
      finance::toUSD(invoice.computeTotalAmount(), invoice.getCountry().getCurrency()),
      reportGenerator.getTotalAmount());
}