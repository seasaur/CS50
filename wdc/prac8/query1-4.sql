SELECT store.address
FROM film
INNER JOIN inventory ON film_id='918' AND mark<50 AND inventory.store_id = store.store_id;

- film id 918
- address of every store with the film id
- get address from address table from address id
- only one address per store
