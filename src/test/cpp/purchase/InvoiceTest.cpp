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

   Invoice invoice("John Doe", france);

//   EXPECT_EQ(bookPrice * rate, invoice.computeTotalAmount);
}