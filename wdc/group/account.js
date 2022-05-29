var vueinst = new Vue({
    el: '#account',
    data: {
        username: 'EpicUserName',
        email: 'EpicUserName@example.com',
        password: 'canBeHacked',
        events: [
            { name:'Event1', url:'' },
            { name:'Event2', url:'' },
            { name:'Event3', url:'' },
        ],
    }
});

var actorArray = [];
function get_list(){

    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        actorArray = JSON.parse(this.responseText);
        for (var i = 0; i < actorArray.length; i++) {
            var list = document.getElementById("actors");
            var newRow = document.createElement("tr");
            var newActor_first_name = document.createElement("td");
            newActor_first_name.innerHTML = actorArray[i].first_name;
            newRow.appendChild(newActor_first_name);
            var newActor_last_name = document.createElement("td");
            newActor_last_name.innerHTML = actorArray[i].last_name;
            newRow.appendChild(newActor_last_name);
            list.appendChild(newRow);
        }
      }
    };

    xhttp.open("GET", "/actors", true);
    xhttp.send();

}

var newActorArray = [];

function add_actor(){
  var first_name = document.getElementById("actor-first-name").value;;
  var last_name = document.getElementById("actor-last-name").value;

  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      }
    };

  xhttp.open("POST", "/add", true);
  xhttp.setRequestHeader("Content-type", "application/json");
  xhttp.send(JSON.stringify({first_name: first_name, last_name: last_name}));

}