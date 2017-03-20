#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <Imagen.hpp>


int main(int argc, char const *argv[])
{
	DIR *dir=NULL;
    DIR *subdir=NULL;
    struct dirent *Directory=NULL;
    struct dirent *Subdirectory=NULL;
    string Path,Filename,Full_Path,Directory_Name;
    int Counter=1;
    ofstream Output;

    if (argc!=2){
        cout<< "insuficientes argumentos" <<endl;
	      return -1;
    }

    Path=argv[1];
    dir = opendir(Path.c_str());

    if(dir!=NULL)
    {
    	Imagen image;
        Output.open("Descriptores.txt");

    	while((Directory=readdir(dir))!=NULL )
    	{
    		Directory_Name=Directory->d_name;
            //cout<<Directory_Name<<endl;

    		if(Directory_Name!="." && Directory_Name!=".."&& Directory_Name!=".directory")
    		{
    			Full_Path=Path+"/"+Directory_Name;
                subdir=opendir(Full_Path.c_str());
                cout<<Full_Path<<endl;
    			
    			while((Subdirectory=readdir(subdir))!=NULL)
    			{
    				Filename=Subdirectory->d_name;
                    cout<<Filename<<endl;

    				if(Filename!="." && Filename!=".."&& Filename!=".directory" && Filename!="Thumbs.db")
                	{
                        image.SetImage(Full_Path+"/"+Filename);
                		image.CalculateDescriptors();
                        image.PrintDescriptors(Output);
                		cout<<Counter<<endl;
                		Counter++;
                	}
    			}
    		}
    	}
    }

	Output.close();
	return 0;
}