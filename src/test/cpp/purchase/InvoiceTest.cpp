#include "gtest/gtest.h"
#include "purchase/Invoice.h"

using namespace std;

TEST(InvoiceTest, total_amount_is_converted_to_invoice_currency_at_current_rate)
{
   purchase::Invoice invoice;
   // create an invoice with a different currency

   const auto totalAmount = invoice.computeTotalAmount();

   // assert that it is as expected
}