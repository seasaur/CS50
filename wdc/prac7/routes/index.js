var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

router.get('/brew/:drink', function(req, res) {
  var q = req.query.drink;
  if (q=='tea') {
  res.send('A delicious cup of tea!');
  }
  if (q=='coffee') {
    res.sendStatus(418);
  }
  else {
    res.sendStatus(400);
  }
});

module.exports = router;
