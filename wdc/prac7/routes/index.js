var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

router.get('/brew', function(req, res) {
  var q = req.query.drink;
  if (q=='tea') {
  res.send('A delicious cup of tea!');
  }
  if (q=='coffee') {
    res.status(418).send();
  }
  else {
    res.status(400).send();
  }
});
var lastText = "first";
router.post('/pass-it-on', function(req,res) {
  var text = req.body.message;
  if (!text) {
    res.status(400).send();
  }
  else {
    res.send(lastText);
    lastText = text;
  }
});

var array = [];
router.post('/combine', function(req, res) {
  var lines = req.body.lines;
  var suffix = req.body.suffix;

});

module.exports = router;
