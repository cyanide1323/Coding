var express = require("express");
var app = express();
var bodyParser = require("body-parser");
var mongoose = require("mongoose");
mongoose.connect("mongodb://localhost/books");
var db = mongoose.connect;

app.get('/',function(req,res){
	res.send("Hello world!");
}).listen(3000);
console.log("server is running on port 3000");