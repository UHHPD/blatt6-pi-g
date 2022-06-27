#include "Vektor.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include <iostream>
#include <memory>

double traegheit ( Koerper*k ,Vektor a, Vektor u) {
std :: cout << "berechne␣fuer␣" << k -> name() << '\n';
  double J = 0;
  const int N = 10000;     // Anzahl Integrationspunkte
  const double M = 1;      // Masse des Zylindermantels// Massentraegheitsmoment
  double m = M / N; // Masse eines Massenpunktes
  for (int i = 0; i < N; ++i) {
    Vektor x = k->punkt();
    // Abstand Punkt x und Gerade a + t*u
    // Vektor n = ...;//Normalenvektor x-a kreuz u
    double r = ((x-a).kreuz(u)).betrag()/u.betrag(); //|n|/|u|
    //std::cout << x << " :" << r << std::endl;
    // addiere Beitrag des Massenpunktes zum Traegheitsmoment
    J += m * r * r;
  }
  std::cout << "Massentraegheitsmoment fuer einen" << k->name() 
            << " mit a = " << a << " und u = " << u << ": " << J << std::endl;
  return J;
}

int main() {

  const double ZM_R = 2.0; // Radius der Zylindermantels
  const double ZM_L = 1.0; // Laenge des Zylindermantels

  Vektor a; // Punkt auf der Rotationsachse
  std::cout << "Aufpunkt:";
  std::cin >> a;
  Vektor u; // Richtung der Rotationsachse
  std::cout << "Richtung:";
  std::cin >> u;
  std :: unique_ptr < Zylindermantel > k ( new Zylindermantel ( ZM_R , ZM_L ));
  std :: unique_ptr < Vollzylinder > k2 ( new Vollzylinder ( ZM_R , ZM_L ));
  double J = traegheit (k.get() ,a , u );
  double J2 = traegheit (k2.get() ,a , u );


            
  return 0;
}
