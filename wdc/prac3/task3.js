var i = 1;
function mouseOver(){
    document.getElementById("count").innerText = i++;
}

function click() {
    const d = new Date();
    document.getElementsByClassName("post-time").innerHTML = d;
    document.getElementsByClassName("post-content").innerHTML = "Hello World";
  }