#ifndef IMAGEN_H
#define IMAGEN_H

#include <Descriptores.hpp>

class Imagen
{
public:
	Imagen();
	void SetImage(string File_image);
	void CalculateDescriptors();
	Mat GetImage();
	void PrintDescriptors(ofstream &Output);

private:
	Mat Image;
	Descriptores Descriptors;
	Mat data;
	int count;
	
};

#endif