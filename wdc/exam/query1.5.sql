SELECT Films.name, Seats.seat
FROM Seats
INNER JOIN Films
ON Seats.filmID=Films.filmID
WHERE dates = '2022-06-20' AND booked=true;