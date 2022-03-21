var i = 1;
function mouseOver(){
    document.getElementById("count").innerText = i++;
}

function click() {
    document.getElementsByClassName("post-time")[0].innerHTML = Date();
    document.getElementsByClassName("post-content")[0].innerHTML = "Hello World";
  }