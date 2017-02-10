var width=500,height=250,
margin={left:50,top:30,right:20,bottom:20},
g_width=width-margin.left-margin.right,
g_height=height-margin.top-margin.bottom;

//div--svg--g--path--xy��

//SVG
var svg=d3.select("#container")
.append("svg")
//width,height
.attr("width",width) //attribute .����ÿ��Ԫ�� 
.attr("height",height)

//g
var g=d3.select("svg")
.append("g")
.attr("transform","translate("+margin.left+","+margin.top+")")

var data=[1,3,5,7,8,4,3,7]

//x������
var scale_x=d3.scale.linear()
.domain([0,data.length-1])
.range([0,g_width])

//y������
var scale_y=d3.scale.linear()
.domain([0,d3.max(data)])
.range([g_height,0])

//�������ͼ��
var area_generator=d3.svg.area()
.x(function(d,i){return scale_x(i);})//0,1,2,3...
.y0(g_height)//1,3,5...
.y1(function(d){return scale_y(d);})//1,3,5...
.interpolate("cardinal")

//path �������ͼ��
g
.append("path")
.attr("d",area_generator(data))//d="M1,0L20,40L40,50L100,100L0,200",d -path data
.style("fill","steelblue")//�����ɫ

//x�ᣬy��
var x_axis=d3.svg.axis().scale(scale_x),
y_axis=d3.svg.axis().scale(scale_y).orient("left")

//x���趨
g.append("g")
.call(x_axis)
.attr("transform","translate(0,"+g_height+")")

//y���趨
g.append("g")
.call(y_axis)
.append("text")
.text("Price($)")
.attr("transform","rotate(-90)")
.attr("text-anchor","end")
.attr("dy","1em")


