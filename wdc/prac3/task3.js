var i = 1;
var array = [];

function mouseOver() {
    document.getElementById("count").innerText = i++;
}

function clickFunc() {
    var posts = document.getElementById("posts");
    var number = document.getElementById("postNum").value;
    for(let i = 0; i < number; i++){
        var postTime = document.createElement("p");
        // let breakLine = document.createElement("Br");
        var displayText = document.getElementsByTagName("textarea")[0].value;
        postTime.classList.add("post-time");
        postTime.innerHTML = Date();
        var postContent = document.createElement("p");
        postColor(postContent);
        postStyle(postContent);
        postContent.classList.add("post-content");
        postContent.innerHTML = displayText;
        // post.appendChild(postTime);
        // post.appendChild(breakLine);
        // post.appendChild(postContent);
        // post.appendChild(breakLine);


        var postContainer = document.createElement("div");
        postContainer.appendChild(postTime);
        postContainer.appendChild(postContent);
        posts.appendChild(postContainer);
        array.push(postContainer);
    }
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

function postStyle(postText) {
    var checkBox = document.querySelectorAll('input[name="style"]');
    var textStyle;
    for(var i=0, n=checkBox.length;i<n;i++) {
        if (checkBox[i].checked == true){
            textStyle = checkBox[i].value;
            if(textStyle=="italic") {
                postText.style.fontStyle = textStyle;
            }
            if(textStyle=="bold") {
                postText.style.fontWeight = textStyle;
            }
        }
    }
}

function postRange(postNumber) {
    var posts = document.getElementById("posts");
    posts.innerHTML="";
    for(let i=array.length;i>postNumber;i--) {
        posts.appendChild(array[i]);
    }


}