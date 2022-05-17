var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

router.get('/brew', function(req, res) {
  var drink = req.query.param1;
  if (param1=='tea') {
  res.send('A delicious cup of tea!'+drink);
  }
  if (param1=='coffee') {
    res.sendStatus(418);
  }
  else {
    res.sendStatus(400);
  }
});

module.exports = router;
