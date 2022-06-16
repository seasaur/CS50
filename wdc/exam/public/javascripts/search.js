
var seatList = [];
function getSeats(){
    document.getElementById("seats").innerHTML = ""; //clear out previous search results first
    var searchBar = document.getElementById("userNameSearch").value;
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        seatList = JSON.parse(this.responseText);
        console.log(seatList);
        if(seatList.length==0) {
            alert("There are no screen times matching your selected filters.");
            break;
        }
        for (var i = 0; i < seatList.length; i++) {
            var list = document.getElementById("seats");
            var newDiv = document.createElement("div");
            newDiv.setAttribute('class', 'eventBox');
            var username = document.createElement("h2");
            username.setAttribute('class', 'boxHeading');
            username.innerHTML = seatList[i].username;
            newDiv.appendChild(username);

            var button = document.createElement("button");
            button.innerHTML = "VIEW USER";
            button.id = seatList[i].username;
            button.setAttribute('class', 'submitButton');

            console.log(button.id, "username");


            button.onclick = function(user) {
              viewAUser(this.id)
           }

            newDiv.appendChild(button);
            list.appendChild(newDiv);

        }
      }
    };

    xhttp.open("GET", "/searchseats", true);
    xhttp.send();

}