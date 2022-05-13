var toggle = false;
function tick() {
    if (toggle === true) {
        document.getElementById('imgplus').src  = 'Images/Minus.gif';
    } else {
       document.getElementById('imgplus').src = 'Images/Plus.gif';
       alert(img);
    }
    toggle = !toggle;
}