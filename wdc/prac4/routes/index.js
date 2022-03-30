var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

module.exports = router;

router.get('/last.txt', (req, res) => {
  var timestamps = '/';
  res.send(timestamps + ' From routes/index.js');
  var timestamps = moment().format('HH:mm:ss');
})
