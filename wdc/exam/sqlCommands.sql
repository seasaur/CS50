DROP DATABASE IF EXISTS Cinemas;
CREATE DATABASE Cinemas;
USE Cinemas;

CREATE TABLE Users (
  userID INT UNSIGNED NOT NULL AUTO_INCREMENT,
  email VARCHAR(63),
  password VARCHAR(63),
  PRIMARY KEY  (userID)
);

CREATE TABLE Films (
  filmID INT UNSIGNED NOT NULL AUTO_INCREMENT,
  name VARCHAR(63),
  dates DATE,
  time TIME,
  PRIMARY KEY  (filmID)
);

CREATE TABLE Seats (
  seatID INT UNSIGNED NOT NULL AUTO_INCREMENT,
  seat VARCHAR(3),
  booked BOOLEAN,
  filmID INT UNSIGNED NOT NULL,
  PRIMARY KEY  (seatID),
  FOREIGN KEY (filmID) REFERENCES Films (filmID)
);

CREATE TABLE Bookings (
  seatID INT UNSIGNED NOT NULL,
  userID INT UNSIGNED NOT NULL,
  FOREIGN KEY (seatID) REFERENCES Seats (seatID),
  FOREIGN KEY (userID) REFERENCES Users (userID)
);

INSERT INTO Users VALUES (1, 'sea@gmail.com', 'sea123');
INSERT INTO Films VALUES (1,'Mission Impossible', '2022-06-16','10:00:00');
INSERT INTO Films VALUES (2,'Mission Impossible', '2022-06-16','22:00:00');
INSERT INTO Films VALUES (3,'Xmen', '2022-06-16','13:00:00');
INSERT INTO Films VALUES (4,'Xmen', '2022-06-16','19:00:00');
INSERT INTO Seats VALUES (1, 'A01', true, 1);
INSERT INTO Seats VALUES (2, 'A02', false, 1);
INSERT INTO Seats VALUES (3, 'B01', false, 1);
INSERT INTO Seats VALUES (4, 'B02', false, 1);
INSERT INTO Seats VALUES (5, 'C01', true, 1);
INSERT INTO Seats VALUES (6, 'C02', false, 1);
INSERT INTO Bookings VALUES (1, 1);
INSERT INTO Bookings VALUES (3, 1);

UPDATE Customers
SET ContactName='Juan'
WHERE Country='Mexico';