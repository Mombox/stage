#ifndef WEBSERVER
#define WEBSERVER

 


void www(int argc, char *argv[]);


const char *HTTP =  "<html>\
<head>\
\
<title>\Test</title>\
</head>\
<body onload=\"setTimeout(function(){location.reload()}, 100);\">\
<script>\document.write(Date.now());</script>\
</body>\
</html>";

#endif
    


/*
const char *XMLHTTP = "<html>\
<body>\
<script>\
		function reqListener () {\
          document.getElementById('graph').innerHTML = this.responseText;\
}\
	function reloadGraph() {"
		"var oReq = new XMLHttpRequest();\
	oReq.addEventListener(\"load\", reqListener);\
	oReq.open(\"GET\", \"/svg\");\
	oReq.send();"
		"setTimeout(reloadGraph, 100);"
		"}"
		"setTimeout(reloadGraph, 100);"
		"</script>\
	"
		"<div id='graph'></div>"
		"</body>\
	</html> ";
*/

/*
const char *XMLHTTP = "<html>\n"
"<body>\n"

		"<div id='graph'><svg width=\"800\" height=\"300\" xmlns='http://www.w3.org/2000/svg'></svg></div>\n"
		"<p><a href='/quit'>Quit</a></p>\n"  
		"<script>\n"
				"function reqListener () {\n"
		         "document.querySelector('#graph svg').innerHTML = this.responseText;\n"
		"}\n"
			"function reloadGraph() {\n"
				"var oReq = new XMLHttpRequest();\n"
			"oReq.addEventListener(\"load\", reqListener);\n"
			"oReq.open(\"GET\", \"/svg\");\n"
			"oReq.send();\n"
				"setTimeout(reloadGraph, 100);\n"
				"}\n"
				"setTimeout(reloadGraph, 100);\n"
				
				"var svg = document.querySelector('#graph svg');\n"
				"var pt = svg.createSVGPoint();\n"
				
		
				"function cursorPoint(evt){\n"
				"pt.x = evt.clientX -50; pt.y = evt.clientY -130 ;\n"
				"return pt.matrixTransform(svg.getScreenCTM().inverse());\n"
				"}\n"
			 		
				
				"svg.addEventListener('mousemove', function(evt) {\n"
				"console.log(cursorPoint(evt));\n"	
			  	"}, false);\n"			

				"svg.addEventListener('click', function(evt) {\n"
				" dest = cursorPoint(evt).y ;\n"	
				"console.log(dest);\n"
				"}, false);\n"	
		
		
		
				"</script>\n"
		"</body>\
	</html> ";

*/

