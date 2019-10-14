#ifndef _COLOR_
#define _COLOR_

typedef unsigned char uchar;

class Color {
public:
	Color(uchar R,uchar G,uchar B,uchar A= 255);
	Color(const Color& c);
	Color operator=(const Color& C);
	bool  operator==(const Color& C);
	bool  operator!=(const Color& C);
	
	uchar r,g,b,a;
	
	static const Color White;
	static const Color Black;
	static const Color Red;
	static const Color Green;
	static const Color Blue;
	static const Color Yellow;
	static const Color Magenta;
	static const Color Cyan;
	static const Color Transparent;
};

#endif //endof _COLOR_