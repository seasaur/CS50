var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

var time;
router.get('/last.txt', function(req, res, next) {
  var now = new Date();
  res.send(String(time));
  time = now;
});

var count=0;
router.get('/color.html', function(req, res, next) {
  const color =["red", "yellow", "green", "blue"];
  res.send(`<!DOCTYPE html>
    <html lang="en">
    <head>
    <meta charset="utf-8">
      <title>Express</title>
    </head>

    <body>
    <h1 style = "color:${color[color%4]}">
    ${color[color%4]}
    </h1>
    </body>

    </html>`
    );
    count++;
});

module.exports = router;
