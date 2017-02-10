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
var g=svg
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
.range([g_height,0])	//����ֵ����

//��������ͼ��
var line_generator=d3.svg.line()
.x(function(d,i){return scale_x(i);})//0,1,2,3...
.y(function(d){return scale_y(d);})//1,3,5...
.interpolate("cardinal")

//path �������ͼ��
g
.append("path")
.attr("d",line_generator(data))//d="M1,0L20,40L40,50L100,100L0,200",d -path data

//x�ᣬy��
var x_axis=d3.svg.axis().scale(scale_x), //scale �����S���L��
y_axis=d3.svg.axis().scale(scale_y).orient("left");	//������߅����������߅��

//x���趨
g.append("g")
.call(x_axis)	//���һ��x�S
.attr("transform", "translate(0,"+g_height+")")

//y���趨
g.append("g")
.call(y_axis)	//���һ��y�S
.append("text")
.text("Price($)")	//Ĭ�J��x�S
.attr("transform", "rotate(-90)")	//��r����D 90��
.attr("text-anchor", "end")	//��ĩβ���R
.attr("dy","1em")	//�����Լ���y�S�����D�^����������1�����w��ƫ��



