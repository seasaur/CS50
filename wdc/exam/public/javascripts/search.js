
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

//search function
function sendInfo() {
  var name = document.getElementById("searchName").value;
  var dates = document.getElementById("searchDate").value;
  console.log(name);
  console.log(dates);
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      getSeats();
      }
    };

  xhttp.open("POST", "/storage", true); //send change info request to database
  xhttp.setRequestHeader("Content-type", "application/json");
  xhttp.send(JSON.stringify({dates: dates, name: name}));
}


var seatList = [];
function getSeats(){
    document.getElementById("seats").innerHTML = ""; //clear out previous search results first
    var name = document.getElementById("searchName").value;
    var dates = document.getElementById("searchDate").value;
    console.log(name, "js name");
    console.log(dates, "js dates");
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        seatList = JSON.parse(this.responseText);
        console.log(seatList);
        forLoop(seatList);
      }
    };

  if(name=="any" && dates=="any") {
    console.log("any2");
    xhttp.open("GET", "/any", true);

  }
  else if(dates=="any") {
    console.log("any date");
    xhttp.open("GET", "/datesAny", true);
  }
  else if(name=="any"){
    console.log("any name");
    xhttp.open("GET", "/nameAny", true);
  }
  else {
    xhttp.open("GET", "/searchSeats", true);
  }

    xhttp.send();

}

function forLoop(seatList) {
  if(seatList.length==0) {
    alert("There are no screen times matching your selected filters.");
    return;
}
for (var i = 0; i < seatList.length; i=i+2) {
    var list = document.getElementById("seats");
    var newDiv = document.createElement("div");
    newDiv.setAttribute('class', 'eventBox');
    var withoutT = [];
    seatList.forEach(u => {
      withoutT.push(u.dates.split("T")[0]);
   });
   console.log(withoutT);

    var filmName = document.createElement("h3");
    filmName.setAttribute('class', 'body');
    filmName.innerHTML = "Film Title: " + seatList[i].name + "<br/>Screening Date: "  + withoutT[i] + " Screening Time: " + seatList[i].time;
    newDiv.appendChild(filmName);

    var img = document.createElement("img");

    if()
    img.src = "/images/available.png";
    img.id = "seat";
    img.alt = "available seat";


    newDiv.appendChild(img);

    // <img src="/images/seat.png" alt="available seat" id="seat"></img>

  //   var button = document.createElement("button");
  //   button.innerHTML = "VIEW USER";
  //   button.id = seatList[i].filmName;
  //   button.setAttribute('class', 'submitButton');

  //   console.log(button.id, "filmName");


  //   button.onclick = function(user) {
  //     viewAUser(this.id)
  //  }

  //   newDiv.appendChild(button);
    list.appendChild(newDiv);

}
}