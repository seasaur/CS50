var toggle = false;
function tick() {
    if (toggle === true) {
        document.getElementById('tick').src  = 'greenTick.png';
    } else {
       document.getElementById('tick').src = &nbsp;;
    }
    toggle = !toggle;
}