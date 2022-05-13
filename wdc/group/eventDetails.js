var toggle = false;
// function tick() {
//     var img = document.createElement("img");
//     img.src = "grenTick.png";
//     if (img.indexOf('greenTick.png')!=-1) {
//         document.getElementById('tick').src  = 'greenTick.png';
//     }
//      else {
//        document.getElementById('tick').src = '';
//    }

// }

// function show() {
//     document.getElementById('yourTick').style.display = "block";
//     document.getElementById('toggleTick').style.display = "none";
// }

// var vueinst = new Vue({
//     el: '#app',
//     data: {
//         show_tick=false;
//     }
//     greenTick: {
//         avatar: 'greenTick.png'
//       }
//     methods: {
//         click: function();
//     }
// });


var tick = document.getElementById("you");
if (table != null) {
    for (var i = 0; i < table.rows.length; i++) {
        for (var j = 0; j < table.rows[i].cells.length; j++)
        table.rows[i].cells[j].onclick = function () {
            toggleTick(this);
        };
    }
}

function toggleTick(tableCell) {
    if (tableCell.innerHTML == '') {
        var img = document.createElement("img");
        img.src = "grenTick.png";
        img.style.display = "block";
    }
    else {
        tableCell.innerHTML='';
        img.style.display = "none";
    }
}