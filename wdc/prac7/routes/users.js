var express = require('express');
var router = express.Router();

/* GET users listing. */
router.get('/', function(req, res, next) {
  res.send('respond with a resource');
});

var posts = [];
router.post('/addpost', function(req, res) {
  var jsonPosts = JSON.parse(posts);
  jsonPosts.push(req.body);
});

module.exports = router;
