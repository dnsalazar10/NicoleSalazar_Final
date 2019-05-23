#include <iostream>
#include <fstream>
#include <math.h>
#define PI 3.1416

using namespace std;
//Constantes del problema
double x0 = 1; //posicion inicial de x
double y0 = 1; //posicion inicial de y
double m = 7294.29; //masa
double q = 2; //Carga de la particula
double dt = 0.1; //masa
double tfin=10; //Tiempo final

int inicio=0;
int fin=99;

int int main() {
  //Iniciacilizacion de arrays//
	//Para caso 1: coordenadas en x
	double x_past[N];
	double x_pre[N];
	double x_fut[N];
	//Para caso 2: coordenadas en y
	double y_past2[N];
	double y_pre2[N];
	double y_fut2[N];

  //Abre documento en el que se almacenarán los datos
  ofstream outfile ("qdatos.dat");

  //Pasado
 //Campo para t<3
	for (int i = 0; i < 3; i++)
	{
		x_past[i]=x0*(double(i)/double(N-1));
		y_past2[i]=y0*(i/i_pluck);

	}
  //Campo para 3<t<6
	for (int i = 3 i < 7; i++)
	{
		x_past[i]= x0*(1-double(i)/double(N-1));
		y_past2[i]=y0*((x0/i_pluck)*(i-i_pluck));

	}
//Campo para 7<t<10
	//Presente
	for (int i = 7; i < tfin; i++)
	{

		if(i==inicio)
		{
			x_pre[i]=0;
			y_pre2[i]=0;

		}

		else if (i==fin)
		{
			x_pre[i]=0;
			y_pre2[i]=x_pre2[i-1];

		}

		//Puntos de 1 a 99, ecuacion diferencial
		else
		{
			x_pre[i]= x_past[i] + (c/c_p)/2.0 * ( x_past[i+1] + x_past[i-1] - 2.0*x_past[i] );
			y_pre2[i]= y_past2[i] + (c/c_p)/2.0 * ( y_past2[i+1] + y_past2[i-1] - 2.0*y_past2[i] );

		}
	}

//Futuro
for (int i=0;i<1000;i++)
{
	for (int i=0;i<N;i++)
	{
		if(i==inicio)
		{
			x_fut[i]=0;
			y_fut2[i]=0;


		}
		else if(i==fin)
		{
			x_fut[i]=0;
			y_fut2[i]=A_fut2[fin-1];

		}

		else
		{
			x_fut[i]= x_pre[i] + (c/c_p)/2.0 * ( x_pre[i+1] + x_pre[i-1] - 2.0*x_pre[i] );
		y_fut2[i]= y_pre2[i] + (c/c_p)/2.0 * ( y_pre2[i+1] + y_pre2[i-1] - 2.0*y_pre2[i] );

		}
	}

	//Actualiza los tiempos
	for (int i = 0; i <= N; i++)
	{
		x_past[i]=x_pre[i];
		x_pre[i]=x_fut[i];

		y_past2[i]=y_pre2[i];
		y_pre2[i]=y_fut2[i];


	}
}











  for (int i = 0; i < N; i++)
  {
  	outfile << i*dx << " " << x_pre[i] << " " << y_pre[i] <<endl;
  }
  cout << endl << "Condiciones almacenadas en qdatos.dat" << endl;
  outfile.close ();

  return 0;
}
