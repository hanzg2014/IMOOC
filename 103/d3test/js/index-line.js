var width=500,height=250,
margin={left:50,top:30,right:20,bottom:20},
g_width=width-margin.left-margin.right,
g_height=height-margin.top-margin.bottom;

//div--svg--g--path--xy轴

//SVG
var svg=d3.select("#container")
.append("svg")
//width,height
.attr("width",width) //attribute .连接每个元素 
.attr("height",height)

//g
var g=svg
.append("g")
.attr("transform","translate("+margin.left+","+margin.top+")")

var data=[1,3,5,7,8,4,3,7]

//x轴缩放
var scale_x=d3.scale.linear()
.domain([0,data.length-1])
.range([0,g_width])

//y轴缩放
var scale_y=d3.scale.linear()
.domain([0,d3.max(data)])
.range([g_height,0])

//生成线性图表
var line_generator=d3.svg.line()
.x(function(d,i){return scale_x(i);})//0,1,2,3...
.y(function(d){return scale_y(d);})//1,3,5...
.interpolate("cardinal")

//path 添加线性图表
g
.append("path")
.attr("d",line_generator(data))//d="M1,0L20,40L40,50L100,100L0,200",d -path data
.style("line","steelblue")//填充颜色

//x轴，y轴
var x_axis=d3.svg.axis().scale(scale_x),
y_axis=d3.svg.axis().scale(scale_y).orient("left")

//x轴设定
g.append("g")
.call(x_axis)
.attr("transform","translate(0,"+g_height+")")

//y轴设定
g.append("g")
.call(y_axis)
.append("text")
.text("Price($)")
.attr("transform","rotate(-90)")
.attr("text-anchor","end")
.attr("dy","1em")



