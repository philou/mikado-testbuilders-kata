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

TEST(ReportGeneratorTest, converts_invoice_amounts_to_USD_before_summing_them)
{
   auto grapesOfWrath = std::make_shared<Novel>(
      "Grapes of Wrath",
      6.99,
      Author("John Steinbeck", Country("USA", US_DOLLAR, ENGLISH)),
      ENGLISH,
      std::vector<Genre>());

   auto invoice = make_shared<Invoice>("John Doe", Country("France", EURO, FRENCH));
   invoice->addPurchasedBook(std::make_shared<PurchasedBook>(grapesOfWrath, 1));

   auto repository = make_shared<storage::InMemoryRepository>();
   repository->addInvoice(invoice);

   main_repository::override(repository);

   ReportGenerator reportGenerator;

   const auto totalAmount = reportGenerator.getTotalAmount();

   EXPECT_EQ(finance::toUSD(invoice->computeTotalAmount(), invoice->getCountry().getCurrency()), totalAmount);
}