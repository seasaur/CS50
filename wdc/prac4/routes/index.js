var express = require('express');
var router = express.Router();
var moment = require('moment')

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

router.get('/last.txt', (req, res) => {
  var timestamp;
  res.send(timestamp);
  timestamp = moment().format('HH:mm:ss');
})

module.exports = router;
