var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

var time;
router.get('/last.txt', function(req, res, next) {
  var now = new Date();
  res.send(String(time));
  time = now;
});

router.get('/color.html', function(req, res, next) {
  res.send();
});


module.exports = router;
