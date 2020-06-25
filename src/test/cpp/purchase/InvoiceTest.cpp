#include "gtest/gtest.h"
#include "purchase/Invoice.h"
#include "finance/TaxRule.h"
#include "domain/book/Book.h"
#include "domain/book/Novel.h"
#include "purchase/PurchasedBook.h"

using namespace std;

TEST(InvoiceTest, total_amount_is_converted_to_currency_of_invoice_country_at_current_rate)
{
   auto grapesOfWrath = std::make_shared<domain::book::Novel>(
      "Grapes of Wrath", 
      6.99, 
      domain::book::Author("John Steinbeck", domain::country::Country("USA", domain::country::Currency::US_DOLLAR, domain::country::Language::ENGLISH)), 
      domain::country::Language::ENGLISH, 
      std::vector<domain::book::Genre>());

   purchase::Invoice invoice("John Doe", domain::country::Country("France", domain::country::Currency::EURO, domain::country::Language::FRENCH));
   invoice.addPurchasedBook(std::make_shared<purchase::PurchasedBook>(grapesOfWrath, 1));
   // create an invoice with a different currency

   const auto totalAmount = invoice.computeTotalAmount();

   EXPECT_EQ(
      grapesOfWrath->getPrice() * finance::getApplicableRate(invoice.getCountry(), *grapesOfWrath), 
      totalAmount);
}