var dateList = [];
function getDates(){
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        dateList = JSON.parse(this.responseText);
        console.log(dateList);
        for (var i = 0; i < dateList.length; i++) {
            var list = document.getElementById("searchDates");
            var newOption = document.createElement("option");
            newOption.setAttribute('value', dateList[i]);
            var filmName = document.createElement("h2");
            filmName.setAttribute('class', 'boxHeading');
            filmName.innerHTML = seatList[i].filmName;
            newDiv.appendChild(filmName);

            var button = document.createElement("button");
            button.innerHTML = "VIEW USER";
            button.id = seatList[i].filmName;
            button.setAttribute('class', 'submitButton');

            console.log(button.id, "filmName");


            button.onclick = function(user) {
              viewAUser(this.id)
           }

            newDiv.appendChild(button);
            list.appendChild(newDiv);

        }
      }
    };

    xhttp.open("GET", "/dates", true);
    xhttp.send();

}




var seatList = [];
function getSeats(){
    document.getElementById("seats").innerHTML = ""; //clear out previous search results first
    var select = document.getElementById("searchName").value;
    var selected = select.options[select.selectedIndex].text
    console.log(selected);
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
            var filmName = document.createElement("h2");
            filmName.setAttribute('class', 'boxHeading');
            filmName.innerHTML = seatList[i].filmName;
            newDiv.appendChild(filmName);

            var button = document.createElement("button");
            button.innerHTML = "VIEW USER";
            button.id = seatList[i].filmName;
            button.setAttribute('class', 'submitButton');

            console.log(button.id, "filmName");


            button.onclick = function(user) {
              viewAUser(this.id)
           }

            newDiv.appendChild(button);
            list.appendChild(newDiv);

        }
      }
    };

    xhttp.open("GET", "/searchSeats", true);
    xhttp.send();

}