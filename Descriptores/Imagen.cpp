#include "Imagen.hpp"

Imagen::Imagen()
{
	Descriptors=Descriptores();
	count=0;
}

void Imagen::CalculateDescriptors()
{
	
	Descriptors.ComputeImage(Image);


}
void Imagen::PrintDescriptors(ofstream &Output)
{
	
	Mat aux=Descriptors.getDescriptors();
	cout<<aux.size()<<endl;
	for (int i=0;i<aux.rows;i++){
      for (int j = 0;  j< aux.cols; j++) {
        Output<<aux.at<float>(i,j)<<" ";
      }
     Output<<endl;
    }
    count=count+aux.rows;

    cout<<count<<endl;
}

void Imagen::SetImage(string File_image)
{
	Image=imread(File_image,CV_LOAD_IMAGE_GRAYSCALE);
}

Mat Imagen::GetImage()
{
	return Image;	
}



