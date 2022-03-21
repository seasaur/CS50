var i = 1;
function mouseOver(){
    document.getElementById("count").innerText = i++;
}

function post(){
    const d = new Date();
    document.getElementById("demo").innerHTML = d;
}