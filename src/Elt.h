#ifndef ELT_H
#define ELT_H

#include <cmath>
#include <string>
#include <vector>

using namespace std;

struct DataValue{
	enum nature { NUMBER, TEXT };
	string value;
	string unit="px";
};    

struct DataAttribute {
	string field;
	string value;
};

class Elt{
	protected:
		string name;
		bool visible;
		vector<DataAttribute*> attributes;
		Elt* parent=nullptr;
	public:
		Elt();
		string getName(){return name;};
		vector<DataAttribute*> getAttributes(){return attributes;}
		Elt* getParent(){return parent;}
		
		void setName(string arg){name=arg;};
		void setAttributes(DataAttribute*);
		void setAttributes(DataAttribute*, DataAttribute* ...);		
		void setAttributes(vector<DataAttribute*>);
		
		virtual string render(string);
};

class EltGroup : public Elt{
	protected:
		vector<Elt*> elts;
};

class ArrayEltGroup : public EltGroup{
	protected:
		string elts_type;
};


// Informations Elements
class EltInfo : public Elt{
	protected:
		string value;
	public:
		EltInfo();
		EltInfo(string);
		~EltInfo();
		
		string getValue(){ return value; }
		virtual string render(string);

};

class TextInfo : public EltInfo {
	public:
		TextInfo();
		TextInfo(string);
		~TextInfo();

		virtual string render(string);

};

class AudioInfo : public EltInfo {

};

class ImageInfo : public EltInfo{

};

class VideoInfo : public EltInfo{

};

class MediaInfo : public EltInfo{
	vector<EltInfo*> medias;
	string order_play;
};

namespace c2D{
	class Point2D :public Elt{
		protected:
			float x=0,y=0;
			string color;
		public:
			Point2D();
			Point2D(int,int);
			float getX(){ return x; }
			float getY(){ return y; }
	};
	
	class Shape : public Elt{
		protected:
			vector<EltInfo*> infos;	
		public:
			vector<EltInfo*> getInfos(){ return infos; }
			void addInfos(EltInfo*);
			void addInfos(EltInfo*, EltInfo* ...);
			void addInfos(vector<EltInfo*>);
	};
	
	class Line : public Shape {
		protected:
			Point2D *a, *b;
		public:
			Line();
			Line(Point2D*,Point2D*);
			virtual string render(string);
			float value(){ return sqrt(pow( b->getX() - a->getX(), 2) + pow( b->getY() - a->getY() , 2)); }
			bool isXaxis(){ return b->getX() == a->getX() && b->getY() != a->getY() ; }
			bool isYaxis(){ return b->getX() != a->getX() && b->getY() == a->getY() ; }
	};
	
	class Rectangle : public Shape {
		protected:
			Line* width;
			Line* height; 
		public:
			Rectangle();
			Rectangle(Line*,Line*);
			Line* getWidth(){ return width; }
			Line* getHeight(){ return height; }
			virtual string render(string);
	};
	
	class Circle : public Shape{
		protected:
			Point2D *center;
			float radius;
		public:
			Circle();
			Circle(Point2D*,float);
	};
	
	
	class Triangle : public Shape{
	
	};
	
	class Polygon : public Shape {
	
	};
	
	class ShapeGroup : public Elt{
		protected:
			vector<Shape*> shapes;
	};
	
	class Component : public Elt{
		protected:
			vector<ShapeGroup*> groups;	
	};
	
	// classes for special purposes
	class Table : public Rectangle{
	
	};
	
	class Form : public Rectangle{
	
	};
}


namespace c3D{
	class Point3D : public Elt{
		protected:
			float x,y,z;
			string color;
	};
}

#endif
