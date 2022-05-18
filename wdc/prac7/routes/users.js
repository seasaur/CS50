var express = require('express');
var router = express.Router();

/* GET users listing. */
router.get('/', function(req, res, next) {
  res.send('respond with a resource');
});

var posts = [];
router.post('/addpost', function(req, res) {
  // var jsonPosts = JSON.parse(posts);
  // jsonPosts.unshift(req.body.title);
  var post={
    title: req.body.title,
    content: req.body.content
  }
  posts.push(post)
  res.send(posts);
});

router.get('/getposts', function(req,res) {
  
  res.send(posts);
});


module.exports = router;
