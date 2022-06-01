var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

router.get('/account', function(req, res, next) {
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "SELECT Users.username, Users.first_name, Users.password, Notification.email";
    connection.query(query, function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      res.json(rows);
    });
  });
});

router.post('/add', function(req, res, next) {
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "INSERT INTO Users (username, first_name, password) VALUES(?,?,?);";
    connection.query(query, [req.body.first_name, req.body.last_name], function(error, rows, fields) {
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
