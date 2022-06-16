
//onload: generating the dropdown list for dates
var dateList = [];
function getDates(){
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        dateList = JSON.parse(this.responseText);
        console.log(dateList);
        var withoutT = [];
        dateList.forEach(u => {
           withoutT.push(u.dates.split("T")[0]);
        });
        console.log(withoutT);
        for (var i = 0; i < dateList.length; i++) {
            var list = document.getElementById("searchDate");
            var newOption = document.createElement("option");
            newOption.value=dateList[i].dates;
            newOption.innerHTML=withoutT[i];
            list.appendChild(newOption);
        }
      }
    };

    xhttp.open("GET", "/dates", true);
    xhttp.send();

    getFilms();
}

//onload: generating the dropdown list for films (called by getDates())
var filmList = [];
function getFilms(){
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        filmList = JSON.parse(this.responseText);
        console.log(filmList);
        for (var i = 0; i < filmList.length; i++) {
            var list = document.getElementById("searchName");
            var newOption = document.createElement("option");
            newOption.value=filmList[i].name;
            newOption.innerHTML=filmList[i].name;
            list.appendChild(newOption);
        }
      }
    };

    xhttp.open("GET", "/name", true);
    xhttp.send();

}

function

//search function
var seatList = [];
function getSeats(){
    document.getElementById("seats").innerHTML = ""; //clear out previous search results first
    var name = document.getElementById("searchName");
    var selectedName = name.options[name.selectedIndex].value;
    var date = document.getElementById("searchDate");
    var selectedDate = name.options[name.selectedIndex].value;
    console.log(selectedName);
    console.log(selectedDate);
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        seatList = JSON.parse(this.responseText);
        console.log(seatList);
        if(seatList.length==0) {
            alert("There are no screen times matching your selected filters.");
            return;
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

    xhttp.open("POST", "/searchSeats", true);
    xhttp.send(JSON.stringify({date: selectedDate, name: selectedName})); //or just selected??

}