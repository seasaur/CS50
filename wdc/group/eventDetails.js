var toggle = false;
function tick() {
    var img = document.getElementById('tick').src;
    if (img.indexOf('greenTick.png')!=-1) {
        document.getElementById('tick').src  = 'greenTick.png';
    }
     else {
       document.getElementById('tick').src = '';
   }

}