var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');

var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/users', usersRouter);

var n=1;
var log = function (req, res, next) {
    // console.log('Received ${n} requests');
    n+=1;
    next();
};

app.use(log);

app.get('/', function(req, res) {
    let response =  `Received ${req.response}requests`;
    res.send(response);
});

app.listen(3000);

// Req.use((req,res)=>{
//     If(req.header.content-type != "Application/json")
//       {
//     req.send(412)
//  }
//  })

module.exports = app;
