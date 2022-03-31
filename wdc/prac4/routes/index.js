var express = require('express');
var router = express.Router();

/* GET home page. */
// router.get('/', function(req, res, next) {
//   res.render('index', { title: 'Express' });
// });

var time;
router.get('/last.txt', function(req, res, next) {
  var now = new Date();
  res.send(String(time));
  time = now;
});

var count=0;
const color =["red", "yellow", "green", "blue"];
router.get('/color.html', function(req, res, next) {

  res.send(`<!DOCTYPE html>
    <html lang="en">
    <head>
    <meta charset="utf-8">
      <title>Express</title>
    </head>

    <body>
    <h1 style = "color:${color[count%4]}">
    ${color[count%4]}
    </h1>
    </body>

    </html>`
    );
    count++;
});
let ff='';
router.get('/log.html', function(req, res, next) {
  ff+=`<li>${new Date()}</li>`; //string concatenation, += adds on top of existing list and doesn't overwrite it
  res.send(`<!DOCTYPE html>
  <html lang="en">
  <head>
  <meta charset="utf-8">
    <title>Express</title>
  </head>

  <body>
  <ul>
  ${ff}
  </ul>
  </body>

  </html>`);
});

var count1=0;
router.get('/color.txt', function(req, res, next) {
  res.send(color[count1%4]);
  count1++;
});

var arrayDates = [];
router.get('/log.json', function(req, res, next) {
  arrayDates.push(Date());
  var myArray = JSON.stringify(arrayDates);
  res.send(myArray);
});

router.get('/log-ro.json', function(req, res, next) {
  var logroArray = JSON.stringify(arrayDates);
  res.send(logroArray);
});

let accept = 0;
router.get('/accept', function(req, res, next) {
  res.sendStatus(200);
  accept = 1;
});

router.get('/content.ajax', function(req, res, next) {
  if (accept=0) {
    res.sendStatus(403);
    res.send(0);
  }
  else {
    res.send('<p>some html</p> <p>some more html</p>')
  }
});


module.exports = router;
