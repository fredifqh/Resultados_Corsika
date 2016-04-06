#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
const int range = 3;
const double l = 100; // Tamaño del lado de la grilla
const double L = 500; // Tamaño del lado total del area 

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

int main(int argc, char const *argv[]){

if (argc < 2)
{	
	cerr << "no input file's name\n"<< endl;
}	
int zona_x, zona_y;
double x, y;

string program_name = argv[0];
ifstream input;
input.open(argv[1]);
ofstream zonasFile;
/*
ofstream myFiles[8][8];
	
for(int m = -3; m <= 3; ++m)
{
	for (int n = -3; n < 4; ++n)
	{
		stringstream out_filename;
		out_filename << "zona_"<< m << "_" << "zona_"<< n << ".dat";
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
	for (int k = -3; k <= 3; ++k)
	{
		for (int j = -3; j <= 3; ++j)
		{
			if (j*lado - 100 < array[i][4]/100 && array[i][4]/100 <= j*lado && k*lado - 100 < array[i][5]/100 && array[i][5]/100 < k*lado)  
			{
				myFiles[k + range][j + range] << array[i][4] << "  " << array[i][5] << endl;
			}
		}    
	}    
}    
*/
vector< vector<double> > array;
read_function((char*)argv[1], array);
for (int i = 0; i < array.size(); ++i)
{
	x = array[i][4]*0.01;
	y = array[i][4]*0.01;
	if ((x < L) && (x > -L) && (y < L) && (y > -L))
	{
		if (x >= 0)
			zona_x = int(x/l) + 1;
		if (y >= 0)
			zona_y = int(y/l) + 1;
		if (x < 0)
			zona_x = -(int(-x/l) + 1);
		if (y < 0)
			zona_y = -(int(-y/l) + 1);
		stringstream out_filename;
		out_filename << "zona_"<< zona_x << "_" << "zona_"<< zona_y << ".dat";
   		zonasFile.open(out_filename.str().c_str(), fstream::app);
		zonasFile << x << "  " << y << endl;
		zonasFile.close();
	}
}
/*
srand(std::time(0));
int x = std::rand() % 300 + 1;
cout << x << endl;

int y = std::rand() % 300 + 1;
cout << y << endl;

int limit_x = (int(x/100) + 1);
int limit_y = (int(y/100) + 1);

if (x + 3 < limit_x*100 && y + 3 < limit_y*100)
{
	stringstream file;	
	file << "zona_" + std::to_string(limit_x) + "_zona_" + std::to_string(limit_y) +  ".dat";
	ifstream zona(file.str().c_str());

	cout << file.str().c_str() << endl;

	ofstream salida;
	salida.open("suma.dat");

	vector<vector<double> > zona1;
	read_function((char*) file.str().c_str(), zona1);
		for (int q = 0; q < zona1.size(); ++q)
			salida << zona1[q][0] + zona1[q][1] << endl;
	zona.close();
	salida.close();
}
else if (x + 3 > limit_x*100 && y + 3 < limit_y*100)
{
	stringstream file;	
	file << "zona_" + std::to_string(limit_x + 1) + "_zona_" + std::to_string(limit_y) +  ".dat";
	ifstream zona(file.str().c_str());

	cout << file.str().c_str() << endl;

	ofstream salida;
	salida.open("suma.dat");

	vector<vector<double> > zona1;
	read_function((char*) file.str().c_str(), zona1);
		for (int q = 0; q < zona1.size(); ++q)
			salida << zona1[q][0] + zona1[q][1] << endl;
	zona.close();
	salida.close();
}
else if (x + 3 < limit_x*100 && y + 3 > limit_y*100)
{
	stringstream file;	
	file << "zona_" + std::to_string(limit_x) + "_zona_" + std::to_string(limit_y + 1) +  ".dat";
	ifstream zona(file.str().c_str());

	cout << file.str().c_str() << endl;

	ofstream salida;
	salida.open("suma.dat");

	vector<vector<double> > zona1;
	read_function((char*) file.str().c_str(), zona1);
		for (int q = 0; q < zona1.size(); ++q)
			salida << zona1[q][0] + zona1[q][1] << endl;
	zona.close();
	salida.close();
}
else if (x + 3 > limit_x*100 && y + 3 > limit_y*100)
{
	stringstream file;	
	file << "zona_" + std::to_string(limit_x + 1) + "_zona_" + std::to_string(limit_y + 1) +  ".dat";
	ifstream zona(file.str().c_str());

	cout << file.str().c_str() << endl;

	ofstream salida;
	salida.open("suma.dat");

	vector<vector<double> > zona1;
	read_function((char*) file.str().c_str(), zona1);
		for (int q = 0; q < zona1.size(); ++q)
			salida << zona1[q][0] + zona1[q][1] << endl;
	zona.close();
	salida.close();
}
*/
return 0;
}