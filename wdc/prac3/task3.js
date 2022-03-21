var i = 1;
function mouseOver(){
    document.getElementById("count").innerText = i++;
}

function post(){
    const d = new Date();
    document.getElementById("posts").innerHTML = d;
}

function click() {
    document.getElementsByClassName("post-time").innerHTML = Date();
    document.getElementsByClassName("post-content").innerHTML = "Hello World";
  }