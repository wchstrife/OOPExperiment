#include <iostream>
#include <stdlib.h>

using namespace std;


void main()
{
	for(int E = 0 ; E <= 9; E++)
		for(int G = 0 ; G <= 9; G++)
			if(E != G){
				for(int A = 0 ; A <= 9; A++)
					if(E != A && G!=A){
						for(int L = 0 ; L <= 9; L++){
							if( (E*1000 + G*100 + A*10 + L) * L == L*1000 + A*100 + G*10 + E){
								cout <<" E: " << E  << " G: " << G << " A: " << A << " L: " << L << endl;
								break;
							}
							}
					}
								
			}
			
			system("pause");
}

