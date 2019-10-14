#ifndef _IMAGE_PROVIDER_
#define _IMAGE_PROVIDER_

#include <OpenGL/gltypes.h>

class RessourceImage{
public:
	RessourceImage();
	~RessourceImage();
	bool loadFromFile(const char* filename);
	bool loadFromMemory(const void* data, int size);
	bool genTexture();
	void clear();
	bool isValid() const;

	int width() const;
	int height() const;
	unsigned char* pixelData() const;
	GLuint textureId();
	
private:
	int            m_width;
	int            m_height;
	unsigned char* m_pixelData;
	GLuint         m_textureId;
};

#endif // end of _IMAGE_PROVIDER_