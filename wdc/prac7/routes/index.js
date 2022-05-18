var express = require('express');
var router = express.Router();
router.use(express.static('public'));

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


router.post('/combine', function(req, res) {
  var lines = req.body.lines;
  var suffix = req.body.suffix;
  var anyvariablename = "";
  // create empty string
  // for each line in lines
  // add (line + suffix + \n) to string
  // req.send string
  lines.forEach(line => {
    anyvariablename+=line+suffix+"\n";
  });

  res.send(anyvariablename);
});

router.get('/cookie', function(req, res) {
  var cookie = req.cookies.task3_1;
  if (cookie===null) {
    res.cookie('task3_1', 1);
  }
  else {
    cookie+=1;
  }
});

module.exports = router;
