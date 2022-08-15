
    var skills = document.getElementsByClassName("skill-level-div");
    skillFill(skills[0], 2);
    skillFill(skills[1], 3);
    skillFill(skills[2], 3);
    skillFill(skills[3], 4);




    function flipback(item) {
        var parent = item.parentNode.parentNode.parentNode;
        parent.style.transform += "rotateY(180deg)";

    }
    function arrower(item) {
        item.style.transform += "translateX(50px)";
        var arrowsList = document.getElementsByClassName("arrows");
        console.log(arrowsList.length);
        for (var i = 0; i < arrowsList.length; i++) {
            if (arrowsList[i].style.transform != "translateX(0px)" && arrowsList[i].id != item.id) {
                arrowsList[i].style.transform = "translateX(0px)";
            }
        }
    }

    function highlightMyParent(item, parentNoNo) {
        item.style.backgroundColor = "aqua";
        var parent = item.parentNode;
        var transitionCard = parent.parentNode.children;
        console.log(transitionCard[0].class, transitionCard[0].id)
        var children = transitionCard[0].children;
        children[parentNoNo].style.display = "flex";
        // console.log(children[1].id)

    }
    function unHighlight(item, parentNoNo) {
        item.style.backgroundColor = "rgba(0, 255, 106, 0.062)";
        var parent = item.parentNode;
        var transitionCard = parent.parentNode.children;
        console.log(transitionCard[0].class, transitionCard[0].id)
        var children = transitionCard[0].children;
        children[parentNoNo].style.display = "none";
        console.log(children)
    }

    function skillFill(item, level) {
        console.log("hello");
        console.log(item.class);
        var childDivs = item.children;
        var i;
        for (i = 0; i < level; i++) {
            childDivs[i].style.backgroundColor = "#000";
        }
        for (; i < childDivs.length; i++) {
            childDivs[i].style.border = "2px solid #000"
        }
    }
    function hourlyWage() {
        var textBox = document.getElementById("hourly-wage");

        var hiringRadioBtn = document.getElementById("radio-hiring");
        if (hiringRadioBtn.checked) {
            textBox.style.display = "unset";
        }
        else
            textBox.style.display = "none";
    }