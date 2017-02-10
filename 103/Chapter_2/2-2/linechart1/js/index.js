//設置都放在文件開頭
var width = 500, height =200, 
margin = {left:50, top:30, right:20, bottom: 20},
g_width = width - margin.left - margin.right,
g_height = height - margin.top - margin.bottom;

var data =[1,3,5,7,8,4,3,7]

//svg
var svg = d3.select("#container")
.append("svg")
//.append("svg:svg")

//atrribute modfication
//same as <svg width="500" height="250"></svg>
.attr("width", width)  //500px by default
.attr("height", height) //syntactically the same as jQuery

d3.select("svg")
.append("g")
.attr("transform", "translate("+margin.left+","+margin.top+")") //x軸偏移 50px, y軸偏移30px

//縮放函數
var scale_x = d3.scaleLinear()
.domain([0, data.length-1])	//輸入範圍
.range([0, g_width])	//輸出範圍

var scale_y = d3.scaleLinear()
.domain([0, d3.max(data)])
.range([0,g_height])

//使用d3的line函數, //d代表 元素, i代表 下標
//var line_generator = d3.svg.line()
var line_generator = d3.line()
.x(function(d, i){return scale_x(i);}) // x = 0,1,2,3...
.y(function(d){return scale_y(d);})	//y = 1,3,5,7...
.curve(d3.curveCatmullRom.alpha(0.5))

d3.select("g")
.append("path")
.attr("d", line_generator(data)) //d 代表 path data, 使用data生成折線

//.attr("d", "M1,0L20 40L40, 50L100, 100L0,200")
//起點(1,0)->(20.40)->(40,50)->(100,100)->(0,200)
