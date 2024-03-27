#include <iostream>
#include <fstream>
#include <ctime> 
#include <cstdlib>
#include <sstream>


using namespace std;

int main(){
    
    ifstream image;

    ofstream newimage; 
    image.open("landscape.ppm");
    newimage.open("image.ppm");

    string type = "", width = "", height = "", RGB = "";
        image >> type;
        image >> width;
        image >> height;
        image >> RGB;

        //cout<< type << width << RGB<< endl;
    newimage << type << endl;
    newimage << 250 << " " << 250 << endl;
    newimage << RGB << endl;
    string red = "", green = "", blue = "";
    int r = 0, g = 0, b = 0;
    int totalr = 0, totalg =0, totalb = 0;
    int count = 0;
        while(!image.eof()){
            image >> red;
            image >> green;
            image >> blue;

            stringstream redstream(red);
            stringstream greenstream(green);
            stringstream bluestream(blue);
            redstream >> r;
            greenstream >> g;
            bluestream >> b;
            totalr += r;
            totalg += g;
            totalb += b;
            count++;
        }
        int averager= totalr/count;
        int averageg= totalg/count;
        int averageb = totalb/count;
    for(int y = 0; y < 250; y++){
        for(int x = 0; x< 250; x++){
                newimage << averager << " " << averageg << " " << averageb << endl;
        }
    }

        image.close();
        newimage.close();
    return 0;
}