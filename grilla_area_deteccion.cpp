#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
const int range = 7;
const double lado = 100;

void read_function(char* filename, vector< vector<double> >& v)
{
    ifstream input;
    input.open(filename);
    if(input.is_open())
    {
        if (input){
			string line; 
			int i = 0;
			while (getline(input, line)){
				if (line[0] != '#'){
					v.push_back(vector<double>());
					stringstream split(line);
					double value;
					while (split >> value){
					v.back().push_back(value);
					}			
				}
			}
		}
	}
	input.close();
}


string IntToStr(int n) 
{
    stringstream result;
    result << n;
    return result.str();
}

int main(int argc, char const *argv[]){

if (argc < 2)
{	
	cerr << "no input file's name\n"<< endl;
}	

string program_name = argv[0];
ifstream input;
input.open(argv[1]);

ofstream myFiles[16][16];
	
for(int m = -7; m < 8; ++m)
{
	for (int n = -7; n < 8; ++n)
	{
		stringstream out_filename;
		out_filename << "cuadrante" << "_" << "zona_"<< m << "_" << "zona_"<< n << ".dat";
   		myFiles[m + range][n + range].open(out_filename.str().c_str()); 
		
		myFiles[m + range][n + range].setf(std::ios::scientific);
  		myFiles[m + range][n + range].setf(std::ios::showpos);
		myFiles[m + range][n + range].precision(7);
		}
} 

vector< vector<double> > array;
read_function((char*)argv[1], array);

for (int i = 0; i < array.size(); ++i)
{
	for (int k = -7; k < 8; ++k)
	{
		for (int j = -7; j < 8; ++j)
		{
			if (j*lado - 100 < array[i][4]/100 && array[i][4]/100 < j*lado && k*lado - 100 < array[i][5]/100 && array[i][5]/100 < k*lado)  
			{
				myFiles[k + range][j + range] << array[i][4] << "  " << array[i][5] << endl;
			}
		}    
	}    
}    

ifstream zona;


ofstream salida;
salida.open("suma.dat");

double x = 630;
double y = 250;

int b = int(x/lado); 
int c = int(y/lado);

vector<vector<double> > zona1;
read_function((char*) "cuadrante" << "_" << "zona_"<< b<< "_" << "zona_"<< c << ".dat", zona1);
	for (int q = 0; q < zona1.size(); ++q)
		salida << zona1[q][0] + zona1[q][1] << endl;

return 0;
}