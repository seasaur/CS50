var i = 1;
function mouseOver() {
    document.getElementById("count").innerText = i++;
}

function clickFunc() {
    document.getElementsByClassName("post-time")[0].innerHTML = Date();
    var displayText = document.getElementsByTagName("textarea")[0].value;
    document.getElementsByClassName("post-content")[0].innerHTML = displayText;
}

var main;
var menu;

function toggleBG() {
    main = document.getElementById("main");
    menu = document.getElementById("menu");
    main.style.display = "none";
    menu.style.display = "block";
}

function toggleMain() {
    main = document.getElementById("main");
    menu = document.getElementById("menu");
    main.style.display = "block";
    menu.style.display = "none";
}

function BGcolor() {
    document.bgColor = color;

    // The code I'd like to use for changing the text simultaneously - however it does not work.
    document.getElementById("coltext").style.color = color;
}

document.getElementById("submitColor").addEventListener("click", changeBackground, false)
}