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

    let query = "SELECT Films.name, Films.dates, Films.time, Seats.seat FROM Seats INNER JOIN Films ON Seats.filmID=Films.filmID WHERE dates = ? AND name = ?;";
    connection.query(query, [dates, name], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      // if(rows.length>0){
        console.log(rows, "ah");
        res.json(rows);
      // }
      // else{
      //   res.sendStatus(401);
      // }

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

    let query = "SELECT Films.name, Films.dates, Films.time, Seats.seat FROM Seats INNER JOIN Films ON Seats.filmID=Films.filmID";
    connection.query(query, [dates, name], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      // if(rows.length>0){
        console.log(rows, "ah");
        res.json(rows);
      // }
      // else{
      //   res.sendStatus(401);
      // }

    });
  });
});

module.exports = router;
