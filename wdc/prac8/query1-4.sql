SELECT DISTINCT address.address
FROM address
INNER JOIN store
ON store.address_id=address.address_id
INNER JOIN inventory
ON inventory.store_id=store.store_id
INNER JOIN film
ON film.film_id=inventory.film_id
WHERE film.title= 'TWISTED PIRATES';