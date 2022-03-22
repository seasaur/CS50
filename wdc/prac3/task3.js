var i = 1;
function mouseOver() {
    document.getElementById("count").innerText = i++;
}

function clickFunc() {
    document.getElementsByClassName("post-time")[0].innerHTML = Date();
    var displayText = document.getElementsByTagName("textarea")[0].value;
    document.getElementsByClassName("post-content")[0].innerHTML = displayText;
}

var main = document.getElementById("main");
var menu = document.getElementById("menu");

function toggleBG() {
    main.style.display = "none";

}

function toggleMain() {

}