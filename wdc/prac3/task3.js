var i = 1;
function mouseOver(){
    document.getElementById("count").innerText = i++;
}

function post(){
    const d = new Date();
    document.getElementById("posts").innerHTML = d;
}

function click() {
    document.getElementById("demo").innerHTML = "Hello World";
  }