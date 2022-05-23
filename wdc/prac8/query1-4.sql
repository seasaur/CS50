SELECT address.address, address.address2
FROM film
INNER JOIN inventory
ON film_id='918' AND mark<50 AND inventory.store_id = store.store_id;

- film id 918
- get address id that has film id (only one address id, no duplicates)
- get address from address table from address id
- only one address per store
