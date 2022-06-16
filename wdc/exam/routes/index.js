var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

router.get('/dates', function(req, res, next) { //account.html: getting a list of all events created by user
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

router.get('/name', function(req, res, next) { //account.html: getting a list of all events created by user
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

router.get('/searchSeats', function(req, res, next) { //admin search route
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "SELECT username FROM Users WHERE username LIKE '%?%';"; //NOT COMPLETE: need containing "search word"
    connection.query(query, [req.body.selected], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      if(rows.length>0){
        console.log(rows, "ah");
        res.json(rows); //return username of user
      }
      else{
        res.sendStatus(401);
      }

    });
  });
});

module.exports = router;
