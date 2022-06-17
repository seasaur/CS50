var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

router.get('/dates', function(req, res, next) {
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "SELECT dates FROM Films;";
    connection.query(query, function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      console.log(rows);
      res.json(rows);
    });
  });
});

router.get('/name', function(req, res, next) {
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "SELECT DISTINCT name FROM Films;";
    connection.query(query, function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      console.log(rows);
      res.json(rows);
    });
  });
});

var dates;
var name;

router.post('/storage', function(req, res, next) {
      dates=req.body.dates;
      name=req.body.name;
      console.log(dates, "index dates");
      console.log(name, "index name");
      res.end();

});

router.get('/searchSeats', function(req, res, next) {
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "SELECT Films.name, Films.dates, Films.time, Seats.seatID, Seats.seat, Seats.booked FROM Seats INNER JOIN Films ON Seats.filmID=Films.filmID WHERE dates = ? AND name = ?;";
    connection.query(query, [dates, name], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
        console.log(rows, "both yay");
        res.json(rows);
    });
  });
});

router.get('/any', function(req, res, next) {
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "SELECT Films.name, Films.dates, Films.time, Seats.seatID, Seats.seat, Seats.booked FROM Seats INNER JOIN Films ON Seats.filmID=Films.filmID";
    connection.query(query, function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
        console.log(rows, "any yay");
        res.json(rows);
    });
  });
});

router.get('/datesAny', function(req, res, next) {
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "SELECT Films.name, Films.dates, Films.time, Seats.seatID, Seats.seat, Seats.booked FROM Seats INNER JOIN Films ON Seats.filmID=Films.filmID WHERE name = ?;";
    connection.query(query, [name], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
        console.log(rows, "dates yay");
        res.json(rows);
    });
  });
});

router.get('/nameAny', function(req, res, next) {
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "SELECT Films.name, Films.dates, Films.time, Seats.seatID, Seats.seat, Seats.booked FROM Seats INNER JOIN Films ON Seats.filmID=Films.filmID WHERE dates = ?;";
    connection.query(query, [dates], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
        console.log(rows, "name yay");
        res.json(rows);
    });
  });
});

router.post('/book', function(req, res, next) { //account route: send updated user info to database
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "UPDATE Seats SET booked = true WHERE seatID = ?;";
    connection.query(query, [req.body.seatID], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      res.end();
    });
  });
});

var currentUser = 1; //as login is not being implemented, current userID will be set as 1.
router.post('/user', function(req, res, next) {
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "INSERT INTO Bookings (userID, seatID) VALUES (?,?);";
    connection.query(query, [currentUser, req.body.seatID], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      res.end();
    });
  });
});


module.exports = router;
