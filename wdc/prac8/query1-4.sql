SELECT film.film_id, film.title
FROM film
WHERE film.title= "TWISTED PIRATES"
INNER JOIN inventory
ON film_id='918' AND mark<50 AND inventory.store_id = store.store_id;

- film id 918
- stores table- get address id that has film id (only one address id, no duplicates)
- address table- get address from address table from address id
- only one address per store
