#include "Rect.hpp"

bool Rect::IsInside(float x,float y){

	return((x <= this.x + w)&&(x >= this.x)&&(y <= this.x + w)&&(y <= this.y));

}