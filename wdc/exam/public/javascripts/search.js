
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
    var img2 = document.createElement("img");
    var checkbox = document.createElement('input');
    checkbox.style.display="none";
    checkbox.name="booked";
    console.log(checkbox.name);
    var checkbox2 = document.createElement('input');
    checkbox2.style.display="none";
    checkbox2.name="booked";
    console.log(checkbox2.name);

    // var label = document.createElement('label');
    // label.style.display="none";
    // var label2 = document.createElement('label');
    // label2.style.display="none";
    br = document.createElement("span");
    br.innerHTML = "<br/>";
    br2 = document.createElement("span");
    br2.innerHTML = "<br/>";
    br3 = document.createElement("span");
    br3.innerHTML = "<br/>";

    var span = document.createElement('span');
    span.style.display="none";
    var span2 = document.createElement('span');
    span2.style.display="none";

   var button = document.createElement("button");
   button.classList.add('submitButton');
   button.innerHTML="BOOK SEATS";
   button.id="book";
   button.onclick=function() {
      book();
   }

    //there are 2 seats in every screening
    if(seatList[i].booked==0) {
      img.src = "/images/available.png";
      img.id = "seat";
      img.alt = "available seat";
      checkbox.style.display="inline";
      // label.style.display="block";
      checkbox.type = "checkbox";
      checkbox.value = seatList[i].seatID;
      console.log(checkbox.value,"value checkbox");
      // label.htmlFor = "value";
      // label.appendChild(document.createTextNode(seatList[i].seat));
      span.style.display="inline";
      span.innerHTML = seatList[i].seat;
    }
    else {
      img.src = "/images/unav.png";
      img.id = "seat";
      img.alt = "unavailable seat";
    }

    if(seatList[i+1].booked==0) {
      img2.src = "/images/available.png";
      img2.id = "seat";
      img2.alt = "available seat";
      checkbox2.style.display="inline-block";
      // label2.style.display="block";
      span2.style.display="inline";
      span2.innerHTML = seatList[i+1].seat;
      checkbox2.type = "checkbox";
      checkbox2.value = seatList[i+1].seatID;
      console.log(checkbox2.value,"value checkbox");

      // label2.htmlFor = "value";
      // label2.appendChild(document.createTextNode(seatList[i+1].seat));
    }
    else {
      img2.src = "/images/unav.png";
      img2.id = "seat";
      img2.alt = "unavailable seat";
    }

    newDiv.appendChild(img);
    newDiv.appendChild(img2);
    newDiv.appendChild(br);
    newDiv.appendChild(checkbox);
    // newDiv.appendChild(label);
    newDiv.appendChild(span);
    newDiv.appendChild(br2);
    newDiv.appendChild(checkbox2);
    newDiv.appendChild(span2);

    list.appendChild(newDiv);
}
list.appendChild(button);
list.appendChild(br3);
}

var bookedList = [];
function book() {
  var selected = document.getElementsByName("booked");
  bookedList=[];
   for(var checkbox of selected) {
    if (checkbox.checked) {
    console.log(checkbox.value);
    bookedList.push(checkbox.value);

    // bookedList.push(selected);
   }
    // for(var i=0;i<8;i++) { //8=total # of seats
      // bookedList.push(booked[i].value);
    }
    console.log(bookedList);
    if(bookList.length==0) {
      alert("You did not select any seats.");
      return;
    }
    for(var i=0;i<bookedList;i++) {
        send(bookedList[i]);
    }
}

function send(booked) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      alert("Booking successful!");
      }
    };

  xhttp.open("POST", "/book", true); //send change info request to database
  xhttp.setRequestHeader("Content-type", "application/json");
  xhttp.send(JSON.stringify({seatID: bookedList}));

}