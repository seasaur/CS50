var i = 1;
function mouseOver() {
    document.getElementById("count").innerText = i++;
}

function clickFunc() {
    document.getElementsByClassName("post-time")[0].innerHTML = Date();
    var displayText = document.getElementsByTagName("textarea")[0].value;
    document.getElementsByClassName("post-content")[0].innerHTML = displayText;
}

var main;
var menu;

function toggleBG() {
    main = document.getElementById("main");
    menu = document.getElementById("menu");
    main.style.display = "none";
    menu.style.display = "block";
}

function toggleMain() {
    main = document.getElementById("main");
    menu = document.getElementById("menu");
    main.style.display = "block";
    menu.style.display = "none";
}

var color;

function BGFunc() {
        color = document.getElementById("BG").value;
        document.body.style.backgroundColor = color;
}

function postColor(postText) {
    // // document.getElementById("blueButton").style.color = "blue";
    // // const btn = document.querySelector('#colorBtn');
    // const radioButtons = document.querySelectorAll('input[name="color"]');
    // textColor.addEventListener("click", () => {
    //     let selectedColor;
    //     for (const radioButton of radioButtons) {
    //         if (radioButton.checked) {
    //             selectedColor = radioButton.value;
    //             break;
    //         }
    //     }
    // document.getElementsByClassName("post-content")[0].style.color = selectedColor;
    // });

    var radioButtons = document.querySelectorAll('input[name="color"]');
    var selectedColor;
    for(let radioButton of radioButtons){
        if(radioButton.checked){
            selectedColor = radioButton.value;
            break;
        }
    }
    postText.style.color= selectedColor;
}
