var toggle = false;
function tick() {
    var img = document.createElement("img");
    img.src = "grenTick.png";
    if (img.indexOf('greenTick.png')!=-1) {
        document.getElementById('tick').src  = 'greenTick.png';
    }
     else {
       document.getElementById('tick').src = '';
   }

}