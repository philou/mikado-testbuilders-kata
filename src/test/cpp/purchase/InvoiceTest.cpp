#include "gtest/gtest.h"
#include "purchase/Invoice.h"
#include "finance/TaxRule.h"
#include "domain/book/Book.h"
#include "domain/book/Novel.h"
#include "purchase/PurchasedBook.h"

using namespace std;
using namespace domain::book;
using namespace domain::country;
using namespace purchase;

TEST(InvoiceTest, total_amount_is_converted_to_currency_of_invoice_country_at_current_rate)
{
   Country france("France", Currency::EURO, Language::FRENCH);
   Country usa("USA", Currency::US_DOLLAR, Language::ENGLISH);
   Author steinbeck("John Steinbeck", usa);
   auto grapesOfWrath = make_shared<Novel>("Grapes of Wrath", 7.99, steinbeck, Language::ENGLISH, vector<Genre>());

   Invoice invoice("John Doe", france);
//   invoice.addPurchasedBook(grapesOfWrath, 1);

   double rate = finance::getApplicableRate(invoice.getCountry(), *grapesOfWrath);

   //EXPECT_EQ(grapesOfWrath.getPrice() * rate, invoice.computeTotalAmount());
}