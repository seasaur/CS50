var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

module.exports = router;

router.get('/last.txt', (req, res) => {
  var timestamps = moment().format('HH:mm:ss')
  console.log(timestamps + ' From routes/index.js')
  res.send('GET request to the homepage')
})
