#include "Renderer.h"
#include <string>
#include <vector>

namespace webRenderer
{
	string rendererElt(Elt* component){
		string result = "";
		return result;
	}
	
	string rendererShape(Shape* component){
		string instructions="";	
		string name = component->getName();
		instructions += name+" = document.createElement('"+"div"+"')" +";";
		instructions += name+".setAttribute('id','"+name+"')" +";";
		for (DataAttribute* da : component->getAttributes() ) 
		{
			if (da->field == "data-class"){
				instructions += name+".setAttribute('class','"+da->value+"')" ;
			}
			else if(da->field == "data-name"){
				instructions += name+".setAttribute('name','"+da->value+"')" ;
			}
			else if(da->field == "data-id"){
				instructions += name+".setAttribute('id','"+da->value+"')" ;
			}
			else if(da->field == "data-box-shadow"){
				instructions += name+".style.border = "+da->value+";"; 
			}
			else if(da->field == "data-margin"){
				instructions += name+".style.margin = "+da->value+";"; 
			}
			else if(da->field == "data-box-padding"){
				instructions += name+".style.padding = "+da->value+";"; 
			}
			else{
				instructions += name+".setAttribute('"+da->field+"','"+da->value+"')";
			}
		}
		for (EltInfo* info : component->getInfos())
		{
			instructions += info->renderer("WEB");
		}
		if ( component->getParent() == nullptr){
			instructions += "document.appendChild("+name+") ;";
		}
		else{
			instructions += component->getParent()->getName()+".appendChild("+name+") ;";
		}	
		return instructions;
	}

	string rendererLine(Line* component){
		string instructions = rendererShape(component);
		
		if ( component->isXaxis() ) { 
			instructions += component->getName()+".style.border = 1px solid #333 ";
			instructions += component->getName()+".style.width = "+to_string(component->value())+"px;";
			instructions += component->getName()+".style.height = 0px;"; 
		}
		else if ( component->isYaxis() ) { 
			instructions += component->getName()+".style.border = 1px solid #333 ";
			instructions += component->getName()+".style.width = 1px;"; 
			instructions += component->getName()+".style.height = "+to_string(component->value())+"px;";
		}	
		return instructions;
		
	}
		
	string rendererRectangle(Rectangle* component){
		string instructions = rendererShape(component);
		if ( component->getWidth() != nullptr && component->getWidth()->value() != 0) { instructions += component->getName()+".style.width = "+to_string(component->getWidth()->value()) +";"; }
		if ( component->getHeight() != nullptr && component->getHeight()->value() != 0 ) { instructions += component->getName()+".style.height = "+to_string(component->getHeight()->value())+";"; }
		return instructions;	
	}

}