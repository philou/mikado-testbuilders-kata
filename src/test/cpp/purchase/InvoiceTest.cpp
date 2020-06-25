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
   auto grapesOfWrath = std::make_shared<Novel>(
      "Grapes of Wrath", 
      6.99, 
      Author("John Steinbeck", Country("USA", US_DOLLAR, ENGLISH)), 
      ENGLISH, 
      std::vector<Genre>());

   Invoice invoice("John Doe", Country("France", EURO, FRENCH));
   invoice.addPurchasedBook(std::make_shared<PurchasedBook>(grapesOfWrath, 1));

   const auto totalAmount = invoice.computeTotalAmount();

   EXPECT_EQ(
      grapesOfWrath->getPrice() * finance::getApplicableRate(invoice.getCountry(), *grapesOfWrath), 
      totalAmount);
}