var express = require('express');
var router = express.Router();

/* GET users listing. */
router.get('/', function(req, res, next) {
  res.send('respond with a resource');
});

jsonString = [];
router.post('/addpost', function(req, res) {
  ;
});

module.exports = router;
