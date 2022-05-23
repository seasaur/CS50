SELECT inventory.film_id store.store_id
FROM film
INNER JOIN inventory ON film_id='918' AND mark<50 AND Students.student_id = Enrolments.student_id;

- film id 918
- address of every store with the film id
- only one address per store
