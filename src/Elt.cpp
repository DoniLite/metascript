# include "Elt.h"
# include "Renderer.h"
using namespace std;


Elt::Elt(){

}

string Elt :: renderer(string arg){
	string result = "";
	if ( arg == "WEB"){ result = webRenderer :: rendererElt(this); }
	return result;
}

namespace c2D{
	Point2D :: Point2D(){
	
	}
	Point2D :: Point2D(int arg1, int arg2){
		x = arg1;
		y = arg2;
	}
	
	
	Line :: Line(){
	
	}
	
	Line :: Line(Point2D* arg1, Point2D* arg2){
		a = arg1;
		b = arg2;
	}
	
	string Line :: renderer(string arg="WEB"){
		string result = "";
		if ( arg == "WEB"){ result = webRenderer :: rendererLine(this); }
		return result;
	}

	
	Rectangle :: Rectangle(){
	
	}
	
	Rectangle :: Rectangle(Line* arg1, Line* arg2){
		width = arg1;
		height = arg2;
	}

	string Rectangle :: renderer(string arg){
		string result = "";
		if ( arg == "WEB"){ result = webRenderer :: rendererRectangle(this); }
		return result;
	}


	Circle :: Circle(){
	
	}
	
	Circle :: Circle(Point2D* arg1, float arg2){
		center = arg1;
		radius - arg2;
	}

}

