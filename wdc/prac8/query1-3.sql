SELECT customer.first_name, customer.last_name, rental.rental_date
FROM customer
INNER JOIN rental
ON customer.customer_id=rental.customer_id
WHERE rental.return_date=null
ORDER BY rental_date ASC
LIMIT 1;