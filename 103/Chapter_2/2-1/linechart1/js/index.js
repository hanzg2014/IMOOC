//svg

var svg = d3.select("#container")
.append("svg")
//.append("svg:svg")

//atrribute modfication
//same as <svg width="500" height="250"></svg>
.attr("width", 500)  //500px by default
.attr("height", 250) //syntactically the same as jQuery

d3.select("svg")
.append("g")
.attr("transform", "translate(50,30)") //x軸偏移 50px, y軸偏移30px

