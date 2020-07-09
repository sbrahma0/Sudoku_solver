#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int a [9][9];
bool in_row(int i, int j, int x) {
	for (int g=0;g<9;g++) {
		if (a[i][g]==x)
			return 0;
		}
	return 1;
	
}

bool in_col(int i, int j, int x) {

	for (int g=0;g<9;g++) {
		if (a[g][j]==x)
			return 0;
		}
	return 1;

}

bool in_square(int i, int j, int x) {

	int r = ceil((i+1)/3.);
	int c = ceil((j+1)/3.);
	for (int i=(r-1)*3; i<(r-1)*3+3;i++) {
		for (int j=(c-1)*3; j<(c-1)*3+3;j++) {
			if (a[i][j] == x)
				return 0;
			}
		}
	return 1;

}




int main()
{
	
	int un=0, temp;
	bool b=1;
	const char* filename = "sudoku";
	ifstream in(filename);
	if (!in.is_open())
		cout<<"Problem\n";
	
	for (int i=0;i<9;i++) {
		for (int j=0; j<9; j++) {
			in>>a[i][j];
			if (a[i][j]==0)
				un++;
			}
		}
	in.close();
	// main loop
	while (un && b) {
		b = 0; // that mean noting can be written so the sudoku cannot be solved
		for (int i=0;i<9;i++) {
			for (int j=0; j<9; j++) {
				if (a[i][j]!=0) // if a number is already there
					continue;
				
				temp = 0;
				for (int num = 0; num<10;num++) {
					if (in_row(i,j,num) && in_col(i,j,num) && in_square(i,j,num)) {
						if (temp==0)
							temp = num;
						else {
							temp = 0; // this is for the case when the number of possibility if moere than 1
							break;
							}
						}
					}
				
				if (temp) {
					a[i][j] = temp;
					b=1;
					un--;
					}
				}
			}
		}
		
		if (!b)
			cout<<"Cannot solve"<<endl;
		else
			cout<<"Solved"<<endl;
		
		for (int i=0;i<9;i++) {
			//cout<<"\n\n";
			for (int j=0; j<9; j++) {
				cout<<a[i][j]<<" ";
				}
			cout<<endl;
			}
		
	cout<<un<<endl;
	
	
	
	return 0;
	
	
	
	
	}


