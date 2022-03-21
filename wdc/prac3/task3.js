var i = 1;
function mouseOver(){
    document.getElementById("count").innerText = i++;
}

function click() {
    const d = new Date();
    document.getElementsByClassName("post-time").[0]innerHTML = d;
    document.getElementsByClassName("post-content").[0]innerHTML = "Hello World";
  }