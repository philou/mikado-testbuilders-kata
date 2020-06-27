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
   Country france("France", Currency::EURO, Language::FRENCH);
   //Invoice invoice("John Doe", Country)
   //EXPECT_EQ(finance::toUSD(invoice...), reportGenerator.getTotalAmount());
}